CFLAGS 		= -g -std=c89 -pedantic -Wno-all
#-Wall -Wextra -Wpedantic -Wconversion
LIBRARY_DEPS = -lpthread -lrt
COMMON_DEPS 	= src/*.h Makefile
COMMON_BUILD_DEP = build/BinSemaphores.o build/taxi.o build/source.o build/shmUtils.o
BUILD_DIR = build
BIN_DIR = bin
MKDIR_P = mkdir -p

all: dirstruct bin/master

dirstruct: $(BUILD_DIR) $(BIN_DIR)

$(BUILD_DIR):
	$(MKDIR_P) $(BUILD_DIR)

$(BIN_DIR):
	$(MKDIR_P) $(BIN_DIR)

build/%.o: src/%.c $(COMMON_DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

bin/master: build/master.o  $(COMMON_DEPS)
	$(CC) -o bin/master build/master.o $(COMMON_BUILD_DEPS)  $(LIBRARY_DEPS)

clean:
	$(RM) -r -d build/
	$(RM) -r -d bin/

run: all
	./bin/master