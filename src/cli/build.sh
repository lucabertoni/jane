#!/bin/sh

echo "############ BUILDING ############"

LOG_PATH="/var/log/jane/"
LIB=."./lib"

LIBSSH=ssh
LIBYAML=yaml

DEBUG=-g3
FLAGS="-Wall -Wunused-variable -Wreturn-type -Wint-conversion -Wdeprecated-declarations -Wmisleading-indentation -Wimplicit-function-declaration"
MACRO="-D JANE_DEBUG"
MACRO+=' -D JANE_LOG_PATH="'$LOG_PATH'"'

echo "Debug level: "$DEBUG
echo "Flags: "$FLAGS
echo "Macros: "$MACRO

mkdir -p $LOG_PATH
chmod o+rw $LOG_PATH

set -v
gcc $DEBUG $FLAGS $MACRO -iquote$LIB -l$LIBSSH -l$LIBYAML main.c $LIB/servers_details.c $LIB/jane_ssh.c $LIB/jane.c -o jane-cli ; set +v

chmod o+x jane-cli
echo "Finished."