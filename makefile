# directories
## the directory of "MyRecipes" project
NR_DIR=../MyRecipes

## the directory of include file NR.h
NR_INC_DIR=$(NR_DIR)/include

## the directory of library file lNR.a
NR_LIB_DIR=$(NR_DIR)/lib

# flags
CFLAGS=-Wall -g -std=c11
IFLAGS=-I ./include -I $(NR_INC_DIR)
LFLAGS=-lNR -L $(NR_LIB_DIR) -lm
FLAGS=$(CFLAGS) $(IFLAGS) $(LFLAGS)

export

all:link chap2 chap3 chap4 chap5

link:
	for dir in chap2 chap3 chap4 chap5;\
	do\
		[ -e $(dir)/sub.mk ] && ln -s sub.mk $(dir)/sub.mk;\
	done

chap2:
	$(MAKE) -C chap2

chap3:
	$(MAKE) -C chap3

chap4:
	$(MAKE) -C chap4

chap5:
	$(MAKE) -C chap5

test:
	echo $(files)
