SpireC: main.o factorizations.o utils.o
	gcc -pthread -o SpireC main.o factorizations.o utils.o

main.o: src/main.c src/factorizations.h
	gcc -c src/main.c

factorizations.o: src/factorizations.c src/utils.h
	gcc -c src/factorizations.c

utils.o: src/utils.c
	gcc -c src/utils.c
