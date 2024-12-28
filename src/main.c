#include <stdio.h>

#include "include/server.h"
#include "include/client.h"
#include "include/utils.h"

int main(int argc, char* argv[]) {
    winsock_init();

    if (!strcmp(argv[1], "server")) {
        SOCKET server_socket = server_create();
        
        server_run(server_socket);

        closesocket(server_socket);
    }
    else if (!strcmp(argv[1], "client")) {
        const int port;
        sscanf(argv[2], "%d", &port);

        SOCKET client_socket = client_connect(port);
        client_send(client_socket, "hello from a client");

        closesocket(client_socket);
    }

    return 0;
}