#!/usr/bin/env bash
#Compiles and install oChre from source
#Run this script with root access

#TODO Install g++

#Install dependencies
#none so far

#Compile the binary
make COMPILER=g++ BINARY=bin PURGE=rm

#Install to path location
cp bin/oChre.bin /usr/games
