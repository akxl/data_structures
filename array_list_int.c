#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct array_list_int {
    size_t size;
    size_t used_capacity;
    int * values;
    void (*push)(struct array_list_int * self, int new_value);
    int (*pop)(struct array_list_int * self);
};

void push(struct array_list_int * self, int new_value) {
    int current_idx = self->used_capacity;
    if (current_idx < self->size - 1) {
        self->values[current_idx] = new_value;
        self->used_capacity = current_idx + 1;
    } else {
        int new_size = self->size + 10;
        self->values = (int *) realloc(self->values, new_size * sizeof(int));
        self->size = new_size;
        self->values[current_idx] = new_value;
        self->used_capacity = current_idx + 1;
    }
}

int pop(struct array_list_int * self) {
    int current_idx = self->used_capacity;
    if (current_idx > 0) {
        int new_idx = current_idx - 1;
        int returned_elem = self->values[new_idx];
        self->used_capacity = new_idx;
        return returned_elem;
    } else {
        return INT_MIN;
    }
}

struct array_list_int * initialise() {
    struct array_list_int * result = (struct array_list_int *) malloc(sizeof(struct array_list_int));
    
    result->size = 10;
    result->used_capacity = 0;
    result->values = (int*) malloc(10 * sizeof(int));
    result->push = push;
    result->pop = pop;
    return result;
}

int main() {
    
    struct array_list_int * aaa = initialise();

    unsigned int i;
    for(i = 0; i < 30; i++) {
        aaa->push(aaa, i);
    }

    for(i = 0; i < 30; i++) {
        printf("%d\n", aaa->values[i]);
    }

    free(aaa->values);
    free(aaa);
}