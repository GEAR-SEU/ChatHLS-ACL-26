

#include "loop_sequential.h"
 
int main () {
  din_t A[N], B[N];
  dout_t X[N], Y[N];
  dsel_t xlimit, ylimit;
  
  int i, retval=0;
  ofstream FILE;
  
  
  for(i=0; i<N;++i) {
    A[i]=i;
    B[i]=N-1-i;
  }
  
  FILE.open ("result.dat");
  
  
  xlimit=31;
  ylimit=31;
  loop_sequential(A,B,X,Y,xlimit,ylimit);
  
  for(i=0; i<N-1;++i) {
    FILE << X[i] << " " << Y[i] << endl;
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

