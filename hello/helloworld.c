#include <stdio.h>

int main()
{
	//printf("hello world");
	char *names[]={"Miller","Jones","Anerson"};
	printf("%c\n",*(*(names+1)+2));    //dereference the first * in parentheses is "Jones" seconed is "n" 
	printf("%c\n",names[1][2]);
	
	int num = 5;
	int *p = &num;
	
	printf("p:%d\n",*p);
//	printf("num:%0x\n",&num);
	
	
	int *pi;
	int st;
	pi = &st;
	
	printf("Value of pi: %p\n",pi);
	void * pv = pi;          //convert to void * type
	pi = (int*)pv;       	 //convert to int * type
	printf("Value of pi:%p\n",pi);
	
	const size_t key = 40;
	printf("%d",key);
	
	
//	const int *pci = &key;
//	*pci = 600;
	
	int *const pci = &num;
	
	
	printf("num:%d\n",num);
	
	num = 1000;
	
	printf("num:%d",num);
	return 0;
}
