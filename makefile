chapters=chap2 chap3 chap4 chap5

.PHONY:link chap

all:link chap

link:./sub.mk
	@for chap in $(chapters);\
	do \
		if [ ! -e $$chap/makefile ];\
		then \
			ln sub.mk $$chap/makefile;\
		fi;\
	done

chap:$(chapters)

$(chapters):
	make -C $@
