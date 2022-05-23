#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#define MAX_HASH_SIZE 1000
typedef struct hash_table HASH_TABLE;
typedef struct entry ENTRY;

struct entry {
    char *key;
    char *value;
    ENTRY *next;
};

struct hash_table {
    ENTRY *entry[MAX_HASH_SIZE];
};

static unsigned int makeHashIndex(const char *key){
    unsigned int result = 0;

    char temp = *key;
    while (temp != '\0') {
        result += temp;
        temp = *(++key);
    }
    result = result % MAX_HASH_SIZE;
    return result;
}

static ENTRY* allocateHashEntry(const char *key, const char *value) {
    ENTRY *temp;

    if((temp = (ENTRY*)malloc(sizeof(ENTRY))) == NULL) {
        puts("Cannot allocate hash entry !!");
        return NULL;
    }

    if((temp->key=(char*)malloc(strlen(key)+1)) == NULL) {
        puts("Cannot allocate hash key!!!");
        free(temp);
        return NULL;
    }

    if((temp->value=(char*)malloc(strlen(value)+1)) == NULL) {
        puts("Cannot allocate hash data!!!");
        free(temp);
        free(temp -> key);
        return NULL;
    }
    return temp;
}

static void copyHashEntry(ENTRY* entry, const char *key, const char *value) {
    strncpy(entry->key, key, strlen(key) + 1);
    strncpy(entry->value, value, strlen(value)+1);
    entry->next = NULL;
}

static ENTRY* makeHashEntry(const char *key, const char *value) {
    ENTRY *temp = allocateHashEntry(key, value);

    if(temp == NULL) {
        puts("Cannot allocate hasy entry!!!");
        return NULL;
    }
    copyHashEntry(temp, key, value);
    return temp;
}

static void insertEntry(HASH_TABLE *hashTable, const int index, ENTRY *entry) {
    ENTRY *temp = hashTable->entry[index];
    if (temp == NULL) {
        hashTable->entry[index] = entry;
        return;
    }

    while(temp->next != NULL) {
        temp = temp -> next;
    }
    temp->next = entry;
    return;
}

HASH_TABLE *createHashTable(void) {
    HASH_TABLE *temp;

    if((temp=(HASH_TABLE*)malloc(sizeof(HASH_TABLE))) == NULL) {
        puts("Cannot create hash table!!!");
        return NULL;
    }

    memset(temp->entry, 0, MAX_HASH_SIZE* sizeof(ENTRY*));
    return temp;
}

int insertHashEntry(HASH_TABLE *hashTable, const char *key, const char *value) {
    unsigned int index;
    ENTRY *entry;
    if((entry= makeHashEntry(key, value)) == NULL) {
        puts("Cannot make hash entry!!!");
        return -1;
    }

    index = makeHashIndex(entry->key);
    insertEntry(hashTable, index, entry);
    return index;
}

ENTRY *findHashEntry(HASH_TABLE *hash, const char *key) {
    unsigned int index = makeHashIndex(key);
    ENTRY *temp = hash->entry[index];
    while(temp != NULL) {
        temp = temp->next;
    }
    return hash->entry[index];
}

ENTRY *getHashEntry(HASH_TABLE *hash, const char *key) {
    unsigned int index = makeHashIndex(key);
    ENTRY *temp = hash->entry[index];

    if(temp == NULL) {
        return temp;
    }

    hash->entry[index] = temp->next;
    temp->next = NULL;
    return temp;
}

void freeHashEntry(ENTRY *entry) {
    if(entry == NULL)
        return;
    if(entry->key != NULL)
        free(entry->key);
    if(entry->value != NULL)
        free(entry->value);
    free(entry);
    return;
}


/* Test Build Code */
static inline void HelloPrint() {
    puts("**********  This Program is Hash Example  **********");
}

static inline int GlibHelloPrint() {
    GString *my_string = g_string_new("Hash Table Example 01\n");
    g_print(my_string->str, my_string->len);
    g_string_free(my_string, TRUE);
    return 1;
}

int main() {
    HelloPrint();
    GlibHelloPrint();

    ENTRY *entry;
    HASH_TABLE *hash = createHashTable();

    insertHashEntry(hash, "name", "Park Ji Woo");
    insertHashEntry(hash, "name", "Blue");
    insertHashEntry(hash, "name","Song Hyun A");
    insertHashEntry(hash, "name", "Kim Gyu Hyun");
    insertHashEntry(hash, "name", "Lee Dae Kwan");
    insertHashEntry(hash, "name", "yang Woo Wyoung");

    entry = findHashEntry(hash, "name");
    if(entry != NULL) {
        printf("The value : %s\n", entry -> value);
    }

    entry = getHashEntry(hash, "name");
    while(entry != NULL) {
        printf("The value : %s\n", entry -> value);
        freeHashEntry(entry);
        entry = getHashEntry(hash, "name");
    }

    entry = getHashEntry(hash, "address");
    if(entry != NULL) {
        printf("The value : %s\n", entry -> value);
        freeHashEntry(entry);
    }
    return EXIT_SUCCESS;
}
