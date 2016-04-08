# directories
## the directory of "MyRecipes" project
NR_DIR=../MyRecipes
## the directory of include file NR.h
NR_INC_DIR=$(NR_DIR)/include
## the directory of library file lNR.a
NR_LIB_DIR=$(NR_DIR)/lib
# flags
CFLAGS=-Wall -g -std=c11
LFLAGS=-lNR -L $(NR_LIB_DIR) -lm
IFLAGS=-I ./include -I $(NR_INC_DIR)
FLAGS=$(CFLAGS) $(IFLAGS) $(LFLAGS)
# source files
files=$(wildcard ./include/*) ./src/OrbitalEle_CoorVol_Trans.c
files2=$(files) \
	./src/OrbitEvaluation.c \
	./src/transform.c
files3=$(files) \
	./src/CircularRTB.c \
	./src/CircularSitnikov.c \
	./src/EllipticSitnikov.c
# executable files
bin21=./bin/evaluate
bin22=./bin/transform
bin31=./bin/circularRTB
bin32=./bin/CircularSitnikov
bin33=./bin/EllipticSitnikov
BIN=$(bin21) $(bin22) $(bin31) $(bin32) $(bin33)
# text files
txt21=./homework/chap2/evaluate.txt
txt22=./homework/chap2/transform.txt
txt31=./homework/chap3/circularRTB.txt
txt32=./homework/chap3/CircularSitnikov.txt
txt33=./homework/chap3/EllipticSitnikov.txt


.PHONY:all chap2 chap3 run run2 run3 py2 py3

# all the executable files, divided into chapters
all:chap2 chap3

## chapter 2
chap2:$(bin21) $(bin22)

$(bin21):$(files2)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c $(FLAGS)
$(bin22):$(files2)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/transform.c $(FLAGS)

## chapter 3
chap3:$(bin31) $(bin32) $(bin33)

$(bin31):$(files3)
	gcc -o $@ ./src/CircularRTB.c $(FLAGS)

$(bin32):$(files3)
	gcc -o $@ ./src/CircularSitnikov.c $(FLAGS)

$(bin33):$(files3)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/EllipticSitnikov.c $(FLAGS)

# run all the executable files and write the output into text files
run:run2 run3

## chapter 2
run2:$(txt21) $(txt22)

$(txt21):$(bin21)
	$< > $@

$(txt22):$(bin22)
	$< > $@

py2:$(txt21) $(txt22)
	cd homework/chap2/;python plotorbit.py

## chapter 3
run3:$(txt31) $(txt32) $(txt33)

$(txt31):$(bin31)
	$< > $@

$(txt32):$(bin32)
	$< > $@

$(txt33):$(bin33)
	$< > $@

py3:py31 py32 py33 py34

py31:$(txt31)
	cd homework/chap3/;python orbitplot.py

py32:$(txt31)
	cd homework/chap3/;python plotcontour.py

py33:$(txt31)
	cd homework/chap3/;python PoincareMapRTB.py

py34:$(txt32) $(txt33)
	cd homework/chap3/;python phasediagram.py




rebuild:
	rm -f $(BIN);make all

test:
	echo $(files)
