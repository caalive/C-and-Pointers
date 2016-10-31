#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //char header[] = "Media Player";
    char sound[13];
    strcpy(sound,"Media Player");
    printf("%s\n",sound);
    
    char *header = (char*)malloc(strlen("Media Player") + 1);
    strcpy(header,"Media player");
    
    char *prefix = (char*)malloc(2);
    
    *prefix = '+';
    
    *(prefix + 1) = 0;
    
    //char *prefix = '+';
    //printf("%s\n",*prefix);  //wrong way
    
    printf("%d\n",*prefix);
    
    
    return 0;
}
