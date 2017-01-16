#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <libssh/libssh.h>
#include <yaml.h>

#include "servers_details.h"
#include "jane_ssh.h"
#include "jane.h"
#include "errors.h"

extern uint16_t jane_error;

int main(int argc, char *argv[]){
    struct Server **servers;
    char debug[1024];
    // ssh_session jane_ssh_session;

    /* I get more info I can about libraries and stuff about that */
    sprintf(debug, "Using version %s of libyaml\n"
                    "jane v%s\n", yaml_get_version_string(), _JANE_VERSION);
    jane_log(_debug_log, debug);

    servers = server_details_load_from_file("servers.yaml");
    
    if(servers == NULL){
        sprintf(debug, "Error occurred while allocating memory needed to contain servers details. Error no.: %d. More info at: %s\n", jane_error, JANE_ERROR_DOC);
        jane_log(_stdout_log, debug);
        exit(jane_error);
    }

    // struct jane_ssh_session_connection_options options = {"127.0.0.1", 22, SSH_LOG_PROTOCOL};
    //jane_ssh_session = jane_ssh_session_init(&options);
    //jane_get_remote_server_details(jane_ssh_session, *head);
    
    servers_details_free(servers, 3);
    
    return 0;
}