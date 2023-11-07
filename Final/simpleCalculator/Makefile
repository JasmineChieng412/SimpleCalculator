# Makefile Variables
CFLAGS	= -Wall	-pedantic -ansi	-Werror	-g
OBJS    = calculator.o calcInterface.o terminal.o LinkedList.o writeToFile.o
EXEC    = calculator
CC      = gcc

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

calculator.o : calculator.c calcInterface.h terminal.h LinkedList.h writeToFile.h	
	$(CC)  $(CFLAGS) -c calculator.c

calcInterface.o : calcInterface.c calcInterface.h terminal.h LinkedList.h
	$(CC) $(CFLAGS) -c calcInterface.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c

writeToFile.o :  writeToFile.c writeToFile.h LinkedList.h
	$(CC) $(CFLAGS) -c writeToFile.c
clean	: 
	rm	-f	$(EXEC)	$(OBJS) 
        

