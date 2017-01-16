#include <stdint.h>
#include <libssh/libssh.h>

#include "servers_details.h"

#ifndef JANE_H
#define JANE_H

#define _JANE_NAME		"jane"
#define _JANE_VERSION	"0.0.0"

/* JANE LOG */
#ifndef JANE_LOG_PATH
#define JANE_LOG_PATH	"/var/log/jane/"
#endif

extern const char *jane_log_levels[];

#define _info_log		1
#define _warning_log	2
#define _error_log		3
#define _stdout_log		4
#define _debug_log		5

#define JANE_MAX_LOG_LEVEL	5

#ifdef JANE_DEBUG
#define JANE_LOG_DEBUG	1	// Debug enabled
#else
#define JANE_LOG_DEBUG	0	// By default debug is disabled
#endif
/* -END- JANE LOG */

int jane_get_remote_server_details(const ssh_session jane_ssh_session, struct Server *server_details);
int jane_get_server_hardware_details(const ssh_session jane_ssh_session, struct Server *server_details);
int jane_get_server_hardware_harddisk_details(const ssh_session jane_ssh_session, struct Server *server_details);

void jane_log(unsigned short int log_level, char* message);
#endif