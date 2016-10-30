#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *trim(char *phrase)
{
    char *old = phrase;
    char *new = phrase;
    
    while(*old == ' ')
    {
	old++;
    }
    
    while(*old)
    {
	*(new++) = *(old++);
    }
    
    *new = 0;
    return (char*)realloc(phrase,strlen(phrase) + 1);
}




int main()
{
   // int vector[5] = {1,2,3,4,5};
    int matrix[2][3] = {{1,2,3},{4,5,6}};
    
    int i = 0;
    for(; i < 2; i++)
    {
	printf("&matrrix[%d]:%p sizeof(matrix[%d]):%d\n",i,&matrix[i],i,sizeof(matrix[i]));
    }
    
    int *pv = (int *)malloc(sizeof(int) * 5);
    
    
    for(i = 0; i < 5; i++)
    {
	pv[i] = i + 1;
    }
    
    for(i = 0; i < 5; i++)
    {
	printf("pv[%d]:%d,%p\n",i,*(pv + i),pv);
    }
    
    free(pv);
    pv = NULL;
    
    char *buffer = (char*)malloc(strlen("   cat") + 1);
    strcpy(buffer," cat");
    printf("%s\n",trim(buffer));
    
    return 0;
}


