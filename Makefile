OBJS = obj/Pixel.o obj/Image.o
FLAGS = -Wall -l SDL2 -o

all: bin/test.out

bin/test.out: obj/Image.o obj/Pixel.o obj/mainExemple.o 
	g++ -g obj/Image.o obj/Pixel.o obj/mainExemple.o -o bin/test.out -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
	
obj/main.o: src/main.cpp src/Image.h src/Pixel.h
	g++ -g -Wall -c src/main.cpp -o obj/main.o
	
obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h src/Pixel.h
	g++ -g -Wall -c src/mainAffichage.cpp -o obj/mainAffichage.o

obj/mainExemple.o: src/mainExemple.cpp src/Image.h src/Pixel.h 
	g++ -g -Wall -c src/mainExemple.cpp -o obj/mainExemple.o
	
obj/Image.o: src/Image.h src/Image.cpp
	g++ -g -Wall -c src/Image.cpp -o obj/Image.o -I/usr/include/SDL2
	
obj/Pixel.o: src/Pixel.h src/Pixel.cpp
	g++ -g -Wall -c src/Pixel.cpp -o obj/Pixel.o




clean:
	rm obj/*.o bin/*

test:
	bin/test

exemple:
	bin/exemple

affichage:
	bin/affichage
