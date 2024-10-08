#include "queue.h"

/*===============  FILE  ===============*/

queue* QUEUE_init() {
    queue *new = (queue*)malloc(sizeof(queue));
    if (new) new->head = NULL;
    return new;
}

int QUEUE_isEmpty(queue *queue) {
    if (queue) return queue->head == NULL;
    return 1;
}

void QUEUE_enqueue(queue *queue, int value) {
    if (queue) {
        if (QUEUE_isEmpty(queue)) queue->head = CELL_create(value);
        else {
            cell *tmp;
            for (tmp = queue->head; tmp && tmp->next; tmp=tmp->next);
            tmp->next = CELL_create(value);
        }
    }
}

int QUEUE_dequeue(queue *queue) {
    int value = -1;
    if (!QUEUE_isEmpty(queue)) {
        cell *save = queue->head;
        value = save->value;
        queue->head = save->next;
        free(save);
    }
    return value;
}

void QUEUE_print(queue *queue) {
    if (!QUEUE_isEmpty(queue)) {
        for (cell *current=queue->head; current; current=current->next) {
            printf("%d -> ", current->value);
        }
        putchar('\n');
    }
}

void QUEUE_free(queue *queue) {
    if (queue) CELL_free(queue->head);
    free(queue);
}