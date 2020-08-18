#include <stdio.h>
#include <time.h>
#include <mpi.h>

static int long numSteps = 1000000000;

int main(int argc, char **argv) {


  int procID, numP;

  double pi = 0;
  MPI_Double globalSum=0.0;
  double stepSize = 1.0/(double) numSteps;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size( MPI_COMM_WORLD, &numP);
  MPI_Comm_rank( MPI_COMM_WORLD, &procID);
    
  for (int i=procID; i<numSteps; i+=numP) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);
    // MPI_Send(&pi,1,MPI_INT,1,0,MPI_COMM_WORLD);
  }
  pi *= stepSize;
 
  if (procID == 0) {
    globalSum = (double*)malloc(numP*sizeof(double));
    //unknown size
  }
  MPI_Gather(&pi,1, MPI_DOUBLE, globalSum, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if (procID==0) {
    for (int i=1; i<numP; i++)
      pi +=globalSum;
  }

  printf("PI = %16.14f\n",pi);

  MPI_Finalize();
  return 0;

}
