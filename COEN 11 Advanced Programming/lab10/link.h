#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define M 20

typedef struct phone
{
        char name[M];
        char number[M];
        struct phone *next;
}PHONE;

pthread_mutex_t mutex;

//PHONE *tail2 = NULL;
PHONE *head[26];


void read_insert(char*book);
void save_file(char*book);
void bin_read(char *binbook);
int input(char name1[M], char number2[M]);
int delete();
int show();
int letter();
void* bin_save(void* x);


