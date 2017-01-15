#include <stdlib.h>
#include <stdio.h>

#include "servers_details.h"
#include "errors.h"

extern uint16_t jane_error;

int server_details_serverhw_init(struct Server *server_details){
    server_details->server_hardware = (struct ServerHW*) malloc(sizeof(struct ServerHW));

    server_details->server_hardware->hard_disk_details = (struct HardDisk*) malloc(sizeof(struct HardDisk));
    server_details->server_hardware->hard_disk_details->partitions = (struct HDDPart*) malloc(sizeof(struct HDDPart));
    
    server_details->server_hardware->memory_details = (struct Memory*) malloc(sizeof(struct Memory));
    
    server_details->server_hardware->swap_details = (struct Swap*) malloc(sizeof(struct Swap));
    
    server_details->server_hardware->cpu_details = (struct CPU*) malloc(sizeof(struct CPU));

    return ((server_details->server_hardware == NULL) || (server_details->server_hardware->hard_disk_details == NULL) ||
            (server_details->server_hardware->hard_disk_details->partitions == NULL)||
            (server_details->server_hardware->memory_details == NULL) || (server_details->server_hardware->swap_details == NULL) ||
            (server_details->server_hardware->cpu_details == NULL)
    ) ? JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR : 0;
}

struct Server **servers_details_init(unsigned short int server_count){
    struct Server **servers, **head;
    int i;

    if(server_count <= 0 || ((servers = (struct Server**) malloc(sizeof(struct Server) * server_count)) == NULL)){
        jane_error = JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR;
        return NULL;
    }else{
        head = servers;

        for (i = 0; i < server_count; ++i, ++servers)
        {
            if((*servers = (struct Server*) malloc(sizeof(struct Server*))) == NULL ||
                (server_details_serverhw_init(*servers) == JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR)){
                jane_error = JANE_ERROR_GENERIC_STRUCT_ALLOC_ERROR;
                return NULL;
            }
        }

        servers = head;
    }

    return servers;
}

void server_details_serverhw_free(struct Server *server){
    free(server->server_hardware->hard_disk_details->partitions);
    server->server_hardware->hard_disk_details->partitions = NULL;

    free(server->server_hardware->hard_disk_details);
    server->server_hardware->hard_disk_details = NULL;

    free(server->server_hardware->memory_details);
    server->server_hardware->memory_details = NULL;

    free(server->server_hardware->swap_details);
    server->server_hardware->swap_details = NULL;

    free(server->server_hardware->cpu_details->cpu_hw_info);
    server->server_hardware->cpu_details->cpu_hw_info = NULL;

    free(server->server_hardware->cpu_details->cpu_load_average);
    server->server_hardware->cpu_details->cpu_load_average = NULL;

    free(server->server_hardware->cpu_details);
    server->server_hardware->cpu_details = NULL;

    free(server->server_hardware);
    server->server_hardware = NULL;
}

void servers_details_free(struct Server **servers, unsigned short int server_count){
    int i;
    for(i = 0; i < server_count; ++i, ++servers){
        server_details_serverhw_free(*servers);
        free(*servers);
    }
}

/*
    It Loads servers details from yaml-formatted file.
    Format of file:
    -   server_id           :   !!str 1 # or whatever you want, like a personal code (ex: 0A124F), it will then be translated into a string
        server_name         :   Main "jane" server
        server_domain       :   www.mywebsite.com
        server_ip_address   :   127.0.0.1
        server_ssh_port     :   22
        server_mac_address  :   # if empty it will be filled
    - and so on...
*/
struct Server **server_details_load_from_file(const char* file_name){
    int number_of_servers = 0;
    struct Server **servers;

    // TODO: Continuare qui
    servers = servers_details_init(number_of_servers);

    return servers;
}