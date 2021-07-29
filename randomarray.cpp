#include <stdio.h>
#include <stdlib.h>
#include<time.h>


struct numarray{
    int *num;
    int len;
};

void initialize(numarray* arr, int len)
{
    arr->len = len;
    arr->num = new int [arr->len];
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

void bubblesort(numarray* arr)
{
	int len = arr->len;
	for(int i=0; i<len-1; i++)
	{
		for(int j=0; j<len-i-1; j++)
			if(arr->num[j] > arr->num[j+1])
			{
				int temp = arr->num[j];
				arr->num[j] = arr->num[j+1];
				arr->num[j+1] = temp;
			}
	}
}


void insertionsort(numarray* arr)
{
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

void selectionsort(numarray* arr)
{
	int len = arr->len;
    for (int i=0; i < len-1; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        if (arr->num[j] < arr->num[min])
            min = j;
 
 		int temp = arr->num[min];
 		arr->num[min] = arr->num[i];
 		arr->num[i] = temp;
    }
}


void destroy(numarray* arr)
{
    delete [] arr->num;
}

int main()
{   
    //bubblesort(&arr);
    //insertionsort(&arr);
    
    int len_arr[15] = {10, 50, 100, 500, 1000, 1500, 2500, 5000, 7500, 10000, 15000, 25000, 50000, 75000, 100000};
    double time[15];
    
	for(int i=0; i<15; i++)
	{
		int len = len_arr[i];
	    numarray arr;
//	    printf("Enter the length of your array- ");
//	    scanf("%d", &len);
	
	    initialize(&arr, len);
	
	    random(&arr);
	
//	    display(&arr);
		
	    clock_t t;
	    t = clock();
	    
	    insertionsort(&arr);
	    
	    t = clock() - t;
	    
//	    printf("\n\n\nsorted array-\n");
	    
	    double time_taken = ((double)t)/CLOCKS_PER_SEC;
	    
	    time[i] = time_taken;
	    
	    printf("len = %d time to sort = %lf\n", len_arr[i], time[i]);
	    
	    destroy(&arr);
    
	}
		

    return 0;
}
