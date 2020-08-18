
#include <mpi.h>
#include <stdio.h>

static int long numSteps = 100000;

int main(int argc, char **argv){
    double pi=0;
    double time=0;
    double dx = 1.0/(double) numSteps;


    int numP, procID;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numP);
    MPI_Comm_rank(MPI_COMM_WORLD, &procID);

    for (int i=procID; i<numSteps; i+=numP) {
    	double x = (i+0.5)*dx;
    	pi += 4.0/(1.0+x*x);    	
    }
    pi *= dx;

    double *globalSum=NULL;
    if (procID==0) {
      globalSum = (double*)malloc(numP*sizeof(double));
      // for unknown size
    }

    MPI_Gather(&pi,1,MPI_DOUBLE, globalSum, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (procID==0) {
      for (int i=1; i<numP; i++) {
	pi += globalSum[i];
      }
   
      printf("PI=%f, duration:%f ms\n",pi,time);
    }
    return 0;
}
