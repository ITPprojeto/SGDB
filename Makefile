CC=gcc
CFLAGS=-I.

sgdb:	main.o sgbdfunc.o
	$(CC)	-o	sgbd	main.o	sgbdfunc.o

clean:
	-rm	-f	sgbdfunc.o
	-rm	-f	sgbdfunc
