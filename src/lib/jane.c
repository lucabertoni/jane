#include <stdlib.h>

#include "jane.h"
#include "errors.h"

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
    if(jane_get_server_hardware_harddisk_details(const ssh_session jane_ssh_session, struct Server *server_details) == JANE_ERROR_GET_REMOTE_FILE_ERROR)
        return JANE_ERROR_GET_REMOTE_FILE_ERROR;
    
    return 0;
}