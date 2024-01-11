# Katalog źródeł
SRCDIR = src

# Katalog docelowy
BINDIR = bin

# Pliki źródłowe
SRC = $(wildcard $(SRCDIR)/*.c)

# Kompilator
CC = gcc

# Flagi kompilatora
CFLAGS = -Wall -g

# Nazwa programu wynikowego
TARGET = $(BINDIR)/run

# Reguła domyślna - budowanie programu
all: $(TARGET)

# Reguła budowania programu
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Stworzenie katalogu docelowego, jeśli nie istnieje
$(shell mkdir -p $(BINDIR))

# Reguła czyszczenia plików tymczasowych i programu
clean:
	rm -rf $(BINDIR)/run
