#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double nr(double a0, double a1, double a2, double a3, double a4, double a5, double x0){
    if (a1+2*a2*x0+3*a3*x0*x0+4*a4*x0*x0*x0+5*a5*x0*x0*x0*x0==0){
        printf("nan\n");
        return 1;
    }
    double x1;
    x1 = x0 - (a0+a1*x0+a2*x0*x0+a3*x0*x0*x0+a4*x0*x0*x0*x0+a5*x0*x0*x0*x0*x0)/(a1+2*a2*x0+3*a3*x0*x0+4*a4*x0*x0*x0+5*a5*x0*x0*x0*x0);
    static int counter=0;
    counter+=1;
if (fabs(x1-x0)<1e-6){
        printf("%1.2f\n",x1);
}
    else if (counter==1000){
        printf("incomplete\n");
        return 1;
    }
    else{ 
    x0=x1;
    return nr(a0,a1,a2,a3,a4,a5,x0);
    }
    }
    int main(int argc, char **argv){
        if (argc != 8){
            printf("The programm must be called as ./netwon a0 a1n a2 a3 a4 a5 x0");
            return 1;
        }
    double a0 = strtod(argv[1],NULL);
    double a1 = strtod(argv[2],NULL);
    double a2 = strtod(argv[3],NULL);
    double a3 = strtod(argv[4],NULL);
    double a4 = strtod(argv[5],NULL);
    double a5 = strtod(argv[6],NULL);
    double x0 = strtod(argv[7],NULL);
    
    return nr(a0,a1,a2,a3,a4,a5,x0);
    }