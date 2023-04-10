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

    server_queue = mq_open("/server", O_WRONLY);
    if (server_queue == -1) {
        perror("mq_open");
        exit(1);
    }

    // Create client queue
    char client_queue_name;
    sprintf(client_queue_name, "/client_%d", getpid());
    client_queue = mq_open(client_queue_name, O_CREAT | O_WRONLY, 0644, &attr);
    if (client_queue == -1) {
        perror("mq_open");
        exit(1);
    }

    // Send message to server
    sprintf(buffer, "%s %s", client_queue_name, "Hello, server!");
    if (mq_send(server_queue, buffer, strlen(buffer) + 1, 0) == -1) {
        perror("mq_send");
        exit(1);
    }

    // Receive response from server
    if (mq_receive(client_queue, buffer, MSG_BUFFER_SIZE, NULL) == -1) {
        perror("mq_receive");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    mq_close(client_queue);
    mq_unlink(client_queue_name);

    return 0;
}