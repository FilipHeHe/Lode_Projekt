# CMakeList.txt : CMake project for BattleshipGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("BattleshipGame")

# Add source to this project's executable.
add_executable (BattleshipGame "BattleshipGame.cpp" "BattleshipGame.h"   "Multiplayer.cpp" "random_placement.h" "random_placement.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BattleshipGame PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
