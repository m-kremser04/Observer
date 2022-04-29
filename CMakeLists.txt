cmake_minimum_required(VERSION 3.19)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(untitled4
        ConcreteObserver.h
        ConcreteObserverImpl.cpp
        ConcreteSubject.h
        main.cpp
        ObserverInterface.h
        Subject.h
        SubjectImpl.cpp)
