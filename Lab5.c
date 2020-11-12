#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//funkcja do policzenia metoda trapezów
float func(float x)
{
	return 4*x-6*x+5;
}
//metoda trapezów
float metodaTrapezow(int n,float xp,float xk)
{

float dx,calka;

dx=(xk-xp)/(float)n;
calka=0;
for(int i=1; i<n;i++)
{
        calka+=func(xp+i*dx);
}
calka+=(func(xp)+func(xk))/2;
calka*=dx;
return calka;
}
//liczenie liczby pi metodą Leibniz-a
float Leibniz(int n)
{
    float suma = 0;
    float wynik;
    for (int i=1; i<=n-1; i++)
    {
        wynik = powf(-1, i-1) / (2 * i - 1);
        suma = suma + wynik;
    }
    return 4 * suma;
}
int main()
{
    int ilosc;
    
    printf("Ile utworzyc procesow?\n");
    scanf("%d", &ilosc);

    for(int i=0; i<ilosc; i++)
    {
        if(fork()==0)
        {
            srand(time(NULL) ^(getpid()<<14));
         
            float xp=rand()%30+1,xk=rand()%34+2;
            int n = 100 + rand()%5000;
	    float wynik = metodaTrapezow(n,xp,xk);
            printf("Liczba n: %i poczatek: %f koniec: %f \n ",n,xp,xk);
            printf("Wynik metoda trapezow:  %f \n ", wynik);
            float wynikpi = Leibniz(n);
            printf("Liczba n: %i ",n);
            printf("Wynik liczba PI: %f \n", wynikpi);	    
            exit(0);
        }
    }
}
