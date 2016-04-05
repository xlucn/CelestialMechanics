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
files2=$(files) \
	./src/OrbitEvaluation.c \
	./src/transform.c
files3=$(files) \
	./src/CircularRTB.c \
	./src/SitnikovCircular.c \
	./src/SitnikovEllipse.c
# executable files
exe21=./bin/evaluate
exe22=./bin/transform
exe31=./bin/circularRTB
exe32=./bin/SitnikovCircular
exe33=./bin/SitnikovEllipse
# text files
txt21=./homework/chap2/evaluate.txt
txt22=./homework/chap2/transform.txt
txt31=./homework/chap3/circularRTB.txt
txt32=./homework/chap3/SitnikovCircular.txt
txt33=./homework/chap3/SitnikovEllipse.txt


.PHONY:all chap2 chap3 run run2 run3 py2 py3

# all the executable files, divided into chapters
all:chap2 chap3

## chapter 2
chap2:$(exe21) $(exe22)

$(exe21):$(files2)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c $(FLAGS)
$(exe22):$(files2)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/transform.c $(FLAGS)

## chapter 3
chap3:$(exe31) $(exe32) $(exe33)

$(exe31):$(files3)
	gcc -o $@ ./src/CircularRTB.c $(FLAGS)

$(exe32):$(files3)
	gcc -o $@ ./src/SitnikovCircular.c $(FLAGS)

$(exe33):$(files3)
	gcc -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/SitnikovEllipse.c $(FLAGS)

# run all the executable files and write the output into text files
run:run2 run3

## chapter 1
run2:$(txt21) $(txt22) py2

$(txt21):$(exe21)
	$< > $@

$(txt22):$(exe22)
	$< > $@

py2:$(txt21) $(txt22)
	cd homework/chap2/;python plotorbit.py

## chapter 2
run3:$(txt31) $(txt32) $(txt33) py3

$(txt31):$(exe31)
	$< > $@

$(txt32):$(exe32)
	$< > $@

$(txt33):$(exe33)
	$< > $@

py3:$(txt31) $(txt32) $(txt33)
	cd homework/chap3/;python orbitplot.py;python phasediagram.py;python plotcontour.py

test:
	echo $(files)
