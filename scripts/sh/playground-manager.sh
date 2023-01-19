#!/bin/bash

################################################################################
# configuration management
################################################################################
THIS_FILE=$(readlink -f $0)
THIS_FOLDER="$(dirname $THIS_FILE)"

cd "$THIS_FOLDER"

source ../../config/config.sh
################################################################################
# playground management
################################################################################

function cleanPlayground(){

  cp $PLAYGROUND_TEMPLATE_FILE $PLAYGROUND_FILE
}

function backupPlaygroundTest(){
  cp $PLAYGROUND_FILE "$PLAYGROUND_EXAMPLES_FORLDER/$1.cpp"
}

################################################################################
# main
################################################################################

# Read Flags
while [[ $# -gt 0 ]]; do
  case $1 in
    -b|--bachup)
      shift
      BACKUP_FILE=$1
      BACKUP_PLAYGROUND=1;
      shift
      ;;
    -c|--clean)
      CLEAN_PLAYGROUND=1;
      shift
      ;;
    *)
      echo "Invalid option: -$1"
      exit 1
      ;;
  esac
done


# Backup playground file
if [[ -n "$BACKUP_PLAYGROUND" ]] ; then
  backupPlaygroundTest "$BACKUP_FILE"
fi

# Clean playground file
if [[ -n "$CLEAN_PLAYGROUND" ]] ; then
  cleanPlayground
fi
