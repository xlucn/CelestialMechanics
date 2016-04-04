NR_DIR=../MyRecipes
NR_INC_DIR=$(NR_DIR)/include
NR_LIB_DIR=$(NR_DIR)/lib

CFLAGS=-Wall -g -std=c11
LFLAGS=-lm -lNR -L $(NR_LIB_DIR)
IFLAGS=-I ./include -I $(NR_INC_DIR)

files=$(wildcard ./include/*)
files1=$(files) ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c ./src/transform.c
files2=$(files) ./src/CircularRTB.c ./src/Sitnikov.c

all:1 2

1:./bin/evaluate ./bin/transform

./bin/evaluate:$(files1)
	gcc $(CFLAGS) $(IFLAGS) -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c $(LFLAGS)

./bin/transform:$(files1)
	gcc $(CFLAGS) $(IFLAGS) -o $@ ./src/OrbitalEle_CoorVol_Trans.c ./src/transform.c $(LFLAGS)

2:./bin/circularRTB ./bin/Sitnikov

./bin/circularRTB:$(files2)
	gcc $(CFLAGS) $(IFLAGS) -o $@ ./src/CircularRTB.c $(LFLAGS)

./bin/Sitnikov:$(files2)
	gcc $(CFLAGS) $(IFLAGS) -o $@ ./src/Sitnikov.c $(LFLAGS)

test:
	echo $(files)
