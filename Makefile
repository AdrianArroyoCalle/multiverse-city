#Makefile de Visual Divel Start
#(C) Adrián Arroyo Calle 2012
# Macros

CC = g++
CFLAGS = `wx-config --cppflags`
PRE = -DIDIOMA=ES -DLINUX
OBJ = main.o Inicio.o save.o tren.o dkey.o police.o hiper.o golf.o dialogbox.o mercado.o
EXIT = MultiverseCity
LIBFLAGS = `wx-config --libs`-L. -lmctcube


# Reglas explicitas

all:
	rm usr/games/MultiverseCity
	#Building libmctcube
	g++ -fPIC -c -o libmctcube.o libmctcube/main.cpp `wx-config --cppflags`	
	g++ -shared -fPIC -o usr/lib/libmctcube.so libmctcube.o
	cp usr/lib/libmctcube.so libmctcube.so
	#Building libdivcore
	g++ -fPIC -c -o libdivcore.o divcore/main.cpp `wx-config --cppflags`	
	g++ -shared -fPIC -o usr/lib/libdivcore.so libdivcore.o
	cp usr/lib/libdivcore.so libdivcore.so
	g++ -c MCT/main.cpp -o main.o `wx-config --cppflags`
	g++ -c MCT/MCTFrame.cpp -o mct.o `wx-config --cppflags`
	g++ -o usr/games/MultiverseCity main.o mct.o `wx-config --libs` -L. -lmctcube -lpthread -lvlc  -O3 -DVLC -DPTHREAD -ldivcore




clean:
	$(RM) $(OBJ)

# Reglas implicitas
