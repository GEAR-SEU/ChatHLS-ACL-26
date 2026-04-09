

#include "loop_max_bounds.h"
 
int main () {
  din_t A[N];
	dsel_t x=0;
	dout_t accum;
	
	int i, retval=0;
	ofstream FILE;

	for(i=0; i<N;++i) {
	  A[i]=i;
	}
	
	FILE.open ("result.dat");

	
	for(i=0; i<N;++i) {
	  x=i;
	  accum = loop_max_bounds(A,x);
	  FILE << accum << endl;
	}
	FILE.close();

	
	retval = system("diff --brief -w result.dat result.golden.dat");
	if (retval != 0) {
	  cout << "Test failed  !!!" << endl; 
	  retval=1;
	} else {
	  cout << "Test passed !" << endl;
	}

	
  return retval;
}

