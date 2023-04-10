#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE (MAX_MSG_SIZE + 10)

int main(int argc, char **argv) {
    mqd_t server_queue, client_queue;
    char buffer[MSG_BUFFER_SIZE];
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    server_queue = mq_open("/server", O_CREAT | O_RDONLY, 0644, &attr);
    if (server_queue == -1) {
        perror("mq_open");
        exit(1);
    }

    while (1) {
        if (mq_receive(server_queue, buffer, MSG_BUFFER_SIZE, NULL) == -1) {
            perror("mq_receive");
            exit(1);
        }
        printf("Received message: %s\n", buffer);

        // Send response to client
        char client_queue_name;
        sscanf(buffer, "%s", client_queue_name);
        client_queue = mq_open(client_queue_name, O_WRONLY);
        if (client_queue == -1) {
            perror("mq_open");
            exit(1);
        }
        sprintf(buffer, "Hello, client!");
        if (mq_send(client_queue, buffer, strlen(buffer) + 1, 0) == -1) {
            perror("mq_send");
            exit(1);
        }
        mq_close(client_queue);
    }

    mq_close(server_queue);
    mq_unlink("/server");

    return 0;
}