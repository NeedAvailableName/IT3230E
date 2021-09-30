/*write a command line program that solves the second degree equation ax^x+bx+c=0 with the following syntax: sde a b c
example sde 1 2 1 return: x1=x2=-1*/
#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[]) {
	if(argc!=4) {
		printf("wrong syntax\n");
		printf("enter sde a b c\n");
	}
	else {
        double a=atof(argv[1]);
	    double b=atof(argv[2]);
	    double c=atof(argv[3]);
	    double delta=b*b-4*a*c;
	    if(delta<0) printf("The equation has no solution\n");
	    else if(delta==0) printf("x1=x2=%f\n", -b/(2*a));
	    else printf("x1=%f, x2=%f\n", (-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
	}
	return 0;
}
