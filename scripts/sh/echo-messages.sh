#!/bin/bash

RED='\033[1;31m'
L_RED='\033[0;31m'
GREEN='\033[0;32m'
L_GREEN='\033[1;32m'
ORANGE='\033[0;33m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
L_BLUE='\033[1;34m'

NC='\033[0m'

my_echo(){
  echo -e "$1\e[0m"
}

echo_info(){
  my_echo "${GREEN}[ ${L_GREEN}  INFO  ] ${GREEN}$1"
}

echo_warning(){
  my_echo "${ORANGE}[${YELLOW} WARNING ] ${ORANGE}$1"
}

echo_error(){
  my_echo "${RED}[${L_RED}  ERROR  ] ${RED}$1"
}

echo_note(){
  my_echo "${BLUE}[${L_BLUE}   NOTE  ] ${BLUE}$1"
}