#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <libssh/libssh.h>

#include "servers_details.h"
#include "jane_ssh.h"
#include "jane.h"
#include "errors.h"

extern uint16_t jane_error;

int main(int argc, char *argv[]){
    struct Server **servers;
    // ssh_session jane_ssh_session;
    // struct jane_ssh_session_connection_options options = {"127.0.0.1", 22, SSH_LOG_PROTOCOL};

    servers = server_details_load_from_file("servers.yaml");
    
    if(servers == NULL){
        fprintf(stderr, "%s -> Error occurred while allocating memory needed to contain servers details. Error no.: %d. More info at: %s\n", *argv, jane_error, JANE_ERROR_DOC);
        exit(jane_error);
    }

    //jane_ssh_session = jane_ssh_session_init(&options);
    //jane_get_remote_server_details(jane_ssh_session, *head);
    
    servers_details_free(servers, 3);
    
    return 0;
}