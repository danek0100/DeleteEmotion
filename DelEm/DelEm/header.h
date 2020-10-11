#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <stdlib.h>



typedef struct node
{
	char value;
	struct node* pnext;
}NODE;

//Всё для стека
NODE* push(NODE* phead, int v);
NODE* pushpri(NODE* phead, char* v);
NODE* pop(NODE* phead);
NODE* poppri(NODE* phead);
int IsEmpty(NODE* phead);

//Для задний
void change(char* start, int left, int right, int step, int* gsum);
int checkbrackets(NODE* head, int maxi);
int check(NODE* phead, char str, int n);

#endif

