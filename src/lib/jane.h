#include <stdint.h>
#include <libssh/libssh.h>

#include "servers_details.h"

#ifndef JANE_H
#define JANE_H

int jane_get_remote_server_details(const ssh_session jane_ssh_session, struct Server *server_details);
int jane_get_server_hardware_details(const ssh_session jane_ssh_session, struct Server *server_details);
int jane_get_server_hardware_harddisk_details(const ssh_session jane_ssh_session, struct Server *server_details);
#endif