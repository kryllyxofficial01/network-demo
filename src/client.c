#include "include/client.h"

SOCKET client_connect(const int port) {
    SOCKET client_socket = create_socket();

    struct sockaddr_in client;

    client.sin_family = AF_INET;
    client.sin_port = htons((short) port);

    char address_str[NI_MAXHOST + NI_MAXSERV + 1];
    snprintf(address_str, sizeof(address_str), "127.0.0.1:%d", port);

    inet_pton(AF_INET, address_str, &client.sin_addr);

    printf("\nConnecting to server at '%s' ... ", address_str);

    if (connect(client_socket, (struct sockaddr*) &client, sizeof(client)) == SOCKET_ERROR) {
        printf("\e[31mFailed\e[0m\n");

        winsock_cleanup();

        exit(EXIT_FAILURE);
    }

    printf("\e[32mSuccess\e[0m\n\n");

    return client_socket;
}

void client_send(SOCKET client_socket, const char* data) {
    printf("Data to be sent: \e[36m%s\e[0m\n", data);
    printf("Sending data to server ... ");

    if (send(client_socket, data, strlen(data) + 1, 0) == SOCKET_ERROR) {
        printf("\e[31mFailed\e[0m\n");

        winsock_cleanup();

        exit(EXIT_FAILURE);
    }

    printf("\e[32mSuccess\e[0m\n");
}