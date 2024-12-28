#ifndef __UTILS_H

#pragma comment(lib, "ws2_32.lib")

#define WIN32_LEAN_AND_MEAN

#include <stdio.h>

#include <winsock2.h>
#include <ws2tcpip.h>

void winsock_init();
void winsock_cleanup();

SOCKET create_socket();

#endif