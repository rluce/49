all: divide test_fdiv enquire

test_fdiv: test_fdiv.c fdiv_impl.c
	gcc -O0 -g -o test_fdiv fdiv_impl.c test_fdiv.c

divide: divide.c fdiv_impl.c
	gcc -O0 -g -o divide divide.c fdiv_impl.c

enquire: enquire.c
	gcc -O0 -g -o enquire enquire.c

clean:
	rm -f fdiv_impl.o fdiv divide
	rm -rf *.dSYM
