main: main.o ./lib/add.o ./lib/subtract.o ./lib/multiply.o ./lib/divide.o
	gcc -I./lib -L./lib main.c -Wl,--rpath=./lib -ltest -o exprshared
main.o: main.c
	gcc -c main.c
./lib/add.o: ./lib/add.c
	gcc -c ./lib/add.c
./lib/subtract.o: ./lib/subtract.c
	gcc -c ./lib/subtract.c
./lib/multiply.o: ./lib/multiply.c
	gcc -c ./lib/multiply.c
./lib/divide.o: ./lib/divide.c
	gcc -c ./lib/divide.c
clean:
	rm -f foobar main.o add.o subtract.o multiply.o divide.o


