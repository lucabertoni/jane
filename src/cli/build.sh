#!/bin/sh

LIB=../lib
LIBSSH=ssh
echo "############ BUILDING ############"
gcc -Wall -iquote$LIB -l$LIBSSH main.c $LIB/servers_details.c $LIB/jane_ssh.c $LIB/jane.c -o jane-cli
