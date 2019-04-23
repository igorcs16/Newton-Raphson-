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
  double jk = 0.5;
  double jkn[10];
  double F = 0.0;
  double f;

  double modulo;

  int cont, i;

  if(epsilon >= 0 && epsilon <= 1)
  {
    for(i = 0; i < sizeof(deposito); i++)
    {
      //funcao
      if(i == 0)
      {
        for(cont = 0; cont < sizeof(deposito); cont++)
        {
          F = deposito[cont]*pow(1 + jk, tempo[cont]) + F;
          f = tempo[cont]*deposito[cont]*pow(1 + jk, tempo[cont]-1) + f;
        }

        jkn[i] = jk - (F/f);

        modulo = (jkn[i] - jk) * (-1);

        if(modulo < epsilon)
          return jk;
      }

      else
      {
        for(cont = 0; cont < sizeof(deposito); cont++)
        {
          F = deposito[cont]*pow(1 + jkn[i], tempo[cont]) + F;
          f = tempo[cont]*deposito[cont]*pow(1 + jkn[i], tempo[cont]-1) + f;
        }

        jkn[i+1] = jk - (F/f);

        modulo = (jkn[i + 1] - jkn[i]) * (-1);

        if(modulo < epsilon)
          return jkn[i];
      }

    }
  }

  return -1; 
}
