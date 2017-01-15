#include <stdint.h>

#ifndef JANE_SSH_ERRORS
#define JANE_SSH_ERRORS

#define JANE_SSH_ERROR_NO_ERROR									0x01
#define	JANE_SSH_ERROR_INIT_ERROR								0x02
#define	JANE_SSH_ERROR_CONNECTION_ERROR							0x03
#define	JANE_SSH_ERROR_DISCONNECT_FAILED_NO_CONNECTION_FOUND	0x04
#define JANE_SSH_ERROR_SFTP_CREATE_ERROR						0x05
#define JANE_SSH_ERROR_UNKNOWN_HOST								0x06

extern uint16_t jane_ssh_error;

extern uint8_t jane_ssh_connected;

#endif