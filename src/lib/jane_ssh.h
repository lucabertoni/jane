#include <libssh/libssh.h>
#include <stdint.h>

#include "jane_ssh_errors.h"

#ifndef JANE_SSH_H
#define JANE_SSH_H

//extern uint16_t jane_ssh_error;
//extern uint8_t jane_ssh_connected;

struct jane_ssh_session_connection_options{
    char *ip_address;
    uint16_t port;
    int verbosity; // See LIBSSH SSH_LOG_* consts
};

ssh_session jane_ssh_session_init(const struct jane_ssh_session_connection_options *options);
void jane_ssh_session_free(ssh_session session);
int jane_ssh_session_connect(ssh_session session);
void jane_ssh_session_disconnect(ssh_session session);

#endif