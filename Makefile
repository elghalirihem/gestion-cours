CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o cours.o
EXEC = gestion_sport

$(EXEC): $(OBJ)
$(CC) $(OBJ) -o $(EXEC)

main.o: main.c cours.h
$(CC) $(CFLAGS) -c main.c

cours.o: cours.c cours.h
$(CC) $(CFLAGS) -c cours.c

clean:
rm -f $(OBJ) $(EXEC)

.PHONY: clean


