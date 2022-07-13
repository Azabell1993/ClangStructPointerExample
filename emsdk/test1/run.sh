#!/bin/bash 

###################################################################
#Script Name	:                                                                                              
#Description	:                                                                                 
#Args           :                                                                                           
#Author       	: Azabell                                        
#Email         	: jeewoo19930315@gmail.com                                           
###################################################################
gcc -c -DBUILD_MY_DLL Calculator.c
gcc  -shared -o Calculator.dll Calculator.o -Wl
emcc Calculator.c -s WASM=1 -o Calculator.js
