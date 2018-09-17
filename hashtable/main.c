#include <stdio.h>
#include "hashtable.h"

int main(){
     ht_t *hashtable = new_hashtable();

     printf("Inserting {\"%s\" : \"%s\"}\n", "key", "value");
     insert(&hashtable, "key", "value");

     printf("Inserting {\"%s\" : \"%s\"}\n", "A", "ABC");
     insert(&hashtable, "A", "ABC");

     printf("Inserting {\"%s\" : \"%s\"}\n", "B", "ABC");
     insert(&hashtable, "B", "ABC");
     
     printf("Inserting {\"%s\" : \"%s\"}\n", "C", "ABC");
     insert(&hashtable, "C", "ABC");

     print(hashtable);

     printf("deleting bucket with key \"%s\"\n", "key");
     delete_bucket(hashtable, "key");

     print(hashtable);
     
     printf("Search result for key \"%s\"\n", "A");
     printf("%s", search(hashtable, "A"));
}
