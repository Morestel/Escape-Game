CC=gcc -Wall -O3
GL=-lglut -lGLU -lGL -lm

alcatraz: main.c Map.o Personnage.o Camera.o
	$(CC) -o $@ $^ $(GL)

Map.o: Map.c Map.h Config.h

Personnage.o: Personnage.c Personnage.h Config.h

Camera.o: Camera.c Camera.h

clean:
	rm -f *.o alcatraz