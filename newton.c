#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double deposito[10];
int tempo[10];
double saldo;
int t_s;

static double newton(double epsilon);

int main()
{
  double e = 0.0;
  int i = 0;
  char perc = '%';
   
  printf("Digite os valores dos depósitos e o mês de cada depósito\n");

  for(i = 0; i < 10; i++)
  {
    printf("Valor:");
    scanf(" %lf", &deposito[i]);

    printf("Mês:");
    scanf(" %d", &tempo[i]);

    printf("\n");
  }

  printf("Saldo:");
  scanf(" %lf", &saldo);

  printf("Mês Saldo:");
  scanf(" %d", &t_s);
  
  printf("\nValor de Precisão:");
  scanf(" %lf", &e);

  printf("\nTaxa de juros anual é de aproximadamente: %.2lf%c\n", newton(e), perc);

  return 0;
}

static double newton(double epsilon)
{
  double jkn = 0.5;
  double aux = 0.0;
  double F = 0.0;
  double f = 0.0;

  double modulo = 0.0;

  int cont = 0, i = 0;

  if(epsilon >= 0 && epsilon <= 1)
  {
    do
    {
      F = f = 0.0;

      for(cont = 0; cont < 10; cont++)
      {
        F += deposito[cont]*pow(1 + jkn, t_s - tempo[cont]);
        f += (t_s - tempo[cont])*deposito[cont]*pow(1 + jkn, t_s - tempo[cont] -1);
      }
      
      F -= saldo;

      aux = jkn;
      jkn = jkn - (F/f);

      modulo = (jkn - aux) * (-1);

      i++;

    } while(modulo >= epsilon);

    return jkn*100;

  }

  return -1; 
}
