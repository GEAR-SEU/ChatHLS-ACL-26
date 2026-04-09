

#include "loop_pipeline.h"
 
int main () {
  din_t A[N];
  dout_t accum;
	
  int i, j, retval=0;
  ofstream FILE;

  
  for(i=0; i<N;++i) {
    A[i]=i;
  }
  
  FILE.open ("result.dat");
  
  
  for(j=0; j<NUM_TRANS;++j) {
    accum = loop_pipeline(A);
    FILE << accum << endl;
    
    for(i=0; i<N;++i) {
      A[i]=A[i]+N;
    }
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

