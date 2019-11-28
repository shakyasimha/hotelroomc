cmake_minimum_required(VERSION 3.12)
project(hotelroomc VERSION 1.0.0)

add_library(
    console-func
    conio.h
    SetConsoleCursorPosition.h 
)

add_executable(main main.c)

target_link_libraries(main PRIVATE console-func)