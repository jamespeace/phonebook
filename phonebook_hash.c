#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* create new hash table */
hashTable *createHashTable(int tableSize)
{
	hashTable *ht;
	int i;

	if (tableSize < 0) {
		perror("error: tableSize < 0\n");
		return NULL;
	}

	/* malloc the table */
	if ((ht = (hashTable *) malloc(sizeof(hashTable))) == NULL) {
		perror("error: can't malloc hashTable\n");
		return NULL;
	}
	
	/* Allocate the array of table */
	if ((ht->hashTable = (entry **) malloc(sizeof(entry *) * tableSize)) == NULL) {
		perror("error: can't allocate the array of table\n");
		return NULL;
	}

	/* Initalize the table header */
	for (i = 0; i < tableSize; i++)
		ht->hashTable[i] = NULL;

	ht->tableSize = tableSize;

	return ht;
}

/* find name in the hash table */
entry *findName_hash(char *lastname, hashTable *ht)
{
	int index;
	entry *e;

	index = hash_func1(lastname, ht->tableSize);
	e = ht->hashTable[index];
	while (e != NULL) {
		if (strcmp(lastname, e->lastName) == 0)
			return e;
		e = e->pNext;
	}
	return NULL;
}
/* Insert a new entry into the hash table */
int append_hash(char *line, hashTable *ht)
{
	unsigned int hv; /* hash value */
	entry *e;
	
	hv = hash_func1(line, ht->tableSize);

	/* initial an entry */
	if ((e = (entry *) malloc(sizeof(entry))) == NULL) {
		perror("error: can't allocate a new entry\n");
		return 1;
	}
	strcpy(e->lastName, line);	

	/* Insert the entry into table */
	e->pNext = ht->hashTable[hv];
	ht->hashTable[hv] = e;

	return 0;
}
/* hash function : summation of array */
unsigned int hash_func1(char *line, int tableSize)
{
	unsigned int hashVal = 0;
	while (*line != '\0')
		hashVal += *line++;

	return hashVal / tableSize;
}
