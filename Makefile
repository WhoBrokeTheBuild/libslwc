
SOURCES = $(wildcard source/*.c)
OBJECTS = $(patsubst source/%.c,source/%.o,$(SOURCES))
TARGET  = libslwc.a

CFLAGS  = -g -Wall -nostdlib -fno-builtin -std=c11 -Iinclude
LDFLAGS = -L.
LDLIBS  =

.PHONY: all
all: $(TARGET) tests

$(TARGET): $(OBJECTS)
	$(AR) rcs $@ $^
	ranlib $@
	
source/%.o: source/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

TEST_SOURCES = $(wildcard test/*.c)
TEST_BINARIES = $(patsubst test/%.c,test/%.x86_64,$(TEST_SOURCES))

.PHONY: tests
tests: $(TEST_BINARIES)

test/%.x86_64: test/%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS) -lslwc

.PHONY:
clean:
	rm $(OBJECTS) $(TARGET) $(TEST_BINARIES)