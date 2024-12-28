#include "include/utils.h"

void winsock_init() {
    struct WSAData wsa_data;

    if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
        printf("Failed to initialize Winsock\n");

        exit(EXIT_FAILURE);
    }

    printf("\e[33mWinsock initialized\e[0m\n");
}

void winsock_cleanup() {
    // not gonna do any error checking cause this is more of a proof of concept
    WSACleanup();
}

SOCKET create_socket() {
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == INVALID_SOCKET) {
        printf("\e[31mFailed\e[0m\n");

        winsock_cleanup();

        exit(EXIT_FAILURE);
    }

    return sock;
}