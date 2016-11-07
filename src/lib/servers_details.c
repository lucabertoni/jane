#include <stdlib.h>

#include "servers_details.h"

struct Server **servers_details_init(unsigned short int server_count){
    struct Server **servers;

    if((servers = (struct Server**) malloc(sizeof(struct Server**) * server_count)) == NULL)
        return NULL;
    
    return servers;
}

void servers_details_free(struct Server **servers, unsigned short int server_count){
    int i;    
    for(i = 0; i < 3 - 1; ++i){
        #include <stdio.h>
        free(*servers++);
        printf("dentro %d\n", i);
    }
}