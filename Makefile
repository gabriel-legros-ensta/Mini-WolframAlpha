CC=gcc
CFLAGS=-Wall -Werror 


all:main.x

main.x: utils.o lexical.o syntax_analysis.o evaluation.o 
	$(CC) -o $@ $^ `pkg-config --cflags --libs gtk+-3.0` -lm

%.o: %.c
	$(CC)  -I$(HOME)/Documents -c $< -o $@ `pkg-config --cflags --libs gtk+-3.0` -lm


clean:

	rm -f *.o

realclean: clean
	rm -f *.x
	
	
	
	

