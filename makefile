CC=gcc
FLAG=-g -Wall -Wextra -Werror
NOM_EXEC=ruzzlesolver
DIR_EXEC=/bin/
SRC=/src/
INCLUDE=/include/

main: main.o affichage.o generer.o pile_ptr.o points.o traitement.o
	$(CC) main.o affichage.o generer.o pile_ptr.o points.o traitement.o -o .$(DIR_EXEC)$(NOM_EXEC) $(FLAG)

affichage.o: .$(SRC)affichage.c .$(INCLUDE)affichage.h .$(INCLUDE)structure.h .$(INCLUDE)couleur.h
	$(CC) -c .$(SRC)affichage.c $(FLAG)

generer.o: .$(SRC)generer.c .$(INCLUDE)generer.h .$(INCLUDE)structure.h
	$(CC) -c .$(SRC)generer.c $(FLAG)

pile_ptr.o: .$(SRC)pile_ptr.c .$(INCLUDE)pile_ptr.h .$(INCLUDE)structure.h
	$(CC) -c .$(SRC)pile_ptr.c $(FLAG)

points.o: .$(SRC)points.c .$(INCLUDE)points.h .$(INCLUDE)structure.h
	$(CC) -c .$(SRC)points.c $(FLAG)

traitement.o: .$(SRC)traitement.c .$(INCLUDE)traitement.h .$(INCLUDE)structure.h
	$(CC) -c .$(SRC)traitement.c $(FLAG)

main.o: .$(SRC)main.c .$(SRC)affichage.c .$(SRC)generer.c .$(SRC)pile_ptr.c .$(SRC)points.c .$(SRC)traitement.c .$(SRC)points.c
	$(CC) -c .$(SRC)main.c $(FLAG)

clean:
	rm -rf *.o
