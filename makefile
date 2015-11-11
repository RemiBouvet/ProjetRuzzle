CC=gcc
FLAG=-Wall

main: ./src/*.c ./include/*.h
	$(CC) -o ./bin/main ./src/*.c $(FLAG)
main.o: ./bin/main.c
	$(CC) -c ./bin/main.c $(FLAG)
