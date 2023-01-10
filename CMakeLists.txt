# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22.1)

project(
	EveryDayCode
	VERSION 1.0.0
	DESCRIPTION "Every Day Code"
	LANGUAGES CXX
)

include(scripts/cmake/PrintVariables.cmake)

print_environment()
# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------
# Define a parta onde sera colocado o binario resultante da compilação
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/output")

file( GLOB_RECURSE FILES_SOURCES )
message(NOTICE "Teste -> ${FILES_SOURCES} <- ficheiros")
# =============================================================================
# Project settings
# -----------------------------------------------------------------------------
add_subdirectory(playground)
add_subdirectory(src)