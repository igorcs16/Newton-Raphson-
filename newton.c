#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE   1
#define FALSE  0

double deposito[10];
int tempo[10];
double saldo;
int t_s;

static double newton(double epsilon);

int main()
{
  double e = 0.5;

  newton(e);

  return 0;
}

static double newton(double epsilon)
{
  int i = 0;

  printf("Digite os valores dos depositos e o mes de cada deposito\n");

  for(i = 0; i < 5; i++)
  {
    printf("Valor:\n");
    scanf(" %lf", &deposito[i]);

    printf("Mes:\n");
    scanf(" %d", &tempo[i]);
  }
}
