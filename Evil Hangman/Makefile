CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o my_string.o

unit_test: my_string.o unit_test.o test_defs.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_defs.o my_string.o

test_defs.o: test_defs.c
	$(CC) $(CFLAGS) -c test_defs.c -o test_defs.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(OBJECTS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

my_string.o: my_string.c my_string.h
	$(CC) $(CFLAGS) -c my_string.c


unit_test.o: unit_test.c unit_test.h
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o

clean:
	rm string_driver $(OBJECTS) *.o *~
