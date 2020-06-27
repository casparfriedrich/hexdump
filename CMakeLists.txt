cmake_minimum_required(VERSION 3.17)

project(hexdump LANGUAGES C)

add_executable(hexdump main.c hexdump.c)
