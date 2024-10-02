# Nom de l'exécutable
TARGET = main

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Iinclude

# Dossier des fichiers objets
OBJ_DIR = obj

# Fichiers sources
SRC_MAIN = main.c
SRC_INCLUDE = $(wildcard include/*.c)
SRC = $(SRC_MAIN) $(SRC_INCLUDE)

# Fichiers objets correspondants
OBJ = $(OBJ_DIR)/main.o $(patsubst include/%.c,$(OBJ_DIR)/%.o,$(SRC_INCLUDE))

# Règle par défaut : compilation de l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

# Compilation du fichier main.c
$(OBJ_DIR)/main.o: main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation des fichiers dans include/
$(OBJ_DIR)/%.o: include/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean
