#ifndef DLL_H /* DLL pour "Doubly Linked List "*/
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

/*===============  STRUCTURES  ===============*/

/**
 * @brief Cellule doublement chainée.
 */
typedef struct cell2 {
    int value;
    struct cell2 *prev, *next;
}dlc; 

/**
 * @brief Liste doublement chainée.
 */
typedef struct list2 {
    dlc *head;
}dll;

/*===============  CELLULE  ===============*/

/**
 * @brief Créer une nouvelle cellule composée d'une valeur.
 * @param value : la valeur que l'on veut mettre dans la cellule
 * @return Renvoie la cellule créée, NULL sinon.
 */
dlc* DLC_create(int value);

/**
 * @brief Compte le nombre de cellule doublement chainée.
 * @param cell : la première cellule de la liste.
 */
int DLC_count(dlc *cell);

/**
 * @brief Libére la mémoire de toutes les cellules doublement chaînées.
 */
void DLC_free(dlc *cell);

/*===============  LISTE  ===============*/

/**
 * @brief Initialise une liste.
 * @return Renvoie la liste créée, NULL sinon.
 */
dll* DLL_init();

/**
 * @brief Ajoute un élément en tête de liste.
 * @param list : la liste dans laquelle on ajoute en tête.
 * @param value : la valeur ajoutée.
 */
void DLL_addHead(dll *list, int value);

/**
 * @brief Supprime un élément d'une liste.
 * @param list : la liste dans laquelle je veux supprimer.
 * @param value : la valeur que je veux enlever de la liste.
 */
void DLL_delete(dll *list, int value);

/**
 * @brief Affiche le contenu d'une liste.
 * @param list : la liste à afficher.
 */
void DLL_print(dll *list);

/**
 * @brief Renvoie la taille de la liste.
 */
int DLL_getLenght(dll *list);

/**
 * @brief Renvoie si une liste est vide ou non.
 * @return Renvoie 1 (True) si la liste est vide 0 (False) sinon. 
 */
int DLL_isEmpty(dll *list);

/**
 * @brief Ajoute un élément en fin de liste.
 * @param list : la liste de base.
 * @param value : la valeur ajoutée.
 */
void DLL_addTail(dll *list, int value);

/**
 * @brief Ajoute un élément à une place spécifique dans une liste.
 * @param list : la liste de base.
 * @param index : l'indice où on ajoute l'élément dans la liste.
 * @param value : la valeur ajoutée.
 * @warning Si l'indice est trop haut, l'élément est ajouté en fin de liste, s'il est trop bas il est ajouté au début.
 */
void DLL_addIndex(dll *list, int index, int value);

/**
 * @brief Supprime un élément en tête de liste.
 */
void DLL_deleteHead(dll *list);

/**
 * @brief Trouve un élément dans une liste.
 * @param list : la liste
 * @param value : la valeur recherchée.
 * @return Renvoie la cellule recherchée.
 */
dlc* DLL_findElement(dll *list, int value);

/**
 * @brief Supprime et libére toute la mémoire d'une liste (cellules incluses).
 */
void DLL_free(dll *list);



#endif