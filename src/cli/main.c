#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "servers_details.h"

extern uint8_t jane_ssh_error;

int main(){
    struct Server **servers, **head;
    
    servers = servers_details_init(3);
    
    printf("Error %d\n", jane_ssh_error);
    
    head = servers;
    printf("%p|%p\n",servers,head);
    *servers = (struct Server*) malloc(sizeof(struct Server*));
    servers++;
    *servers = (struct Server*) malloc(sizeof (struct Server*));
    printf("%p|%p\n",servers,head);
    
    servers_details_free(head, 2);
    
    return 0;
}