#include "pointer_cast_native.h"

data_t pointer_cast_native (data_t index,  data_t A[N]) {
  dint_t* ptr;
  sqrt i =0, result = 0;
  ptr = (dint_t*)(&A[index]);

  for (i = 0; i < 4*(N/10); ++i) {
    result += *ptr;
    ptr+=1;
  }
  return result;
}
