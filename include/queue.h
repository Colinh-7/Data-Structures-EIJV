#ifndef QUEUE_H
#define QUEUE_H

#include "cell.h"

/*===============  STRUCTURE  ===============*/

/**
 * @brief Structure d'une file.
 */
typedef struct queue {
    cell *head;
} queue;

/*===============  FILE  ===============*/

/**
 * @brief Initialise une file.
 * @return Renvoie la file initialisée, NULL sinon.
 */
queue* QUEUE_init();

/**
 * @brief Test si la file est vide.
 * @param queue : la file.
 * @return Renvoie 1 si la file est vide, 0 sinon.
 */
int QUEUE_isEmpty(queue *queue);

/**
 * @brief Enfiler en fin de file.
 * @param queue : la file
 * @param value : la valeur à enfiler.
 */
void QUEUE_enqueue(queue *queue, int value);

/**
 * @brief Défile la file.
 * @param queue : la file
 * @return Renvoie la valeur en tête de file.
 */
int QUEUE_dequeue(queue *queue);

/**
 * @brief Affiche la file.
 * @param queue : la file à afficher.
 */
void QUEUE_print(queue *queue);

/**
 * @brief Supprime et libère la mémoire d'une file.
 * @param queue : la file à supprimer.
 */
void QUEUE_free(queue *queue);

#endif