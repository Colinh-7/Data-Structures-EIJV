#include "dll.h"

/*===============  CELLULE  ===============*/

dlc* DLC_create(int value) {
    dlc *new_cell = (dlc*)malloc(sizeof(dlc));
    if (new_cell) {
        new_cell->value = value;
        new_cell->next = NULL;
        new_cell->prev = NULL;
    }
    return new_cell;
}

int DLC_count(dlc *cell) {
    if (cell) return 1 + DLC_count(cell->next);
    return 0;
}

void DLC_free(dlc *cell) {
    if (cell) DLC_free(cell->next);
    free(cell);
}

/*===============  LISTE  ===============*/

dll* DLL_init() {
    dll *new_list = (dll*)malloc(sizeof(dll));
    if (new_list) {
        new_list->head = NULL;
    }
    return new_list;
}

void DLL_addHead(dll *list, int value) {
    if (list) {
        dlc *new_cell = DLC_create(value);
        if (new_cell) {
            new_cell->next = list->head;
            if (list->head) list->head->prev = new_cell;
            list->head = new_cell;
        }
    }
}

void DLL_delete(dll *list, int value) {
    if (list) {
        dlc *current = list->head;

        while(current && current->value != value) current = current->next;

        if (current) {
            if (current->prev) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            else {
                list->head = current->next;
                list->head->prev = NULL;
            }
            free(current);
        }
    }
}

void DLL_print(dll *list) {
    if (list) {
        for(dlc *c = list->head; c; c=c->next) {
            printf("%d, ", c->value);
        }
        putchar('\n');
    }
}

int DLL_getLenght(dll *list) {
    if (list) return DLC_count(list->head);
    return 0;
}

int DLL_isEmpty(dll *list) {
    if (list) {
        return list->head == NULL;
    }
    return 1;
}

void DLL_addTail(dll *list, int value) {
    if (list) {
        if (DLL_isEmpty(list)) DLL_addHead(list, value);
        else {
            dlc *current = list->head;
            while (current->next) current = current->next;
            dlc *new_cell = DLC_create(value);
            if (new_cell) {
                current->next = new_cell;
                new_cell->prev = current;
            }
        }
    }
}

void DLL_addIndex(dll *list, int index, int value) {

}

void DLL_deleteHead(dll *list) {

}

dlc* DLL_findElement(dll *list, int value) {

}

void DLL_free(dll *list) {
    if (list) {
        DLC_free(list->head);
    }
    free(list);
}