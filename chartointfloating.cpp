#include <stdio.h>

struct string{
    char *str;
    int len;
};


void initialize(string* arr, int len)
{
    arr->len = len;
    arr->str = new char [arr->len+1];
}

float convert(string* arr)
{
    int i = 0;
	float num = 0;
	int decimal = 0;
	while(arr->str[i] != '\0')
    {
    	if(arr->str[i] == '.')
    	{
    		decimal = 1;
    	}
    	
    	else
		{
        	int temp = arr->str[i] - '0';
    		if (decimal == 0)
        		num = num*10 + temp;
        	else{
        		decimal *= 10;
        		num += temp/(float)decimal;
        	}
    	}
    	
    	i++;
        
    }
    
    return num;
}


void destroy(string* arr)
{
    delete [] arr->str;
}


int main()
{
    string arr;

    printf("Enter no. of nos.: ");
    int len = 0;
    scanf("%d", &len);
    len++;	

    initialize(&arr, len);

    int i = 0;
    do
    {
        char ch = getchar();
        if (ch != 10)
        {
            arr.str[i] = ch;
            i++;
        }
    } while(i<arr.len);

    arr.str[arr.len] = '\0';

    float num = convert(&arr);
    printf("\n%f", num);    
    destroy(&arr);

    return 0;
}
