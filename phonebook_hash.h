#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* optimal version */
typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_DETAIL *dNext;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} details;

typedef struct __PHONE_BOOK_HASH_TABLE {
	unsigned int tableSize; /* Number of the hash table */
	entry **hashTable;	/* Ponter to hashTable */
} hashTable;

hashTable *createHashTable(int tableSize);
int append_hash(char *line, hashTable *e);
entry *findName_hash(char *line, hashTable *ht);
unsigned int hash_func1(char *line, int tableSize);
#endif
