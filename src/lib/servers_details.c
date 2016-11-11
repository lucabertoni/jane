#include <stdlib.h>

#include "servers_details.h"
#include "errors.h"

int server_details_serverhw_init(struct Server *server_details){
    server_details->server_hardware = (struct ServerHW*) malloc(sizeof(struct ServerHW*));
    
    server_details->server_hardware->hard_disk_details = (struct HardDisk*) malloc(sizeof(struct HardDisk*));
    
    server_details->server_hardware->memory_details = (struct Memory*) malloc(sizeof(struct Memory*));
    
    server_details->server_hardware->swap_details = (struct Swap*) malloc(sizeof(struct Swap*));
    
    server_details->server_hardware->cpu_details = (struct CPU*) malloc(sizeof(struct CPU*));

    return ((server_details->server_hardware == NULL) || (server_details->server_hardware->hard_disk_details == NULL) ||
            (server_details->server_hardware->memory_details == NULL) || (server_details->server_hardware->swap_details == NULL) ||
            (server_details->server_hardware->cpu_details == NULL)
    ) ? JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR : 0;
    
}

struct Server **servers_details_init(unsigned short int server_count){
    struct Server **servers;

    if((servers = (struct Server**) malloc(sizeof(struct Server**) * server_count)) == NULL)
        return NULL;

    return servers;
}

void server_details_serverhw_free(struct ServerHW* server_hardware){
/*
    free(server_hardware->hard_disk_details->partitions);
    free(server_hardware->hard_disk_details);
    free(server_hardware->memory_details);
    free(server_hardware->swap_details);
    free(server_hardware->cpu_details->cpu_hw_info);
    free(server_hardware->cpu_details->cpu_load_average);
    free(server_hardware->cpu_details);
*/
}

void servers_details_free(struct Server **servers, unsigned short int server_count){
    int i;    
    for(i = 0; i < 3 - 1; ++i){
        server_details_serverhw_free((*servers)->server_hardware);
        free(*servers++);
    }
}

