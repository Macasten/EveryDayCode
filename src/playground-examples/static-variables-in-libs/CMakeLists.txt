# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22.1)

project(
	playground
	VERSION 1.0.0
	DESCRIPTION "Workspace to test same code"
	LANGUAGES CXX
)

# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------

add_subdirectory(includes)

# Add executable

set(EXECUTABLE_NAME playground)
add_executable(${EXECUTABLE_NAME} ./playground.cpp)

target_link_libraries(${EXECUTABLE_NAME} PUBLIC playground_lib)

