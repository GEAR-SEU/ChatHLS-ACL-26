#include "pointer_cast_native.h"

data_t pointer_cast_native (data_t index,  data_t *A) {
  dint_t* ptr;
  data_t i =0, result = 0;
  int* A1 = new int[N]; 
  ptr = (dint_t*)(&A[index]);

	
  for (i = 0; i < 4*(N/10); ++i) {
    result += *ptr;
    ptr+=1;
  }
  delete[] A1;
  return result;
} 