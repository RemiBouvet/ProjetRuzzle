CC=gcc
FLAG=-Wall

main: main.o affichage.o generer.o pile_ptr.o points.o traitement.o
	$(CC) main.o affichage.o generer.o pile_ptr.o points.o traitement.o -o ./bin/ruzzlesolver $(FLAG)

affichage.o: ./src/affichage.c ./include/affichage.h ./include/structure.h
	$(CC) -c ./src/affichage.c $(FLAG)

generer.o: ./src/generer.c ./include/generer.h ./include/structure.h
	$(CC) -c ./src/generer.c $(FLAG)

pile_ptr.o: ./src/pile_ptr.c ./include/pile_ptr.h ./include/structure.h
	$(CC) -c ./src/pile_ptr.c $(FLAG)

points.o: ./src/points.c ./include/points.h ./include/structure.h
	$(CC) -c ./src/points.c $(FLAG)

traitement.o: ./src/traitement.c ./include/traitement.h ./include/structure.h
	$(CC) -c ./src/traitement.c $(FLAG)

main.o: ./src/main.c ./src/affichage.c ./src/generer.c ./src/pile_ptr.c ./src/points.c ./src/traitement.c ./src/points.c
	$(CC) -c ./src/main.c $(FLAG)

clean:
	rm -rf *.o
