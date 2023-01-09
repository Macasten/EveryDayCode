# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16.2)

project(
	DailyCodeChallenge
	VERSION 1.0.0
	DESCRIPTION "Daily Code Challenge"
	LANGUAGES CXX
)

# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------

# Define a parta onde sera colocado o binario resultante da compilação
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../output)

file( GLOB_RECURSE FILES_SOURCES )
foreach( MAIN_SOURCE_FILE ${FILES_SOURCES} )
  get_filename_component(EXECUTABLE_NAME ${MAIN_SOURCE_FILE} NAME_WE)
  add_executable( ${EXECUTABLE_NAME} ${MAIN_SOURCE_FILE} )
  # Define as definições de compilação
  target_compile_definitions(${EXECUTABLE_NAME} PRIVATE FLAG_TEST_ON )
endforeach( MAIN_SOURCE_FILE ${FILES_SOURCES} )