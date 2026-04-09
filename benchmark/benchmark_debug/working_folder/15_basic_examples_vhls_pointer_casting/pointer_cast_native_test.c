


#include "pointer_cast_native.h"
 
int main () {
	data_t din[N], idx, dout;

	int i, retval=0;
	FILE        *fp;

	
   for(i=0; i<N;++i) {
			din[i] = i;
   }

	
	fp=fopen("result.dat","w");

	
	idx=136;
	dout=pointer_cast_native (idx, din);

	fprintf(fp, "%d \n", dout);
	fclose(fp);

	
	retval = system("diff --brief -w result.dat result.golden.dat");
	if (retval != 0) {
		printf("Test failed  !!!\n"); 
		retval=1;
	} else {
		printf("Test passed !\n");
  }

	
  return retval;
}

