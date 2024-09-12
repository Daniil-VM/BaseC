CC = gcc
CFLAGS = -Wall -g

all: temp_stats

temp_stats: main.o temp_functions.o
	$(CC) $(CFLAGS) -o temp_stats main.o temp_functions.o

main.o: main.c temp_functions.h
	$(CC) $(CFLAGS) -c main.c

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c temp_functions.c

clean:
	del /Q *.o temp_stats.exe