#!/bin/bash

################################################################################
# configuration management
################################################################################
THIS_FILE=$(readlink -f $0)
THIS_FOLDER="$(dirname $THIS_FILE)"

cd "$THIS_FOLDER"

source ../../config/config.sh
source ./echo-messages.sh

################################################################################
# leetcode management
################################################################################
function getChallengeFile(){
  temp="$(echo $1 | sed -r 's/[ .]+/-/g')"
  echo "$LEETCODE_CHALLENGES_FOLDER/$temp.cpp"
}

function newChallenge(){
  # Get new file name
  CHALLENGE_FILE=$( getChallengeFile "$1")

  # Check if file exist
  if [ -f "$CHALLENGE_FILE" ] ; then
    echo_error "File already exist: $CHALLENGE_FILE"
    exit 1
  fi

  # Copy template file
  cp $LEETCODE_CHALLENGES_TEMPLATE $CHALLENGE_FILE

  # Replace challenge tile
  sed -i "s/<CHALLENGE_TITLE>/$CHALLENGE_TITLE/g" $CHALLENGE_FILE

  echo_info "File created: $CHALLENGE_FILE"
}
################################################################################
# main
################################################################################

# Read Flags
while [[ $# -gt 0 ]]; do
  case $1 in
    -n|--new)
      shift
      CHALLENGE_TITLE=$1
      NEW_CHALLENGE=1
      shift
      ;;
  esac
done

# Backup playground file
if [[ -n "$NEW_CHALLENGE" ]] ; then
  echo_info "Starting Environment Setup"
  newChallenge "$CHALLENGE_TITLE"
fi
