#include <stdio.h>
#include <math.h>
#include <conio.h>

double stepen(double x,int step)
{	
	int a=0;
	double rez = 1.0;
	while (a<step)
	{
		rez = rez*x;
		a++;
	}
	return rez;
};
double d_standart_parabola(double x,double a,double b, double c)
{
	return a*x*x + b*x +c;
}

double d_integral(double (*f)(double), double A, double B, double step){
	double x=A;
	double sum=0.0;
	while (x <B)
	{
		sum  += step * f(x+step);
		x += step; 

	};


	return sum;
};
double d_integral1(double (*f)(double,int), double A, double B, double step,int power){
	double x=A;
	double sum=0.0;
	while (x <B)
	{
		sum  += step * f(x+step,power);
		x += step; 

	};


	return sum;
};

double d_integral2(double (*f)(double,double,double,double), double A, double B, double step,double a,double b ,double c)
{
	double x=A;
	double sum=0.;
	while (x <B)
	{
		sum  += step * f(x+step,a,b,c);
		x += step; 

	};


	return sum;
};

int main(int argc, char const *argv[])
{
	double d=0.;
	double A = 0.;
	double B = 0.;
	double a = 0.;
	double b = 0.;
	double c = 0.;
	int power = 0;

	printf("Choose function, insert number:\n");
	printf("1. sin(x)\n");
	printf("2. cos(x)\n");
	printf("3. x^n \n");
	printf("4. ax^2 + bx +c \n");
	printf("5. sqrt(x) \n");
	int insert =10;
	scanf("%d",&insert);
	switch(insert)
		{
			case 0:
				break;
			case 1:
				printf("Insert borders of integration\n");

				scanf("%lf %lf",&A,&B);
				d = d_integral((*sin),A,B,0.00001);
				printf ("Your result: %lf",d);
				break;
			case 2:
				printf("Insert borders of integration\n");

				scanf("%lf %lf",&A,&B);
				d = d_integral((*cos),A,B,0.00001);
				printf ("Your result: %lf",d);
				break;
			case 3:
				printf("Insert borders of integration and power of x:\n");
				scanf("%lf %lf %d",&A,&B,&power);
				d = d_integral1((*stepen),A,B,0.00001,power);
				printf ("Your result: %lf",d);
				break;
			case 4:
				printf("Insert borders of integration and coefficients a,b,c:\n");

				scanf("%lf %lf %lf %lf %lf",&A,&B,&a,&b,&c);
				d = d_integral2((*d_standart_parabola),A,B,0.00001,a,b,c);
				printf ("Your result: %lf",d);
				break;
			case 5:
				printf("Insert borders of integration\n");

				scanf("%lf %lf",&A,&B);
				d = d_integral((*sqrt),A,B,0.00001);
				printf ("Your result: %lf",d);
				break;
			default:
				printf("Insert right command or 0 for exit");
		}

	getch();

	
	return 0;
}