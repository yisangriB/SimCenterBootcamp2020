#include <omp.h>
#include <stdio.h>


int main(){
  
  static int long numSteps = 100000000;
  
  double pi=0, sum=0;
  double time=0;
  double dx = 1.0/(double)numSteps;

#pragma omp parallel reduction(+:pi)
    {
      int tid = omp_get_thread_num();
      int numT = omp_get_num_threads();

      for (int i=tid; i<numSteps; i+=numT) {
    	double x = (i+0.5)*dx;
    	sum += 4.0/(1.0+x*x);    	
      }
      pi += sum;
    }

    pi *=dx;

    printf("PI is %f\n",pi);

    return 0;
}
