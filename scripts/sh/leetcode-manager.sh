#!/bin/bash

################################################################################
# configuration management
################################################################################
THIS_FILE=$(readlink -f $0)
THIS_FOLDER="$(dirname $THIS_FILE)"

echo "$THIS_FILE"
echo "$THIS_FOLDER"

cd "$THIS_FOLDER"

echo "Loading configuration"
source ../../config/config.sh
# echo "$EVERYDAY_CODE_SHRC_FILE"
echo "$EVERYDAY_CODE_CONFIG_FOLDER"
echo "$EVERYDAY_CODE_BASE_FOLDER"
echo "$LEETCODE_CHALLENGES_FOLDER"
echo "configs"

################################################################################
# leetcode management
################################################################################
function getChallengeFile(){
  temp="$(echo $1 | sed -r 's/[ .]+/-/g')"
  echo "$LEETCODE_CHALLENGES_FOLDER/$temp.cpp"
}

function newChallenge(){
  CHALLENGE_FILE=$( getChallengeFile "$1")
  touch $CHALLENGE_FILE
}
################################################################################
# main
################################################################################

# Read Flags
while [[ $# -gt 0 ]]; do
  case $1 in
    -n|--new)
      shift
      CHALLENGE_TITEL=$1
      shift
      ;;
    # -m|--math)
    #     shift
    #     MATH_LIB=$1
    #     shift
    #     ;;
    # -m*)
    #     shift
    #     MATH_LIB="${1#*-m}"
    #     shift
    #     ;;
    # -t|--type)
    #     shift
    #     BUILD_TYPE=$(echo $1 | tr 'a-z' 'A-Z')
    #     shift
    #     ;;
    # -t*)
    #     shift
    #     BUILD_TYPE=$(echo "${1#*-t}" | tr 'a-z' 'A-Z')
    #     shift
    #     ;;
    # -a|--arch)
    #     shift
    #     BUILD_ARCH=$1
    #     shift
    #     ;;
    # -a*)
    #     BUILD_ARCH="${1#*-a}"
    #     shift
    #     ;;
    # -f|--bypass-verification)
    #     BYPASS_VERIFICATION=true
    #     shift
    #     ;;
    # \?)
    #     shift
    #     echo "Invalid option: -$OPTARG"
    #     exit 1
    #     ;;
  esac
done

getChallengeFile "$CHALLENGE_TITEL"
newChallenge "$CHALLENGE_TITEL"

echo "!!END!!"