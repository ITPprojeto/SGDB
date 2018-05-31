main: sgbd.o
	gcc -o sgbd sgbd.o

sgbd:
		gcc -c sgbd.c

clean:
	rm -rf sgbd
