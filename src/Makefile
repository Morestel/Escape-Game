CC=gcc -Wall -O3
GL=-lglut -lGLU -lGL -lm

alcatraz: main.c Config.h Map.o Camera.o Texture.o Vecteur.o Physique.o
	$(CC) -o $@ $^ $(GL)

%.o: %.c %.h

clean:
	rm -f *.o alcatraz