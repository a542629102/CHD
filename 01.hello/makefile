hello:hello.o my_print.o
	gcc -o hello hello.o my_print.o
hello.o:hello.c 
	gcc -c hello.c
my_print.o:my_print.c
	gcc -c my_print.c
clean: 
	rm *.o hello

