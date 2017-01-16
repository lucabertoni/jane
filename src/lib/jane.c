#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "jane.h"
#include "errors.h"

uint16_t jane_error = JANE_ERROR_NO_ERROR;
const char *jane_log_levels[] = {"INFO", "WARNING", "ERROR", "STDOUT", "DEBUG"}; //INFO: 1, WARNING: 2, ...

int jane_get_remote_server_details(const ssh_session jane_ssh_session, struct Server *server_details){
    int error;
    
    error = jane_get_server_hardware_details(jane_ssh_session, server_details);
    
    return error;
}

int jane_get_server_hardware_harddisk_details(const ssh_session jane_ssh_session, struct Server *server_details){
    
    return 0;
}

int jane_get_server_hardware_details(const ssh_session jane_ssh_session, struct Server *server_details){
    if((server_details->server_hardware == NULL) || (server_details_serverhw_init(server_details) == JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR))
        return JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR;

    // jane_ssh_get_remote_file("/proc/");
    //if(jane_get_server_hardware_harddisk_details(const ssh_session jane_ssh_session, struct Server *server_details) == JANE_ERROR_GET_REMOTE_FILE_ERROR)
        //return JANE_ERROR_GET_REMOTE_FILE_ERROR;
    
    return 0;
}

/*
    log_level:  1 -> Info
                2 -> Warning
                3 -> Error
                4 -> Debug
*/
void jane_log(unsigned short int log_level, char* message){
    FILE *log_file;
    char log_message[1024];

    const char log_file_path_name[] = JANE_LOG_PATH "jane.log";

    if(log_level > JANE_MAX_LOG_LEVEL){
        if(JANE_LOG_DEBUG)
            fprintf(stderr, "jane_log -> Unknown log level %d\n", log_level);
        return;
    }

    if(((_debug_log == log_level) && JANE_LOG_DEBUG) || (_debug_log != log_level)){
        if(_stdout_log == log_level){
            fprintf(stdout, "%s -> %s", _JANE_NAME, message);
        }else{
            if((log_file = fopen(log_file_path_name, "a")) != NULL){
                snprintf(log_message, 1024, "%-7s -> %s\n", jane_log_levels[--log_level], message);
                fputs(log_message, log_file);

                fclose(log_file);
            }
        }
    }
}