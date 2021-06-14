#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct linked_list_int {
    int value;
    struct linked_list_int * next;
} LinkedListInt;

LinkedListInt * initialise(int value) {
    LinkedListInt * new_linked_list = (LinkedListInt*) malloc(sizeof(LinkedListInt));
    new_linked_list->value = value;
    new_linked_list->next = NULL;
    return new_linked_list;
}

void destroy(LinkedListInt * list) {
    if (list->next != NULL) {
        destroy(list->next);
    }
    printf("Freeing element with value %d.\n", list->value);
    free(list);
}

// Actually, it's append.
void push(LinkedListInt * list, int value) {
    LinkedListInt * element_to_append = list;
    while (element_to_append->next != NULL) {
        element_to_append = element_to_append->next;
    }
    printf("Value of element_to_append: %d.\n", element_to_append->value);
    element_to_append->next = (LinkedListInt*) malloc(sizeof(LinkedListInt));
    element_to_append->next->value = value;
}

int pop(LinkedListInt * list) {
    LinkedListInt * previous_element = NULL;
    LinkedListInt * element_to_pop = list;
    while (element_to_pop->next != NULL) {
        previous_element = element_to_pop;
        element_to_pop = element_to_pop->next;
    }
    int return_value = element_to_pop->value;
    printf("Value of element to pop: %d.\n", return_value);
    if (previous_element != NULL) {
        previous_element->next = NULL;
    }
    free(element_to_pop);
    return return_value;
}

void loop_and_print(LinkedListInt * list) {
    LinkedListInt * next_value = list;
    do {
        printf("%d\n", next_value->value);
        next_value = next_value->next;
    } while (next_value != NULL);
}

int main() {
    LinkedListInt * a = initialise(1);
    push(a, 2);
    push(a, 3);
    push(a, 4);
    pop(a);
    loop_and_print(a);
    destroy(a);
}