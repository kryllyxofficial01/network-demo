#ifndef __SERVER_H

#include <stdbool.h>

#include "utils.h"

SOCKET server_create();
void server_run(SOCKET server_socket);

#endif