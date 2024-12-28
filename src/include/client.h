#ifndef __CLIENT_H

#include "utils.h"

SOCKET client_connect(const int port);

void client_send(SOCKET client_socket, const char* data);

#endif