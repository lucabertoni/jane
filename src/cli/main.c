#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <libssh/libssh.h>

#include "servers_details.h"
#include "jane_ssh.h"
#include "jane.h"

int main(){
    struct Server **servers, **head;
    ssh_session jane_ssh_session;
    struct jane_ssh_session_connection_options options = {"127.0.0.1", 22, SSH_LOG_PROTOCOL};
    
    servers = servers_details_init(3);
    
    head = servers;
    *servers = (struct Server*) malloc(sizeof(struct Server*));
    servers++;
    *servers = (struct Server*) malloc(sizeof (struct Server*));

    jane_ssh_session = jane_ssh_session_init(&options);
    jane_get_remote_server_details(jane_ssh_session, *head);
    
    servers_details_free(head, 2);
    
    return 0;
}