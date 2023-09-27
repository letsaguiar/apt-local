CC := cc

CFLAGS := -Wall -Wextra -Werror

CFILES := src/*.c src/json/*.c

TARGET := bin/apt-local

all: $(TARGET)

$(TARGET): $(CFILES)
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf bin/