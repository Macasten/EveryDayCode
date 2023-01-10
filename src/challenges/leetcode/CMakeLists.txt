# =============================================================================
# General settings
# -----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.22.1)

project(
  DailyCodeChallenge
  VERSION 1.0.0
  DESCRIPTION "Daily Code Challenge"
  LANGUAGES CXX
)

message(STATUS "Leetcode Daily Challenge")

# =============================================================================
# Compiler settings
# -----------------------------------------------------------------------------
file( GLOB FILES_SOURCES "${PROJECT_SOURCE_DIR}/*.cpp" )

foreach( MAIN_SOURCE_FILE ${FILES_SOURCES} )
  get_filename_component(FILE_NAME ${MAIN_SOURCE_FILE} NAME_WE)
  set(EXECUTABLE_NAME "leetcode-${FILE_NAME}")
  add_executable( ${EXECUTABLE_NAME} ${MAIN_SOURCE_FILE} )
  target_compile_definitions(${EXECUTABLE_NAME} PRIVATE FLAG_TEST_ON )
  target_include_directories(${EXECUTABLE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
endforeach( MAIN_SOURCE_FILE ${FILES_SOURCES} )