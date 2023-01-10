# =============================================================================
# General settings
# -----------------------------------------------------------------------------
message(STATUS "Challenges Hall")
cmake_minimum_required(VERSION 3.22.1)

project(
	ChallengesHall
	VERSION 1.0.0
	DESCRIPTION "Main gathering for challenges"
	LANGUAGES CXX
)

print_environment()
# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------

# =============================================================================
# Project settings
# -----------------------------------------------------------------------------
add_subdirectory(leetcode)