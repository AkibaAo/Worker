cmake_minimum_required(VERSION 3.27)
project(Worker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Worker WorkerManager.cpp
        WorkManager.h
        MainSystem.cpp
        Worker.h
        employee.h
        employee.cpp
        manager.h
        manager.cpp
        boss.h
        boss.cpp)
