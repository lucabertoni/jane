#include <libssh/libssh.h>
#include <stdint.h>

#ifndef JANE_SSH_H
#define JANE_SSH_H

struct jane_ssh_session_connection_options{
    char *ip_address;
    uint16_t port;
    int verbosity; // See LIBSSH SSH_LOG_* consts
};


ssh_session jane_ssh_session_init();

#endif