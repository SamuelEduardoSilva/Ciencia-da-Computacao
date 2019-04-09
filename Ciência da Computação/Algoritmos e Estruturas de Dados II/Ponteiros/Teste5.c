#include<stdio.h>

main()
{
   char x, *p1, *p2, *p3, *p4;
   p2 = p1++;
   p3 = p2+4;
   p4 = p3-5;


   printf("%p %p %p %p\n",p1,p2,p3,p4);
}


