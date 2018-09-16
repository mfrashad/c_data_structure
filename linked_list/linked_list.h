// Linked List

typedef struct node {
    int val;
    struct node *next;
} node_t;


void init(node_t **head);

void push(node_t *head, int val);

void set(node_t *head, int index, int val);

void insert(node_t **head, int index, int val);

int pop(node_t *head);

int pop_first(node_t **head);

//void remove(node_t **head, int index);

void print(node_t *head);

void free_node(node_t *head);


