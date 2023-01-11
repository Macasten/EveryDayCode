#!/bin/bash

################################################################################
# configuration management
################################################################################
THIS_FILE=$(readlink -f $0)
THIS_FOLDER="$(dirname $THIS_FILE)"

cd "$THIS_FOLDER"

source ../../config/config.sh

#########a#######################################################################
# leetcode management
################################################################################
function getChallengeFile(){
  temp="$(echo $1 | sed -r 's/[ .]+/-/g')"
  echo "$LEETCODE_CHALLENGES_FOLDER/$temp.cpp"
}

function newChallenge(){
  # Get new file name
  CHALLENGE_FILE=$( getChallengeFile "$1")

  # Copy template file
  cp $LEETCODE_CHALLENGES_TEMPLATE $CHALLENGE_FILE

  # Replace challenge tile
  sed -i "s/<CHALLENGE_TITLE>/$CHALLENGE_TITLE/g" $CHALLENGE_FILE

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

newChallenge "$CHALLENGE_TITLE"

# TODO add git validation and branch creation
# if [ `git rev-parse --verify asdf 2>/dev/null` ]
# then
#   echo "cenas"
# fi

echo "!!END!!"