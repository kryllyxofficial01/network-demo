#include "include/server.h"

SOCKET server_create() {
    struct sockaddr_in server;

    server.sin_family = AF_INET; // ipv4 address family
    server.sin_addr.S_un.S_addr = INADDR_ANY;

    printf("\nSetting up server socket ... ");

    SOCKET server_socket = create_socket();

    if (bind(server_socket, (struct sockaddr*) &server, sizeof(server)) == SOCKET_ERROR) {
        printf("\e[31mFailed\e[0m\n");

        winsock_cleanup();

        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 1) == SOCKET_ERROR) {
        printf("\e[31mFailed\e[0m\n");

        winsock_cleanup();

        exit(EXIT_FAILURE);
    }

    printf("\e[32mSuccess\e[0m\n");

    socklen_t server_len = sizeof(server);
    getsockname(server_socket, (struct sockaddr*) &server, &server_len);

    printf("\nServer hosted on port \e[33m%d\e[0m\n\n", ntohs(server.sin_port));

    return server_socket;
}

void server_run(SOCKET server_socket) {
    while (true) { // just run until the user stops the server (otherwise known as Ctrl-C)
        struct sockaddr_storage client;

        socklen_t client_len = sizeof(client);
        SOCKET client_socket = accept(server_socket, (struct sockaddr*) &client, &client_len);

        char buffer[1024];
        recv(client_socket, buffer, sizeof(buffer), 0);

        printf("\e[34mreceived data:\n\t---\e[0m \e[1;36m%s\e[0m \e[34m---\e[0m\n", buffer);

        closesocket(client_socket);
    }
}