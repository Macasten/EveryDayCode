# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16.2)

project(
	playground
	VERSION 1.0.0
	DESCRIPTION "Workspace to test same code"
	LANGUAGES CXX
)

# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------

# Add executable
add_executable(playground ./playground.cpp)
