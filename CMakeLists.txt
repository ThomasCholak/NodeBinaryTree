# Makefile

cmake_minimum_required(VERSION 3.26)
project(NodeBinaryTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(NodeBinaryTree
        tree.cpp
        p0.cpp
        node.h
        tree.h)
