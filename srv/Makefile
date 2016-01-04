all : serveur
serveur : ../cli/screen.o ../cli/input.o ../cli/map.o ../cli/player.o ../cli/nonblock.o main.o
	gcc -o serveur ../cli/screen.o ../cli/input.o ../cli/map.o ../cli/player.o ../cli/nonblock.o main.o

screen.o : ../cli/screen.c ../cli/screen.h
	gcc -c screen.c

input.o : ../cli/input.c ../cli/input.h
	gcc -c ../cli/input.c

map.o : ../cli/map.c ../cli/map.h
	gcc -c ../cli/map.c
 
player.o : ../cli/player.c ../cli/player.h
	gcc -c ../cli/player.c

nonblock.o : ../cli/nonblock.c ../cli/nonblock.h
	gcc -c ../cli/nonblock.c

main.o : main.c ../cli/*.h
	gcc -c main.c


