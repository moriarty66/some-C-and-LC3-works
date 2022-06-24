#include<stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[])
{           
    double sum=0,avg,var;
    int n=argc-1;
    double *p = (double*)malloc(n*sizeof(double));
    for(int i=1; i<argc; i++)
	{
        p[i-1] = (double)atof(argv[i]);
        sum += p[i-1];
    }
    avg = sum/n; 
    for (int j=0; j<n; j++)
    {
        var += pow(p[j]-avg,2)/n;//Çó·½²î
    }
    printf("%lf",var);
    free(p);
}

