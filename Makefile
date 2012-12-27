#Makefile de Visual Divel Start
#(C) Adrián Arroyo Calle 2012
# Macros

CC = g++
CFLAGS = `wx-config --cppflags`
PRE = -DIDIOMA=ES -DLINUX -DVLC -DPTHREAD
OBJ = main.o mct.o
EXIT = MultiverseCity
OPT = -O3
LIBFLAGS = `wx-config --libs`-L. -lmctcube -ldivcore -lvlc -pthread
NECESARIO = libmctcube.so libdivcore.so mct.o main.o


# Reglas explicitas

Release: all

all: $(NECESARIO)
	g++ -o usr/games/MultiverseCity main.o mct.o $(LIBFLAGS) $(OPT) $(PRE)
main.o:
	g++ -c MCT/main.cpp -o main.o `wx-config --cppflags` $(PRE)
mct.o:
	g++ -c MCT/MCTFrame.cpp -o mct.o `wx-config --cppflags` $(PRE)
libmctcube.so:
	g++ -fPIC -c -o libmctcube.o libmctcube/main.cpp `wx-config --cppflags`	$(PRE)
	g++ -fPIC -c -o concejal.o libmctcube/concejal.cpp `wx-config --cppflags` $(PRE)
	g++ -shared -fPIC -o usr/lib/libmctcube.so libmctcube.o concejal.o
	cp usr/lib/libmctcube.so libmctcube.so
libdivcore.so:
	#Building libdivcore
	g++ -fPIC -c -o libdivcore.o divcore/main.cpp `wx-config --cppflags` $(PRE)	
	g++ -shared -fPIC -o usr/lib/libdivcore.so libdivcore.o -lvlc
	cp usr/lib/libdivcore.so libdivcore.so




clean:
	rm *.so *.o

# Reglas implicitas
