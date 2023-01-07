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

# Add executable
add_executable(134 134-Gas-Station.cpp)
add_executable(452 452-Minimum-Number-of-Arrows-to-Burst-Balloons.cpp)
add_executable(944 944-Delete-Columns-to-Make-Sorted.cpp)
add_executable(2244 2244-Minimum-Rounds-to-Complete-All-Tasks.cpp)
add_executable(1833 1833-Maximum-Ice-Cream-Bars.cpp)