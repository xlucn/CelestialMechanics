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

# source files
files=$(wildcard ./include/*) ./src/OrbitalEle_CoorVol_Trans.c
files2=$(files) \
	./src/OrbitEvaluation.c \
	./src/transform.c
files3=$(files) \
	./src/CircularRTB.c \
	./src/CircularSitnikov.c \
	./src/EllipticSitnikov.c
files4=$(files) \
	./src/Perturbation.c \
	./src/LaplaceCoefficient.c

# executable files
bin21=./bin/evaluate
bin22=./bin/transform
bin31=./bin/circularRTB
bin32=./bin/CircularSitnikov
bin33=./bin/EllipticSitnikov
bin41=./bin/Perturbation
bin42=./bin/LaplaceCoef
BIN=$(bin21) $(bin22) $(bin31) $(bin32) $(bin33) $(bin41) $(bin42)

# text files
txt21=./homework/chap2/evaluate.txt
txt22=./homework/chap2/transform.txt
txt31=./homework/chap3/circularRTB.txt
txt32=./homework/chap3/CircularSitnikov.txt
txt33=./homework/chap3/EllipticSitnikov.txt
txt41=./homework/chap4/Perturbation.txt
txt42=./homework/chap4/LaplaceCoefficient.txt


.PHONY:all chap2 chap3 chap4 run run2 run3 run4 py2 py3 py4

# all the executable files, divided into chapters
all:chap2 chap3 chap4

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

## chapter 4
chap4:$(bin41)

$(bin41):$(files4)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/Perturbation.c $(FLAGS)

$(bin42):$(files4)
	gcc -o $@ ./src/LaplaceCoefficient.c $(FLAGS)

# run all the executable files and write the output into text files
run:run2 run3 run4

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

## chapter 4
run4:$(txt41) $(txt42)

$(txt41):$(bin41)
	$< > $@

$(txt42):$(bin42)
	$< > $@

py4:py41

py41:$(txt41)
	cd homework/chap4/;python plotperturbation.py

rebuild:
	rm -f $(BIN);make all

test:
	echo $(files)
