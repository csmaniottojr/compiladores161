# My Little Makefile
FLEX=flex
BISON=bison
CC=g++
PARAM=-std=gnu++11 
OUTPUT=myparse

all: flex yacc clang run

clang: *.cpp *.h
	${CC} -o ${OUTPUT} *.cpp ${LLVMPARAM} ${PARAM}

yacc: parser.y
	${BISON} --defines=parser.h --output=parser.cpp parser.y

flex: scanner.l
	${FLEX} -o scanner.cpp scanner.l 

clean:
	rm parser.cpp parser.h scanner.cpp ${OUTPUT}

test: all
	./${OUTPUT} < input_example

run:
	 ./${OUTPUT}


