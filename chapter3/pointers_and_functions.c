#include <stdio.h>
#include <stdlib.h>

void function2()
{
	//Object * var1 = ...;
	//int var2;
	printf("Program Stack Example\n");
}

void function1()
{
	//Object *var3 = ...;
	function2();
	
}

float average(int *arr,int size)  //传入数组计算平均值
{
	int sum;
	printf("arr:%p\n",&arr);
	printf("size:%p\n",&size);
	printf("sum:%p\n",&sum);
	
	int i = 0;
	for(; i < size; i++)
	{
		sum += arr[i];
	}
	return (sum * 1.0f) / size;				//返回平均值
	
}

void swapvalue(int *ar1,int *ar2)			//使用指针交换传入的两个变量
{
	int tmp;
	tmp = *ar1;
	*ar1 = *ar2;
	*ar2 = tmp;
}

void allocateArry(int **arr,int size,int value)			//修改传入的指针地址
{
	int i = 0;
	*arr = (int *)malloc(sizeof(int) * size);			//malloc空间修改外部变量指针值
	if (*arr != NULL)
	{
		for(; i < size; i++)
		{
			*(*arr+i) = value;
		}
	}
}



int *arry(int value,int size)
{
	int *arr = malloc(sizeof(int) *  size);
	int i = 0;
	for(; i < size; i++)
	{
		arr[i] = value;
	}
	return arr;
}


#define safeFree(p) saferFree((void**)&(p))			//宏定义强制转换指针类型

void saferFree(void **pp)							//释放外部传入的指针，并将其值设置为NULL防止出现野指针
{
	if(pp != NULL && *pp != NULL)
	{
		free(*pp);									//调用系统free函数
		*pp = NULL;
	}
}

typedef int (*fptrOperation)(int num1,int num2);	//定义一个有两个参数返回值为整型的函数指针类型

int computer(fptrOperation operation,int num1,int num2)	
{
	return operation(num1,num2);
}


int add(int num1,int num2)						//返回两个数之和
{
	return num1 + num2;
}

int substract(int num1,int num2)				//返回两个数之差
{
	return num1 - num2;
}

fptrOperation selector(char code)				//根据输入的符号＋－返回选择哪个函数指针
{
	switch(code)
	{
		case '+':
			return add;
		case '-':
			return substract;
			
		default:return 0;
			
	}
	
}

int evaluate(char code,int num1,int num2)
{
	fptrOperation operation = selector(code);
	return operation(num1,num2);
}


int main()
{
	//int var4;
	//function1();
	
	/*
	int arr[5] = {1,2,3,4,5};
	printf("average:%f\n",average(arr,5));
	
	int h,k;
	h = 5,k = 6;
	
	swapvalue(&h,&k);
	
	printf("h:%d k:%d\n",h,k);
	*/
	
	int *vector = arry(5,8);
	int i = 0;
	
	for(; i < 8; i++ )
	{
		printf("vector[%d]:%d\n",i,vector[i]);
	}
	
	//free(vector);
	//vector = NULL;
	safeFree(vector);
	
	
	int *vector1 = NULL;
	
	void (*fptr_arry)(int **pp,int size,int value);		//声名一个函数指针
	
	//allocateArry(&vector1,10,9);
	
	fptr_arry = allocateArry;							//函数指针赋值
	
	fptr_arry(&vector1,10,9);							//调用函数指针
	
	
	for(i = 0; i < 10; i++ )
	{
		printf("vector1:%p vector1[%d]:%d\n",vector1,i,vector1[i]);
	}
	
	//free(vector1);
	//vector1 = NULL;

	printf("free before:%p\n",vector1);					
	safeFree(vector1);								//调用宏定义过的释放指针函数
	printf("free after:%p\n",vector1);
	safeFree(vector1);
	
	printf("%d\n",computer(add,5,6));				//调用函数指针
	printf("%d\n",computer(substract,8,4));
	
	printf("%d\n",evaluate('+',5,6));				//调用函数
	printf("%d\n",evaluate('-',8,4));
	return 0;	
} 














