#include <stdio.h>

void sum(double a, double b) {
  printf("Resultado: %.2f + %.2f = %.2f\n", a, b, a + b);
}

void subtract(double a, double b) {
  printf("Resultado: %.2f - %.2f = %.2f\n", a, b, a - b); 
}

void multiply(double a, double b) {
  printf("Resultado: %.2f * %.2f = %.2f\n", a, b, a * b);
}

void divide(double a, double b) {
  printf("Resultado: %.2f / %.2f = %.2f\n", a, b, a / b);
}

void clean_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void int_input(int *ptr) {
  while (scanf("%d", ptr) != 1) { 
    printf("Opção inválida! Digite um número de 1 a 5\n");
    clean_buffer();
    printf("Digite novamente: ");
  }
  clean_buffer();
}

void decimal_input(double *ptr) {
  while (scanf("%lf", ptr) != 1) {
    printf("Entrada inválida! Digite um número\n");
    clean_buffer();
    printf("Digite novamente: ");
  }
  clean_buffer();
}

void values_input(double *a, double *b) {
  printf("Digite o primeiro número: ");
  decimal_input(a);
  printf("Digite o segundo número: ");
  decimal_input(b);
}

int continue_program(char *c) {
  while (1) {
    printf("Deseja realizar outra operação? (s/n): ");
    scanf(" %c", c);
    if (*c != 'S' && *c != 's' && *c != 'N' && *c != 'n') {
      printf("Resposta inválida. Por favor, digite 's' para sim ou 'n' para não.\n");
      clean_buffer();
    } else {
      break;
    }
  }
  if (*c == 'n' || *c == 'N') {
    printf("Obrigado por usar a calculadora! Até a próxima.\n");
    return 0;
  } else {
    return 1;
  }
}

int main() {
  double a, b;
  int opt = 0;
  char confirm;
  while (1) {
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção: ");
    int_input(&opt);
    while (opt > 5 || opt < 1) {
      printf("Opção inválida! Digite um número de 1 a 5\n");
      printf("Digite novamente: ");
      int_input(&opt);
    } if (opt == 1) {
      values_input(&a, &b);
      sum(a, b);
    } else if (opt == 2) {
      values_input(&a, &b);
      subtract(a, b);
    } else if (opt == 3) {
      values_input(&a, &b);
      multiply(a, b);
    } else if (opt == 4) {
      values_input(&a, &b);
      if (b == 0) {
        printf("Erro: Divisão por zero não é permitida.\n");
      } else {
        divide(a, b);
      }
    } else if (opt == 5) {
      printf("Obrigado por usar a calculadora! Até a próxima.\n");
      break;
    }
    if (continue_program(&confirm) == 0) {
      break;
    }
  }

  return 0;
}
