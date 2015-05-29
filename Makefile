CC=clang

CFLAGS= -Wall -Wextra -std=c99 -g

LDFLAGS= -lncurses

SRC= textbase.c DEAD.c
OBJ= ${SRC:.c=.o}

all: textbase

textbase: ${OBJ}

clean:
	rm -f *~ *.o
	rm -f textbase

#END
