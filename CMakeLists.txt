cmake_minimum_required(VERSION 3.3)
project(CSCI_3240_LAB_01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -Wall -pedantic")

set(SOURCE_FILES main.c)
#add_executable(CSCI_3240_LAB_01 ${SOURCE_FILES})
add_executable(labDataRepresentation-norris ${SOURCE_FILES})
