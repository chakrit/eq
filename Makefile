default:
	mkdir -p obj bin
	gcc -fPIC -c -o obj/eq.o src/eq.c
	gcc -o bin/eq obj/eq.o
