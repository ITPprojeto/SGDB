main: sgdb.c sgdb.o
  gcc -o sgdb sgdb.c sgdb.o

clean:
  rm -rf * -o sgdb
