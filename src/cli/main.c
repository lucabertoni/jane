#include "servers_details.h"

#include <stdlib.h>

int main(){
    struct Server **servers, **head;
    
    servers = servers_details_init(3);
    
    head = servers;
    #include <stdio.h>
    printf("%p|%p\n",servers,head);
    *servers = (struct Server*) malloc(sizeof(struct Server*));
    servers++;
    *servers = (struct Server*) malloc(sizeof (struct Server*));
    printf("%p|%p\n",servers,head);
    
    servers_details_free(head, 2);
    
    return 0;
}