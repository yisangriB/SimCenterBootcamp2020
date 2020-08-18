#include <stdio.h>
#include <time.h>
#include <omp.h>
static int long numSteps = 1000000000;

int main(int argc, char **argv) {

  double pi   = 0;
  double stepSize = 1.0/(double) numSteps;
#pragma omp parallel 
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();

    double sum = 0;

    for (int i=tid; i<numSteps;i+=numT) {
      double x = (i+0.5)*stepSize;
      sum += 4./(1.+x*x);
    }
    printf("%d %d\n",tid, numT);
    //printf("PI is %f\n", pi);
#pragma omp critical // only one thread working on this
    pi +=sum;    
  }

  pi *= stepSize;
  
  printf("PI = %16.14f\n",pi);
  return 0;
}
