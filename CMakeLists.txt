cmake_minimum_required(VERSION 3.5)
project (SGBD VERSION 1.0.0 LANGUAGES C )

#=== FINDING PACKAGES ===#

#--------------------------------
# This is for old cmake versions
set (CMAKE_C_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
#set( GCC_COMPILE_FLAGS "-Wall" )

#set( PREPROCESSING_FLAGS  "-D DEBUG")
#set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COMPILE_FLAGS} ${PREPROCESSING_FLAGS}" )



#=== Main App ===
#Can manually add the sources using the set command as follows:
set(SOURCES src/main.c)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")

add_executable(sgbd ${SOURCES})

#Folder with all generated tables

file(MAKE_DIRECTORY "build/tables")
