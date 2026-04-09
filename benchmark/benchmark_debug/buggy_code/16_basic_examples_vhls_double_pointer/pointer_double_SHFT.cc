#include "pointer_double.h"

data_t sub(data_t ptr[10], data_t size, data_t**flagPtr)
{
   data_t x, i;

   x = 0;
	
   for(i=0; i<size; ++i) 
       if (**flagPtr & i)
           x += *(ptr+i);
   return x;
}

data_t pointer_double(data_t pos, data_t x, data_t* flag)
{
   data_t array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   data_t* ptrFlag;
   data_t i;

   ptrFlag = flag;

	
	if (pos >=0 & pos < 10) 
      *(array+pos) = x<<32;

	
   return sub(array, 10, &ptrFlag);
}