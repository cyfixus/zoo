
########################################
# Author: Sean Foster
# Date: 09/21/2017
# Description: Makefile for Project 02: Zoo Tycoon
########################################
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o menu.o validator.o animal.o tiger.o turtle.o penguin.o zoo.o moneyManagement.o animalManagement.o

SRCS = main.cpp menu.cpp validator.cpp animal.cpp tiger.cpp turtle.cpp penguin.cpp zoo.cpp moneyManagement.cpp animalManagement.cpp

HEADERS = menu.hpp validator.hpp animal.hpp tiger.hpp turtle.hpp penguin.hpp zoo.hpp

#target: dependencies
#		rule to build

zoo: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o zoo