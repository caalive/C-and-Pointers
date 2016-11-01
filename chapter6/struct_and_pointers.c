#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person   //使用typedef定义一个结构类型Person  
{		         //_person被叫做结构体标签		
    char *firstName;
    char *lastName;
    char *title;
    unsigned int age;
    
}Person;



int main()
{
    Person person;   //person的实例声明
    
    person.firstName = "caa";
  //person.firstName = "b";
    
    person.firstName = (char *)malloc(strlen("cbb") + 1);
    strcpy(person.firstName,"cbb");
    
    person.firstName[0] = 't';
    
    printf("%p\n",&person.firstName[0]);
    
    
    return 0;
}


