#ifndef STACK_H
#define STACK_H

#include "cell.h"

/*===============  STRUCTURES  ===============*/

/**
 * @brief Structure de la pile.
 */
typedef struct stack {
    cell *head;
}stack;

/*===============  PILE  ===============*/

/**
 * @brief Initialise une pile.
 * @return Renvoie la pile, NULL sinon.
 */
stack* STACK_init();

/**
 * @brief Teste si une pile est vide.
 * @param stack : la pile que l'on veut tester.
 * @return Renvoie 1 si la pile est vide, 0 sinon.
 */
int STACK_isEmpty(stack *stack);

/**
 * @brief Empile une valeur dans la pile.
 * @param stack : la pile.
 * @param value : la valeur à empiler.
 */
void STACK_stack(stack *stack, int value);

/**
 * @brief Dépiler la pile.
 * @param stack : la pile.
 * @return Renvoie la valeur dépilée.
 */
int STACK_unstack(stack *stack);

/**
 * @brief Affiche la pile.
 * @param stack : la pile à afficher.
 */
void STACK_print(stack *stack);

/**
 * @brief Taille de la pile.
 * @param stack : la pile.
 * @return Renvoie la taille de la pile.
 */
int STACK_getLenght(stack *stack);

/**
 * @brief Supprime et libère la mémoire de la pile.
 * @param stack : la pile à supprimer.
 */
void STACK_free(stack *stack);

#endif