
#include <stdio.h>

static int long numSteps = 100000;

int main(){
    double pi=0;
    double time=0;
    double dx = 1.0/(double)numSteps;
    for (int i=0; i<numSteps; i++) {
    	double x = (i+0.5)*dx;
    	pi += 4.0/(1.0+x*x);    	
    }
    pi *= dx;

    printf("PI=%f, duration:%f ms\n",pi,time);
    return 0;
}