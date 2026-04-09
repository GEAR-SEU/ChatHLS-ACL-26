

#include "loop_imperfect.h"

int main() {
    din_t A[N];
    dout_t B[N];

    int i, retval = 0;
    ofstream FILE;


    for (i = 0; i < N; ++i) {
        A[i] = i;
    }
    
    FILE.open ("result.dat");

    
    loop_imperfect(A, B);
    for (i = 0; i < N; ++i) {
      FILE << B[i] << endl;
    }
    FILE.close();

    
    retval = system("diff --brief -w result.dat result.golden.dat");
    if (retval != 0) {
      cout << "Test failed  !!!" << endl; 
      retval = 1;
    } else {
      cout << "Test passed !" << endl;
    }

    
    return retval;
}

