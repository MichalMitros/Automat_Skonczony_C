all: AutSkon.c
	gcc AutSkon.c -o AutSkon
test: all
	./AutSkon 0 1 1 0 1 1 0 0 1 0 0
