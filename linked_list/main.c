#include <stdio.h>
#include "linked_list.h"

int main() {
    node_t *list = NULL;
    init(&list);
    push(list, 3);
    push(list, 5);
    print(list);
    printf("Popped: %d\n", pop(list));
    print(list);
    pop(list);
    pop(list);
    print(list);
    free_node(list);
}
