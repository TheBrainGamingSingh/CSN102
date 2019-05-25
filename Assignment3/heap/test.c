#include<stdio.h>
#include<stdlib.h>

 

 void main()
 {
   int a=5;
   char* str[2]={"Even","Odd "};
   printf("%s",str[a%2]);
   
 }