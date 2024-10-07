#include "cell.h"

/*===============  CELLULE  ===============*/

cell* CELL_create(int value) {
    cell *new_cell = (cell*)malloc(sizeof(cell)); /* Je réserve un espace mémoire de la taille "cell" 
                                                     et je renvoie un pointeur sur une cellule.*/
    if (new_cell) { // Si new_cell est bien créé (c'est pareil que mettre if (new_list != NULL))
        // Je dois bien vérifié que new_cell est créée car dans le cas contraire j'aurais des segfault lors de l'affectaction des variables.
        new_cell->value = value;
        new_cell->next = NULL;  // Toujours initialisé les pointeurs à NULL, ça évite d'avoir des erreurs plus tard.
    }
    return new_cell;
}

int CELL_count(cell *cell) {
    if (cell) {
        return 1 + CELL_count(cell->next);
    }
    else return 0;
}

void CELL_free(cell *cell) {
    if (cell) {
        CELL_free(cell->next);
    }
    free(cell);
}