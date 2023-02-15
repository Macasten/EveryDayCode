file( GLOB FILES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )

add_library(playground_lib ${FILES_SOURCES})

target_include_directories(playground_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
