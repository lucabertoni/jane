#!/bin/sh

LIB=../lib
LIBSSH=ssh
echo "############ BUILDING ############"

DEBUG=-g3
FLAGS="-Wall -Wunused-variable -Wreturn-type -Wint-conversion -Wdeprecated-declarations -Wmisleading-indentation -Wimplicit-function-declaration"
MACRO="-D JANE_DEBUG"

echo "Debug level: "$DEBUG
echo "Flags: "$FLAGS
echo "Macros: "$MACRO

gcc $DEBUG $FLAGS $MACRO -iquote$LIB -l$LIBSSH main.c $LIB/servers_details.c $LIB/jane_ssh.c $LIB/jane.c -o jane-cli

echo "Built."