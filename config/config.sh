#!/bin/bash

# Project struct

export EVERYDAY_CODE_CONFIG_FOLDER="$(pwd)"
export EVERYDAY_CODE_BASE_FOLDER=$(dirname "$(dirname $EVERYDAY_CODE_CONFIG_FOLDER)")

export LEETCODE_CHALLENGES_FOLDER=$EVERYDAY_CODE_BASE_FOLDER/src/challenges/leetcode
