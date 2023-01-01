cmake_minimum_required(VERSION 3.23)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c registration.c authorization.c userInterface.c addFilm.c catalog.c favorites.c addFilm.h authorization.h catalog.h favorites.h registration.h userInterface.h)
