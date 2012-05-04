CFLAGS = -lmongoclient -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options

all: titlematcher

HEADERS = title.h db.h entitymatcher.h titlematcher.h utils/random.h
SRC = db.cpp entitymatcher.cpp titlematcher.cpp example.cpp

clean:
	rm -f titlematcher gdb

titlematcher: $(SRC) $(HEADERS)
	sudo g++ $(SRC) $(CFLAGS) -o $@ 

gdb: $(SRC) $(HEADERS)
	sudo g++ -ggdb $(SRC) $(CFLAGS) -o $@ 