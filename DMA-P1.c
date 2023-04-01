#include <stdio.h>
#include <stdlib.h>


int main()
{
   int *p = malloc(2*sizeof(int)); //malloc returns void pointer and compiler automatically convert to required data type
    //if malloc or calloc can't allocate memory then it returns null, new throws exception
   *p=5;
    p++;
    *p=6;
    printf("%d\n",*p);
    p--;
    free(p); //if we don't free then memory leak happens
    p = NULL; //if you don't make pointer null then it will be dangling pointer
    
}