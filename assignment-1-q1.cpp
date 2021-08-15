#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct numarray{
	int* num;
	int len;
};

void initialize(numarray* arr, int len){
	arr->len = len;
	arr->num = new int [arr->len + 1];
}

void random(numarray* arr)
{
    int i = 0;
    srand(time(0));
    while (i < arr-> len)
    {
        arr->num[i] = rand();
        i++;
    }
}

void display(numarray* arr)
{
    int i = 0;
    int counter = 0;
    while (i < arr-> len)
    {
    	if(counter != 10)
    	{
	        printf("%d\t", arr->num[i]);
	        i++;
	        counter++;
		}
		else
		{
			printf("\n%d\t", arr->num[i]);
	        i++;
	        counter = 1;	
		}
    }
}

void insert(numarray* arr, int pos, int val) {
	
	arr->len = arr->len + 1;
	int i = arr->len - 1;
		
	while(i>pos-1)
	{
		arr->num[i] = arr->num[i-1];
		i--;
	}
	
	arr->num[pos-1] = val;
}

void sort(numarray* arr)
{
	//using insertion sort
	
	int len = arr->len, key;
    for (int i=1; i<len; i++)
    {
        key = arr->num[i];
        int j = i-1;
        while (j >= 0 && arr->num[j] > key)
        {
            arr->num[j+1] = arr->num[j];
            j = j-1;
        }
        arr->num[j+1] = key;
    }
}

int linearsearch(numarray *arr, int key)
{
	//using linear search
	
	for(int i = 0; i < arr->len; i++ )
		if(arr->num[i] == key)
		{
			return i;
			break;
		}
		else
			return -1;
}

int binarysearch(numarray *arr, int key){
	//binary search
	
	int min = 0;
	int max = arr->len -1;
	int mid = (min + max)/2;
	while (min <= max) 
	{
		int mid = (min + max)/2;
		
		if(arr->num[mid] < key)
			min = mid + 1;
		else if (arr->num[mid] == key) 
		{
			return mid;
		}
		else
			max = mid - 1;
	}
	
	return -1;
}

void deletenum(numarray* arr, int val){
	
	int found = search(arr, val);
	if(found == -1)
		printf("Element not in the array");
	else
	{
		for(int i = found; i<arr->len-1 ; i++)
			arr->num[i] = arr->num[i+1];
			
		arr->len = arr->len - 1;
	}
}

int continuefn(){
	int ch, flag;
	printf("\n\nDo you want to continue? (press 1 for yes, any other input would be considered as no): ");
	scanf("%d", &ch);
				
	if(ch == 1)
		flag = 0;
	else 
		flag = 1;
	
	return flag;
}

void destroy(numarray* arr){
	delete [] arr->num;
}

int main(){
	
	numarray arr;
	
	
	int len = 0;
	do{
		printf("Enter the length of your array: ");
		scanf("%d", &len);
		if(len<=0)
			printf("Length must be greater than 0!!\n\n");
	}while(len<=0);
	
	initialize(&arr, len);
	random(&arr);
	printf("\nYour array is:\n");
	display(&arr);
	
	int choice, flag = 0;
	printf("\n\nMenu\n\n1.Insert\n2.Delete\n3.Search\n4.Exit");
	
	
	do
	{
		printf("\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: {
				int pos, val;
				printf("\n\nEnter the details:");
				
				do{
					printf("\nPosition of the element to be inserted: ");
					scanf("%d", &pos);
					if(pos<=0 || pos>len)
						printf("Position must be greater than 0 and less than the length of the array!!\n");
						
				}while(pos<=0 || pos>len);
				
				printf("Value to be inserted: ");
				scanf("%d", &val);
				
				insert(&arr, pos, val);
				
				printf("\nYour current array is:\n");
				display(&arr);
				
				flag = continuefn();
				
				break;
			}
			
			case 2:{
				int val;
				printf("\n\nEnter the details:\nValue of the element to be deleted: ");
				scanf("%d", &val);
				
				deletenum(&arr, val);
				
				printf("\nYour current array is:\n");
				display(&arr);
				
				flag = continuefn();
				
				break;
			}
			
			case 3:{
				int val, pos;
				printf("\n\nEnter the details:\nValue of the element to search: ");
				scanf("%d", &val);
				
				pos = linearsearch(&arr, val);
				if(pos == -1)
					printf("\nElement not in array");
				else 
					printf("\nElement found at postion = %d", pos+1);
					
				flag = continuefn();
				
				break;
			}
			
			case 4:{
				printf("Thank you!");
				exit(0);
				break;
			}
			
			default: printf("Not a valid choice!!");
		}
		
	}while(flag == 0);
	
	
	destroy(&arr);
	
	return 0;
}
