SCANNER := lex
SCANNER_PARAMS := dic.l
PARSER := yacc
PARSER_PARAMS := -d sintatico.y

all: compile translate

compile:
		$(SCANNER) $(SCANNER_PARAMS)
		$(PARSER) $(PARSER_PARAMS)
		g++ -o glf y.tab.c -ll

run: 	glf
		clear
		compile
		translate

debug:	PARSER_PARAMS += -Wcounterexamples -Wconflicts-sr -Wconflicts-rr -Wcex -Wother
debug: 	all

translate: glf
		./glf exemplo.jsc circulo.jsc

clear:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm glf