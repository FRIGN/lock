VERSION=\"0.0.5\"
CC = gcc
CFLAGS = -Os -mtune=native -Wall -Wextra -pedantic
DESTDIR = /usr/local/

all: lock

lock:
	$(CC) $(CFLAGS) lock.c -o lock


install: all
	@install lock $(DESTDIR)/bin/

clean:
	rm lock
