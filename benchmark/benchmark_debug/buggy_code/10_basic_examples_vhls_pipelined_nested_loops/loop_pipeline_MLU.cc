#include "loop_pipeline.h"

dout_t loop_pipeline(din_t A[N]) {  

  int i,j;
	static dout_t acc;
  
	LOOP_I:for(i=0; i < 20; i=i+2){
		#pragma HLS unroll factor=4
		LOOP_J: for(j=0; j < 20; j++){
			acc += A[j] * i;
		}
	}

	return acc;
}
