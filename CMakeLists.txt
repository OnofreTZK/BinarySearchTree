cmake_minimum_required(VERSION 3.5)
project( ABB VERSION 0.1 LANGUAGES CXX)


# set the compiling flags
set ( CMAKE_CXX_FLAGS "-g -Wall" )

#set include path
include_directories ( include )

# define the sources for the project

add_executable ( abb
				 src/main.cpp
         src/bst.cpp ) #this is the application and has the main

# define C++11 standard
set_property (TARGET abb PROPERTY CXX_STANDARD 11)

#end
