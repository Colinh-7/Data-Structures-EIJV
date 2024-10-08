#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>

/*===============  STRUCTURES  ===============*/

/**
 * @brief Structure d'une cellule.
 */
typedef struct cell {
    int value;
    struct cell *next;
} cell;

/*===============  CELLULE  ===============*/

/**
 * @brief Créer une nouvelle cellule composée d'une valeur.
 * @param value : la valeur que l'on veut mettre dans la cellule
 * @return Renvoie la cellule créée, NULL sinon.
 */
cell* CELL_create(int value);

/**
 * @brief Compte le nombre de cellule chainée.
 * @param cell : la première cellule de la liste.
 */
int CELL_count(cell *cell);

/**
 * @brief Libére la mémoire de toutes les cellules chaînées.
 */
void CELL_free(cell *cell);

#endif