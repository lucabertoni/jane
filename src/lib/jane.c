#include <stdlib.h>

#include "jane.h"

int jane_get_remote_server_details(const ssh_session jane_ssh_session, struct Server *server_details){
    int error;
    
    error = jane_get_server_hardware_details(jane_ssh_session, server_details)
            ;
    
    return error;
}
int jane_get_server_hardware_details(const ssh_session jane_ssh_session, struct Server *server_details){
    if(server_details->server_hardware == NULL){
        if((server_details->server_hardware = server_details_serverhw_init()) == NULL) return JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR;
    }
    
    if(server_details->server_hardware->hard_disk_details == NULL){
        server_details->server_hardware->hard_disk_details = server_details_harddisk_init();
    }
    
    
}
