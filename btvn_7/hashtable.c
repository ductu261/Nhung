/*******************************************************************************
 * Description  : Bài tập 2: Tạo và liên kết thư viện tĩnh/động.
 * File hashtable.c: cài đặt hàm băm và các thao tác trên bảng băm.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

struct Node *buckets[TABLE_SIZE] = {NULL};

unsigned int hash(char *str) 
{
    unsigned int hashval = 0;
    for (; *str != '\0'; str++) 
    {
        hashval = *str + 31 * hashval;
    }
    return hashval % TABLE_SIZE;
}

void insert(char *name, char *phone) 
{
    unsigned int index = hash(name);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    
    if (new_node != NULL) 
    {
        strcpy(new_node->name, name);
        strcpy(new_node->phone, phone);
        
        new_node->next = buckets[index];
        buckets[index] = new_node;
    }
}

char* search(char *name) 
{
    unsigned int index = hash(name);
    struct Node *current;
    
    for (current = buckets[index]; current != NULL; current = current->next) 
    {
        if (strcmp(current->name, name) == 0) 
        {
            return current->phone; 
        }
    }
    return NULL; 
}

void delete_contact(char *name) 
{
    unsigned int index = hash(name);
    struct Node *current = buckets[index];
    struct Node *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) 
    {
        prev = current;
        current = current->next;
    }

    if (current != NULL) 
    {
        if (prev == NULL) 
        {
            buckets[index] = current->next;
        } 
        else 
        {
            prev->next = current->next;
        }
        free(current);
        printf("Da xoa lien he: %s\n", name);
    }
}

void print_table(void) 
{
    int i;
    struct Node *current;
    
    printf("\n--- Danh ba hien tai ---\n");
    for (i = 0; i < TABLE_SIZE; i++) 
    {
        for (current = buckets[i]; current != NULL; current = current->next) 
        {
            printf("Ten: %-10s - SDT: %s\n", current->name, current->phone);
        }
    }
    printf("------------------------\n");
}

void free_table(void) 
{
    int i;
    struct Node *current;
    struct Node *next_node;

    for (i = 0; i < TABLE_SIZE; i++) 
    {
        current = buckets[i];
        while (current != NULL) 
        {
            next_node = current->next;
            free(current);
            current = next_node;
        }
        buckets[i] = NULL;
    }
}