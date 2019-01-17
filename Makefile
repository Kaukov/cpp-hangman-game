CC := g++
SRCDIR := src
TARGET := hangman

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))

build:
	$(CC) $(SOURCES) -o $(TARGET)
