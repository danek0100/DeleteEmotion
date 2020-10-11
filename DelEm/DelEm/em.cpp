#include "header.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 255


int main(int argc, char* argv[])
{
	FILE* fr = fopen(argv[1], "rb");
	if (!fr)
		return;
	fseek(fr, 0L, SEEK_END);
	long length = ftell(fr);
	fseek(fr, 0, SEEK_SET);

	unsigned char* res;
	res = (unsigned char*)malloc(sizeof(unsigned char) * (length + 1));
	for (int i = 0; i < length; i++)
	{
		res[i] = fgetc(fr);
	}
	res[length] = '\0';
	fclose(fr);



	int sum = 0;
	change(res, 0, 0, 0, &sum);
	printf("%d", sum);
	
	return 0;
}