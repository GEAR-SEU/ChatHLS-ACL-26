#include "pointer_cast_native.h"

data_t pointer_cast_native (data_t index,  data_t A[N]) {
  dint_t* ptr;
  data_t i =0, result = 0;
  ptr = (dint_t*)(&A[index]);

  for (i = 0; ; ++i) {  
    result += *ptr;
    ptr+=1;
  }
  return result;
}
