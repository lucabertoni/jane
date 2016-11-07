#include "jane_ssh.h"

ssh_session jane_ssh_session_init(const struct jane_ssh_session_connection_options *options){
    ssh_session session;
    
    session = ssh_new();
    if(session == NULL){
        jane_ssh_error = JANE_SSH_ERROR_INIT_ERROR;
        return NULL;
    }
    
    ssh_options_set(session, SSH_OPTIONS_HOST, options->ip_address);
    ssh_options_set(session, SSH_OPTIONS_LOG_VERBOSITY, &(options->verbosity));
    ssh_options_set(session, SSH_OPTIONS_PORT, &(options->port));
    
    jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;
    
    return session;
}

void jane_ssh_session_free(ssh_session session){
    ssh_free(session);
}

int jane_ssh_session_connect(ssh_session session){
    if(ssh_connect(session) != SSH_OK){
        jane_ssh_error = JANE_SSH_ERROR_CONNECTION_ERROR;
    }else{
        jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;
        jane_ssh_connected = 1;
    }
    
    return jane_ssh_error;

}

void jane_ssh_session_disconnect(ssh_session session){
    if(jane_ssh_connected){
        ssh_disconnect(session);
        jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;
    }else{
        jane_ssh_error = JANE_SSH_ERROR_DISCONNECT_FAILED_NO_CONNECTION_FOUND;
    }    
}