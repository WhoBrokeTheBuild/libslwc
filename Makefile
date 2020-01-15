
SOURCES = $(wildcard source/*.c)
OBJECTS = $(patsubst source/%.c,source/%.o,$(SOURCES))
TARGET  = libslwc.a

CFLAGS  = -g -Wall -nostdlib -std=c11 -Iinclude
LDFLAGS = -L.
LDLIBS  =

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(AR) rcs $@ $^
	ranlib $@
	
source/%.o: source/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

TEST_SOURCES = $(wildcard test/*.c)
TEST_BINARIES = $(patsubst test/%.c,test/%.x86_64,$(TEST_SOURCES))

tests: $(TEST_BINARIES)

test/%.x86_64: test/%.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS) -lslwc
