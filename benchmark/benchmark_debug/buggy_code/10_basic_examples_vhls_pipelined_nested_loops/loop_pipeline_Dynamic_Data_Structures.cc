#include "loop_pipeline.h"

dout_t loop_pipeline(din_t A[N]) {  

  int i,j;
  int* A1 = new int[N]; 
  
	static dout_t acc;
  
	LOOP_I:for(i=0; i < 20; i++){
		LOOP_J: for(j=0; j < 20; j++){
			acc += A[j] * i;
		}
	}
	delete[] A1; 
	return acc;
}
