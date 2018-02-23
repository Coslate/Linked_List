
#declare variable
CC = g++
CTAGS_UTIL = /usr/local/bin/
INCLUDE_FILES = ./include
INCLUDE_FLAGS = -I $(INCLUDE_FILES)
CFLAGS = -g -Wall -O3 
COMPILE_FLAGS = -c
MAIN_OBJECT_NAME = Linked_List_main
MAIN_OBJECT_SOURCE = $(MAIN_OBJECT_NAME).cpp
MAIN_OBJECT_EXEC = $(MAIN_OBJECT_NAME).o
MAIN_OBJECT_EXEC_OUTPUT = ../exec_output/

all : clean Linked_List all_file_tags
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o $(MAIN_OBJECT_SOURCE) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_EXEC)

Linked_List : Linked_List.cpp 
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) Linked_List.cpp $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o

all_file_tags : 
	$(CTAGS_UTIL)ctags -R ./*
	$(CTAGS_UTIL)ctags -a $(INCLUDE_FILES)/*

clean :
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)Linked_List.o