# My Little Makefile
FLEX=flex
BISON=bison
CC=g++
PARAM=-std=c++11
OUTPUT=myparse
all: flex yacc clang
clang:*.cpp *.h
	${CC} -o ${OUTPUT} *.cpp ${LLVMPARAM} ${PARAM} -g

yacc: parser.y
	${BISON} --defines=parser.h --output=parser.cpp --verbose --report-file=bison.out parser.y

flex: scanner.l
	${FLEX} -o scanner.cpp scanner.l
clean:
	rm parser.cpp parser.h scanner.cpp ${OUTPUT}
test: all
	./${OUTPUT} < input_example
run:
	./${OUTPUT}


