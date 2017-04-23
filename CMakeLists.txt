#Specify minimum cmake version and project name
cmake_minimum_required(VERSION 3.6.2)
project(siete_y_medio)

#Bring the headers into the project
include_directories(include)

#Bring the source files into the project
file(GLOB SOURCES "src/*.cpp")

#Create an executable from the sources
add_executable(siete_y_medio ${SOURCES})
