files=$(wildcard ./include/* ./src/* ./lib/*)
all:$(files)
	gcc -o ./bin/evaluate ./src/OrbitalEle_CoorVol_Trans.c ./src/OrbitEvaluation.c -lNR -lm -L ./lib -I ./include -std=c11 
	gcc -o ./bin/transform ./src/OrbitalEle_CoorVol_Trans.c ./src/transform.c -lm -I ./include -std=c11
	
run:
	rm ./*.txt; \
	./bin/transform > ./transform.txt; \
	./bin/evaluate > ./evaluate.txt

tar:
	rm ./*.tar.gz; \
	tar zcvf 天体力学第一章上机作业131210004卢旭.tar.gz ./*
