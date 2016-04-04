# directories
NR_DIR=../MyRecipes
NR_INC_DIR=$(NR_DIR)/include
NR_LIB_DIR=$(NR_DIR)/lib
# flags
CFLAGS=-Wall -g -std=c11
LFLAGS=-lm -lNR -L $(NR_LIB_DIR)
IFLAGS=-I ./include -I $(NR_INC_DIR)
FLAGS=$(CFLAGS) $(LFLAGS) $(IFLAGS)
# source files
files=$(wildcard ./include/*) ./src/OrbitalEle_CoorVol_Trans.c
files1=$(files) \
	./src/OrbitEvaluation.c \
	./src/transform.c
files2=$(files) \
	./src/CircularRTB.c \
	./src/SitnikovCircular.c \
	./src/SitnikovEllipse.c
# executable files
exe11=./bin/evaluate
exe12=./bin/transform
exe21=./bin/circularRTB
exe22=./bin/SitnikovCircular
exe23=./bin/SitnikovEllipse
# text files
txt11=./homework/chap1/evaluate.txt
txt12=./homework/chap1/transform.txt
txt21=./homework/chap2/circularRTB.txt
txt22=./homework/chap2/SitnikovCircular.txt
txt23=./homework/chap2/SitnikovEllipse.txt


.PHONY:all chap1 chap2 run run1 run2 py1 py2

# all the executable files, divided into chapters
all:chap1 chap2

## chapter 1
chap1:$(exe11) $(exe12)

$(exe11):$(files1)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c $(FLAGS)
$(exe12):$(files1)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/transform.c $(FLAGS)

## chapter 2
chap2:$(exe21) $(exe22) $(exe23)

$(exe21):$(files2)
	gcc -o $@ ./src/CircularRTB.c $(FLAGS)

$(exe22):$(files2)
	gcc -o $@ ./src/SitnikovCircular.c $(FLAGS)

$(exe23):$(files2)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/SitnikovEllipse.c $(FLAGS)

# run all the executable files and write the output into text files
run:run1 run2

## chapter 1
run1:$(txt11) $(txt12) py1

$(txt11):$(exe11)
	$< > $@

$(txt12):$(exe12)
	$< > $@

py1:$(txt11) $(txt12)


## chapter 2
run2:$(txt21) $(txt22) $(txt23) py2

$(txt21):$(exe21)
	$< > $@

$(txt22):$(exe22)
	$< > $@

$(txt23):$(exe23)
	$< > $@

py2:$(txt21) $(txt22) $(txt23)
	cd homework/chap2/;python orbitplot.py;python phasegraph.py;python plotcontour.py

test:
	echo $(files)
