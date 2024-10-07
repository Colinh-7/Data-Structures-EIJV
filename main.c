#include "include/list.h"
#include "include/dll.h"
#include "include/stack.h"

int main() {
    printf("=========================\n LISTE\n=========================\n");

    list *my_list = LIST_init(); // Initialisation de ma liste

    for (int i=0; i<10; ++i) { // Remplissage de ma liste
        LIST_addTail(my_list, i);
    }

    LIST_print(my_list); // Affichage de ma liste
    LIST_delete(my_list, 5); // Je supprime la cellule contenant l'entier "5" de ma liste
    printf("Après suppression : \n");
    LIST_print(my_list);

    printf("Taille de la liste : %d.\n", LIST_getLenght(my_list));

    printf("Valeur trouvée ? %s.\n", LIST_findElement(my_list, 6) ? "Oui" : "Non" ); // On cherche la valeur "6".

    LIST_free(my_list); // Je supprime proprement ma liste

    printf("=========================\n LISTE DOUBLEMENT CHAINÉE\n=========================\n");

    dll *my_dll = DLL_init();

    for (int i=0; i<10; ++i) { 
        DLL_addHead(my_dll, i);
    }

    DLL_print(my_dll);
    printf("Taille de la liste : %d.\n", DLL_getLenght(my_dll));

    DLL_free(my_dll);

    printf("=========================\n PILE\n=========================\n");

    stack *my_stack = STACK_init();

    for (int i=0; i<10; ++i) STACK_stack(my_stack, i*10);

    printf("Dépilement de la pile : \n");

    while (my_stack->head) {
        printf("Valeur dépilée : %d. ", STACK_unstack(my_stack));
        printf("Taille de la pile : %d\n", STACK_lenght(my_stack));
    }

    STACK_print(my_stack);
    STACK_free(my_stack);
}