#!/bin/bash 

###################################################################
#Script Name	:                                                                                              
#Description	:                                                                                 
#Args           :                                                                                           
#Author       	: Azabell                                        
#Email         	: jeewoo19930315@gmail.com                                           
###################################################################
gcc main.c -I/usr/local/include/glib-2.0 -L/usr/local/lib -lglib-2.0 -lintl -liconv  -Wall -o test
