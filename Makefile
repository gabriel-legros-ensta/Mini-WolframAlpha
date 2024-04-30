CC=gcc
CFLAGS=-Wall -Werror -I$(HOME)/Documents


all:main.x

main.x: utils.o lexical.o syntax_analysis.o evaluation.o 
	$(CC) -o $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:

	rm -f *.o

realclean: clean
	rm -f *.x
