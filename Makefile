all: fdiv_impl.o fdiv

fdiv_impl.o: fdiv_impl.c
	gcc -O0 -g -c -o fdiv_impl.o fdiv_impl.c

fdiv: fdiv_impl.c
	gcc -O0 -g -o fdiv fdiv_impl.c

clean:
	rm -f fdiv_impl.o fdiv
	rm -rf *.dSYM
