

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_integer_array {

    int size;
    int* array;

}integer_array;

int find_duplicate(int n, int pos, integer_array* a) {

    for(int i = pos+1; i< a->size; i++)
	if (a->array[i] == n)
		return 1;
    return 0;

}


integer_array* my_array_uniq(integer_array* param_1) {

   int temp_array[1000];
   int c = 0;
   for(int i =0 ; i<param_1->size; i++)
	if(!find_duplicate(param_1->array[i],i,param_1))
		temp_array[c++]	= param_1->array[i];
   
   integer_array * a = malloc(sizeof(integer_array));

   a->array = malloc(sizeof(int)*c);
   a->size = c;

   for(int i = 0; i< c ; i++ )
	a->array[i] = temp_array[i];

   return a;

}



int main() {
    
   integer_array* a = malloc(sizeof(integer_array)); 
   
   a->size = 5;
   a->array = malloc(sizeof(int)*5);
 
   a->array[0]=1;
   a->array[1]=2;
   a->array[2]=2;
   a->array[3]=3;
   a->array[4]=1;

   integer_array * uniq = my_array_uniq(a);

   for(int i = 0; i< uniq->size; i++)
	printf("%d\n", uniq->array[i]);

   




}
