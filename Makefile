CC := cc

CFLAGS := -Wall -Wextra -Werror

CLIBS := -ljansson -lcurl

CFILES :=				\
	src/*.c				\
	src/cli/*.c			\
	src/config/*.c		\

TARGET := bin/apt-local

all: $(TARGET)

$(TARGET): $(CFILES)
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@ $(CLIBS)

clean:
	rm -rf bin/