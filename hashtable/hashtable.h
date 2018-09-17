// Hashtable


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

ht_t* new_hashtable();

void insert(ht_t *ht, char *key, char *value);

char* search(ht_t *ht, char *key);

void delete_bucket(ht_t *ht, char *key);

void resize(ht_t *ht);

void print(ht_t *ht);
