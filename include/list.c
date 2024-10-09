#include "list.h"

/*===============  LISTE  ===============*/

list* LIST_init() {
    list *new_list = (list*)malloc(sizeof(list)); 

    if (new_list) { 
        new_list->head = NULL;
    }
    return new_list;
}

void LIST_addHead(list *list, int value) {
    if (list) { // Je vérifie que ma liste ne soit pas vide -> if (list != NULL)
        cell *added_cell = CELL_create(value); // J'initialise une cellule avec la valeur donnée en paramètre

        if (added_cell) { // Si ma cellule est bien créée
            added_cell->next = list->head; // Je mets la première cellule de la liste à la suite de ma nouvelle cellule
            list->head = added_cell; // Je mets à jour la tête de la liste.
        }
    }
}

void LIST_delete(list *list, int value) {
    if (list) {
        cell *current = list->head;
        cell *prev = NULL;

        while (current && current->value != value) { // Je cherche la bonne cellule
            prev = current;
            current = current->next;
        }

        if (current) { // Si current != NULL, alors j'ai trouvé la cellule
            if (prev) { // Si prev != NULL, alors je ne suis pas sur la première cellule de la liste
                prev->next = current->next; // Je lie la cellule précédente à la cellule suivante et donc j'enlève la cellule courante.
            }
            else { // Si la première cellule doit être enlevée
                list->head = current->next; // Je mets la deuxième cellule de la liste en premier.
            }
            free(current); // Je supprime la cellule et libère la mémoire.
        }

    }
}

void LIST_print(list *list) {
    if (list) {
        for (cell *c=list->head; c /*c != NULL*/; c = c->next) { // Autre manière de parcourir une liste avec un for
            printf("%d -> ", c->value);
        }
        putchar('\n');
    }
}

int LIST_getLenght(list *list) { // Version récursive
    if (list) return CELL_count(list->head);
    else return 0;
}

int LIST_isEmpty(list *list) {
    if (list) {
        return list->head == NULL; 
        // Renvoie le résultat de la comparaison entre la tête de liste et NULL.
        // Si la liste est vide alors list->head = NULL donc (list->head == NULL) vaut 1 (True en C)
        // Si la liste est pas vide list->head = (une adresse mémoire) donc (list->head == NULL) vaut 0 (False en C)
    }
    else return 1;
}

void LIST_addTail(list *list, int value) {
    if (LIST_isEmpty(list)) LIST_addHead(list, value);
    else {
        cell *current = list->head;

        while (current->next != NULL) current = current->next; // Je vais jusqu'à la dernière cellule de ma liste

        current->next = CELL_create(value);
    }
}

void LIST_addIndex(list *list, int index, int value) {
    if (LIST_isEmpty(list) || index <= 0) LIST_addHead(list, value);
    else {
        cell *new_cell = CELL_create(value);

        cell *current = list->head;
        index--; // On vient déjà de déplacé d'une cellule donc on enlève déjà 1.

        while (current->next && index > 0) { // On parcourt "index" cellules.
            current = current->next; 
            index--;
        }
        new_cell->next = current->next;
        current->next = new_cell;
    }
}

void LIST_deleteHead(list *list) {
    if (!LIST_isEmpty(list)) {
        cell *save = list->head;
        list->head = list->head->next;
        free(save);
    }
}

cell* LIST_findElement(list *list, int value) {
    cell *found = NULL;
    if (!LIST_isEmpty(list)) {
        found = list->head;
        while (found && found->value != value) found = found->next;
    }
    return found;
}

void LIST_free(list *list) {
    if (list) {
        CELL_free(list->head);
        free(list);
    }
}