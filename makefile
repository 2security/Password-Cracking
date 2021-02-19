runall: program1 program2

program1: combine.c
	gcc -o combine combine.c
	./combine

program2: passcrake.c
	gcc -o passcrake passcrake.c -lcrypt
	./passcrake
