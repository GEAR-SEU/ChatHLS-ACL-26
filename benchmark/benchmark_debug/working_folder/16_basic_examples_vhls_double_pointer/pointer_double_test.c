


#include "pointer_double.h"
 
int main () {
	data_t data_o;

	int i, retval=0;
	FILE        *fp;

	
	fp=fopen("result.dat","w");

	
   for(i=0; i<10;++i) {
			int flag = i;
			data_o = pointer_double(i, -1, &flag);
			fprintf(fp, "%d \n", data_o);
   }
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

