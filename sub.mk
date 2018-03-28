# directories
## the directory of "MyRecipes" project
NR_DIR=../../MyRecipes
## the directory of include file NR.h
NR_INC_DIR=$(NR_DIR)/include
## the directory of library file lNR.a
NR_LIB_DIR=$(NR_DIR)/lib
## include directory
INC_DIR=../include

# common source files in dir "src"
SRCFILES=$(wildcard ../src/*.c)

# flags
CFLAGS=-Wall -g -std=c11
IFLAGS=-I $(INC_DIR) -I $(NR_INC_DIR)
LFLAGS=-lNR -L $(NR_LIB_DIR) -lm
ALLFLAGS=$(SRCFILES) $(CFLAGS) $(IFLAGS) $(LFLAGS)

# gcc & python
CC=gcc
PYTHON=python

# source files
SRC=$(wildcard *.c)
# target
BIN=$(basename $(SRC))
# text files
TXT=$(subst .c,.txt,$(SRC))
#python scripts
PYFILES=$(wildcard *.py)

.PHONY:all bin run py test

all:$(BIN)

%:%.c
	$(CC) -o $@ $< $(ALLFLAGS)

run:$(TXT)

$(TXT):%.txt:%
	./$< > $@

py:
	for pyfile in $(PYFILES); do $(PYTHON) $$pyfile; done

test:
	@echo $(CC) -o $(BIN) $(SRC) $(ALLFLAGS)
