all: main

main: main.c
	gcc -o fork_ex main.c


clean:
	rm -f fork_ex
