#include <stdio.h> // Biblioteca para funções de entrada e saída de dados
#include <stdlib.h> // Biblioteca para utilidades gerais
#include <math.h> // Biblioteca para funções matemáticas

/*
 * Grupo:
 * ALAN DIAS CHAGAS            RA: 20870938
 * ANA PAULA DOS SANTOS SOUZA  RA: 20894639
 * IGOR CASTRO SANTILLI        RA: 20909361
 */


#define TAM 5 // Tamanho total para percorrer todo um vetor em uma estrutura de repetição

double deposito[10]; // declaração de variável global para armazenar depósitos 
int tempo[10]; // declaração de variável global para armazenar os meses dos depósitos
double saldo; // declaração de variável global para armazenar saldo final
int t_s; // declaração de variável global para armazenar mês final

static double newton(double epsilon); // Protótipo da função newton

int main() // função principal
{
  double e = 0.0; // declaração do valor de precisão
  int i = 0; // declaração do contador do laço for
  char perc = '%'; // símbolo de porcentagem
   
  printf("Digite os valores dos depósitos e o mês de cada depósito\n"); // Imprime pedido para entrada de dados

  for(i = 0; i < TAM; i++) // estrutura de repetição para armazenar valores de acordo com o Tamanho definido (TAM)
  {
    printf("Valor:"); // Imprime "Valor" para o usuario digitar o valor de depósito 
    scanf(" %lf", &deposito[i]); // Armazena valor de depósito na variável deposito[i] informado

    printf("Mês:"); // Imprime "Mês" para o usuario passar o mês do depósito correspondente
    scanf(" %d", &tempo[i]); // Armazena na variável tempo[i] mês correspondente ao depósito informado

    printf("\n"); // Quebra de linha
  }

  printf("Saldo:"); // Imprime "Saldo" para o usuario digitar o saldo final
  scanf(" %lf", &saldo); // Armazena saldo final na variável saldo

  printf("Mês Saldo:"); // Imprime "Mês Saldo" para o usuario digitar o mês do saldo correspondente 
  scanf(" %d", &t_s); // Armazena na variável t_s o mês informado 
  
  printf("\nValor de Precisão:"); // Imprime "Valor de Precisão" para o usuário
  scanf(" %lf", &e); // Armazena valor de precisão informado na variável e

  // Imprime na tela a taxa de juros anual, chamando a função newton e passando como parâmetro o valor de precisão
  printf("\nTaxa de juros anual é de aproximadamente: %.2lf%c\n", newton(e), perc);

  return 0; // FIM do programa, retorno da função main
}

static double newton(double epsilon) // "Corpo" da função newton 
{
  double jkn = 0.5; // declaração de variável local, jkn = 0.5 é um valor de aproximação inicial de juros
  double aux = 0.0; // declaração de variável local auxiliar
  double F = 0.0; // declaração de variável local, função f(x)
  double f = 0.0; // declaração de variável local, função derivada f'(x)

  double modulo = 0.0; // declaração de variável local

  int cont = 0; // declaração de variável local, contador. 

  if(epsilon >= 0 && epsilon <= 1) // estrutura de conditional if, verifica se valor de precisão é válido  
  {
    do // inicio da estrutura de repetição "do while"
    {
      F = f = 0.0; // inicializa as funções para calcular o novo valor de juros 

      for(cont = 0; cont < TAM; cont++) // estrutura de repetição for, para cálculo de depósitos e meses armazenados 
      {
        F += deposito[cont]*pow(1 + jkn, t_s - tempo[cont]); // cálculo da função f(jkn)
        f += (t_s - tempo[cont])*deposito[cont]*pow(1 + jkn, t_s - tempo[cont] -1); // cálculo da função derivada f'(jkn)
      }
      
      F -= saldo; // subtrai da função o valor do saldo final

      aux = jkn; // armazena o valor de jkn em uma variável auxiliar, para calcular o próximo valor de precisão de juros
      jkn = jkn - (F/f); // cálculo do valor de juros 

      modulo = (jkn - aux) * (jkn < aux ? (-1) : 1); // módulo de jkn(próximo) - jkn(corrente) 

    } while(modulo >= epsilon); // reinicia o looping caso o modulo seja maior ou igual a epsilon(valor de precisao passado como parâmetro para função

    return jkn*100; // retorna o valor de juros com base no valor de precisão

  }

  return -1; // retorna -1 caso o valor de precisão não seja válido(epsilon >= 0 && epsilon <= 1)
}
