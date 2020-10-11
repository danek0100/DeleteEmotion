#include "header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

NODE* push(NODE* phead, int v)
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->value = v;
	p->pnext = phead;
	return p;
}

NODE* pushpri(NODE* phead, char* v)
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->value = v;
	p->pnext = phead;
	return p;
}

NODE* pop(NODE* phead)
{
	NODE* p = phead->pnext;
	free(phead);
	return p;
}

NODE* poppri(NODE* phead)
{
	NODE* p = phead->pnext;
	printf("%c", phead->value);
	free(phead);
	return p;
} //Вывод с печатью

int IsEmpty(NODE* phead)
{
	if (phead)
		return 0;
	return 1;
}


int check(NODE* phead, char str, int n)
{
	if (!phead)
		n++;
	if ((str == ')') && (phead->value != '('))
		n++;
	return n;
}

int checkbrackets(NODE* head, char* res)
{
	int len = strlen(res);
	int n = 0;
	int left = 0;
	int right = 0;

	for (int i = 0; i < len; i++)
	{

		if ((res[i] == '\n'))
		{
			break;
		}

		if ((res[i] == '('))
		{
			head = push(head, res[i]);
			left++;
		}

		else if (head)
		{
			n = check(head, res[i], n);
			head = pop(head);
			right++;
		}
		else
			n = 1;
	}

	if ((n == 0) && (left == right))
		return 1;

	else
		return 0;
}


void change(char* start, int left, int right, int step, int* gsum)
{
	int len = strlen(start);
	char* changing = (char*)calloc(len + 1, sizeof(char));
	strcpy(changing, start);
	int chek = step;

	for (int i = step; i < len; i++)
	{
		if ((start[i] == '\n' || start[i] == ' '))
		{
			changing[i] = '\0';
			chek = 1001;
			break;
		}

		if (start[i] == '(')
			left++;


		if (start[i] == ')')
			right++;

		if (right > left)
			break;

		if (left == right && (left != 0))
		{
			NODE* ch = 0;
			int le = strlen(changing);
			char* chak = (char*)calloc(le + 1, sizeof(char));
			strcpy(chak, changing);
			chak[i + 1] = '\0';
			if (!checkbrackets(ch, changing))
			{
				free(chak);
				break;
			}
			free(chak);
		}

		if (left > len / 2)
		{
			break;
		}

		if (start[i] == '?')
		{
			changing[i] = ')';
			change(changing, left, ++right, i + 1, gsum);
			changing[i] = '(';
			change(changing, ++left, --right, i+1, gsum);	
			break;
		}

		

		chek++;
	}

	NODE* head = 0;

	
	/*int n = 0;
	for (int i = 0; i < len; i++)
	{

		if (start[i] == '?')
		{
			n++;
			break;
		}
	}*/

	if (step >= len)
		if (chek == 1001 || chek == len)
			if (checkbrackets(head, changing))
				(*gsum)++;
	free(changing);
}