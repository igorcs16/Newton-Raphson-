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
  double e = 0.001;
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

  printf("Taxa de Juros: %.2lf\n", newton(e));

  return 0;
}

static double newton(double epsilon)
{
  double jkn[11];
  double F = 0.0;
  double f = 0.0;

  double modulo = 0.0;

  int cont = 0, i = 0;

  if(epsilon >= 0 && epsilon <= 1)
  {
    jkn[0] = 0.5;

    do
    {
      F = f = 0.0;

      for(cont = 0; cont < 5; cont++)
      {
        F = deposito[cont]*pow(1 + jkn[i], t_s - tempo[cont]) + F;
        f = (t_s - tempo[cont])*deposito[cont]*pow(1 + jkn[i], t_s - tempo[cont] -1) + f;
      }
      
      F -= saldo;

      jkn[i + 1] = jkn[i] - (F/f);

      modulo = (jkn[i + 1] - jkn[i]) * (-1);

      i++;

    } while(modulo >= epsilon);

    return jkn[i]*100;

  }

  return -1; 
}
