
.PHONY:link chap2 chap3 chap4 chap5

all:link chap2 chap3 chap4 chap5

link:
	@if [ ! -e chap2/makefile ];then ln sub.mk chap2/makefile;fi;\
	if [ ! -e chap3/makefile ];then ln sub.mk chap3/makefile;fi;\
	if [ ! -e chap4/makefile ];then ln sub.mk chap4/makefile;fi;\
	if [ ! -e chap5/makefile ];then ln sub.mk chap5/makefile;fi

chap2:
	@$(MAKE) -C chap2

chap3:
	@$(MAKE) -C chap3

chap4:
	@$(MAKE) -C chap4

chap5:
	@$(MAKE) -C chap5

test:
	echo $(MAKE)
