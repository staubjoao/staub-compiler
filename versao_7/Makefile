SCANNER := lex
SCANNER_PARAMS := dictionary.l
PARSER := yacc
PARSER_PARAMS := -d parser.y

all: compile translate

compile:
		$(SCANNER) $(SCANNER_PARAMS)
		$(PARSER) $(PARSER_PARAMS)
		gcc -o glf y.tab.c -ll

run: 	glf
		clear
		compile
		translate

debug:	PARSER_PARAMS += -Wcounterexamples -Wconflicts-sr -Wconflicts-rr -Wcex -Wother
debug: 	all

translate: glf
		./glf arquivos/principal.jsc

clear:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm glf