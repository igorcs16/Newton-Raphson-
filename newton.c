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
  double e;
  int i = 0;
  
  printf("Digite os valores dos depositos e o mes de cada deposito\n");

  for(i = 0; i < 5; i++)
  {
    printf("Valor:");
    scanf(" %lf", &deposito[i]);

    printf("Mes:");
    scanf(" %d", &tempo[i]);
  }

  printf("\nSaldo:\n");
  scanf(" %lf", &saldo);

  printf("Mes Saldo:\n");
  scanf(" %d", &t_s);
  
  printf("Valor de Precisao:");
  scanf(" %lf", &e);

  newton(e);

  return 0;
}

static double newton(double epsilon)
{
  double jkn[11];
  double F = 0.0;
  double f;

  double modulo;

  int cont = -1, i, j;

  if(epsilon >= 0 && epsilon <= 1)
  {
    jkn[0] = 0.5;

    for(i = 0; i < 5; i++)
    {
      cont++;

      for(j = cont; j < 5; j++)
      {
        F = deposito[cont]*pow(1 + jkn[i], t_s - tempo[cont]) + F;
        f = (t_s - tempo[cont])*deposito[cont]*pow(1 + jkn[i], t_s - tempo[cont] -1) + f;
      }

      jkn[i + 1] = jkn[i] - (F/f);

      modulo = (jkn[i + 1] - jkn[i]) * (-1);

      if(modulo < epsilon)
        return jkn[i + 1];
    }

  }

  return -1; 
}
