CC=g++
MAIN=main.o
TEST=test.o
SHELL = /bin/bash
EXE=main
SOURCEDIR=src
SRCFILES=$(wildcard $(SOURCEDIR)/*.cpp)
SRCOBJS=$(patsubst %.cpp,%.o,$(SRCFILES))
DBGOBJS=$(patsubst %.cpp,%.dbg,$(SRCFILES))
# OBJ=$(addprefix $(SOURCEDIR)/, )

all: $(MAIN) $(SRCOBJS)
	$(CC) $(MAIN) $(SRCOBJS) -o $(EXE) -lm


test: $(TEST) $(SRCOBJS)
	$(CC) $(TEST) $(SRCOBJS) -o $(EXE) -lm
.PHONY: test

dtest: test.dbg $(DBGOBJS)
	$(CC) -D DEBUG $< $(DBGOBJS) -o $(EXE)
.PHONY: dtest

%.o: %.cpp
	@$(CC) -c $< -o $@
	
%.dbg: %.cpp
	@$(CC) -D DEBUG -g -c $< -o $@


debug: main.dbg $(DBGOBJS)
	$(CC) $< $(DBGOBJS) -o $(EXE)
.PHONY: debug

clean:
	-rm -f $(SOURCEDIR)/*.o $(SOURCEDIR)/*.dbg $(EXE) *.o *.dbg

.PHONY: clean