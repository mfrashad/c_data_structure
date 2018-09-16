// Hashtable

#define CAPACITY 100

typedef struct {
    char *key;
    char *value;
} bucket_t;

typedef struct {
    int size;
    int capacity;
    bucket_t **buckets;
} ht_t;

int hash(ht_t *ht, char *key);

void init(ht_t *ht);

void insert(ht_t *ht, char *key, char *value);

void search(ht_t *ht, char *key);

void remove(ht_t *ht, char *key);

void resize(ht_t *ht);
