CC := cc

CFLAGS := -Wall -Wextra -Werror

CFILES := src/*.c src/installer/*.c

TARGET := bin/apt-local

all: $(TARGET)

$(TARGET): $(CFILES)
	mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf bin/