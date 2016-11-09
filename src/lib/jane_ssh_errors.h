#include <stdint.h>

#ifndef JANE_SSH_ERRORS
#define JANE_SSH_ERRORS

enum {
    JANE_SSH_ERROR_NO_ERROR = 0,
    JANE_SSH_ERROR_INIT_ERROR,
    JANE_SSH_ERROR_CONNECTION_ERROR,
    JANE_SSH_ERROR_DISCONNECT_FAILED_NO_CONNECTION_FOUND
} JANE_SSH_ERRORS_LIST;

uint16_t jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;

uint8_t jane_ssh_connected = 0;

#endif