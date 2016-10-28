#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	/*
	int *pi = (int*)malloc(sizeof(int));
	*pi = 5;
	//int num = 6;
	printf("*pi: %d\n",*pi);
	printf("pi:%p\n",pi);
	//printf("num:%x\n",&num);
	free(pi);
	pi = NULL;
	printf("pi:%p\n",pi);
	return 0;	
	*/
	
	char *name = malloc(strlen("susan")+1);
	if(name != NULL)
	{
		strcpy(name,"Susan");
		while(*name != 0)
		{
			printf("%c",*name);
			name++;
		}	
	}
	else
	{
		printf("can't malloc enough memory\n!!");
	}
/*	
	char *str;
	printf("Enter a str: ");
	scanf("%s",str);
	printf("%s",str);
*/	
//	const int NUMBER_OF_DOUBLES = 10;
	
//	double *pd = (double*)malloc(NUMBER_OF_DOUBLES);
	
	char *string1;
	char *string2;
	
	string1 = (char*)malloc(16);
	
	if(string1 != NULL)
	{
		strcpy(string1,"0123456789AB");
	}
	else
	{
		return 0;
	}
	
	string2 = (char*)realloc(string1,50);
	printf("string1 Value:%p[%s]\n",string1,string1);
	free(string1);
	string1 = NULL;
	printf("string2 Value:%p[%s]\n",string2,string2);
	
	free(name);
	name = NULL;
	free(string2);
	string2 = NULL;
	return 0;
		
}
