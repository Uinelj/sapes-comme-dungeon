all : client
client : screen.o input.o map.o player.o actions.o nonblock.o main.o
	gcc -o client screen.o input.o map.o player.o actions.o nonblock.o main.o

screen.o : screen.c screen.h
	gcc -c screen.c

input.o : input.c input.h
	gcc -c input.c

map.o : map.c map.h
	gcc -c map.c

player.o : player.c player.h
	gcc -c player.c

actions.o : actions.c actions.h
	gcc -c actions.c

nonblock.o : nonblock.c nonblock.h
	gcc -c nonblock.c

main.o : main.c *.h
	gcc -c main.c

clean :
	rm file1.o file2.o executable core
