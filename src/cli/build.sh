#!/bin/sh

LIB=../lib
LIBSSH=libssh
echo "############ BUILDING ############"
gcc -Wall -iquote$LIB -L$LIBSSH main.c $LIB/servers_details.c $LIB/jane_ssh.c $LIB/jane.c -o jane-cli
