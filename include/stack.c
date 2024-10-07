#include "stack.h"

/*===============  PILE  ===============*/

stack* STACK_init() {
    stack *new = (stack*)malloc(sizeof(stack));
    if (new) new->head = NULL;
    return new;
}

int STACK_isEmpty(stack *stack) {
    if (stack) {
        return stack->head == NULL;
    }
    return 1;
}

void STACK_stack(stack *stack, int value) {
    if (stack) {
        cell *new_cell = CELL_create(value);
        if (new_cell) {
            new_cell->next = stack->head;
            stack->head = new_cell;
        }
    }
}

int STACK_unstack(stack *stack) {
    if (!STACK_isEmpty(stack)) {
        cell *save = stack->head;
        int value = save->value;
        stack->head = save->next;
        free(save);
        return value;
    }
    return -1;
}

void STACK_print(stack *stack) {
    if(!STACK_isEmpty(stack)) {
        for(cell *c=stack->head; c; c=c->next) {
            printf("%d -> ", c->value);
        }
        putchar('\n');
    }
}

int STACK_lenght(stack *stack) {
    return CELL_count(stack->head);
}

void STACK_free(stack *stack) {
    if (stack) {
        CELL_free(stack->head);
        free(stack);
    }
}