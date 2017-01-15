#include <libssh/sftp.h>
#include <stdio.h>
#include <errno.h>

#include "jane_ssh.h"

uint16_t jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;

uint8_t jane_ssh_connected = 0;

ssh_session jane_ssh_session_init(const struct jane_ssh_session_connection_options *options){
    ssh_session session;
    
    session = ssh_new();
    if(session == NULL){
        fprintf(stderr, "JANE_SSH -> Error occurred creating a new ssh session\n");
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

int jane_ssh_verify_knownhost(ssh_session session){

	return 0;
}

int jane_ssh_session_connect(ssh_session session){
    if(ssh_connect(session) != SSH_OK){
        fprintf(stderr, "JANE_SSH -> Can't establish a ssh connection. Details: %s\n", ssh_get_error(session));
        jane_ssh_error = JANE_SSH_ERROR_CONNECTION_ERROR;
    }else{
        jane_ssh_error = JANE_SSH_ERROR_NO_ERROR;
        jane_ssh_connected = 1;
    }
    
    // TODO: continuare
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

// Ridefinire params!!!
/*
char* jane_ssh_get_remote_file(ssh_session, const unsigned char *file_name)
int jane_ssh_get_remote_file(ssh_session, const unsigned char *file_name, const unsigned char *file_name_dest);
*/
int jane_ssh_get_remote_file(ssh_session session, const unsigned char *file_name){
    sftp_session sftp;
    int rc;
    sftp = sftp_new(session);
    
    if (sftp == NULL)
    {
        fprintf(stderr, "JANE_SSH -> Error creating new SFTP session: %s. JANE error code number: %d\n", ssh_get_error(session), JANE_SSH_ERROR_SFTP_CREATE_ERROR);
        return JANE_SSH_ERROR_SFTP_CREATE_ERROR;
    }
    
    rc = sftp_init(sftp);
    if (rc != SSH_OK)
    {
        fprintf(stderr, "JANE_SSH -> Error initializing SFTP session. sftp error no.: %d.\n", sftp_get_error(sftp));
        sftp_free(sftp);
        return rc;
    }
    
    // TODO: continuare da qui

    sftp_free(sftp);

    return -1;
}