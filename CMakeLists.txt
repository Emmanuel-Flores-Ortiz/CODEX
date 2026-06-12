cmake_minimum_required(VERSION 3.20)

# Pon aquí el nombre de tu proyecto (puede ser cualquier nombre)
project(PROGRAMACION_C++_UNIAT)

# Configuracion de Version (C++20)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- PARCIAL 1 ---
# add_executable(asset "asset.h")
add_executable(quests quests.h quests.cpp members.cpp)

# --- PROYECTO GUILDEX ---
#add_executable(asset "asset.h")
add_executable(Inventory Inventory.cpp)
