#include <stdio.h>
#include "hashtable.h"

int main(){
     ht_t *hashtable = new_hashtable();
     insert(hashtable, "key", "value");
     insert(hashtable, "A", "ABC");
     print(hashtable);
}
