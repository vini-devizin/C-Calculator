#include <stdio.h>

void sum(int a, int b) {
  printf("Resultado: %d + %d = %d\n", a, b, a + b);
}

void subtract(int a, int b) {
  printf("Resultado: %d - %d = %d\n", a, b, a - b); 
}

void multiply(int a, int b) {
  printf("Resultado: %d * %d = %d\n", a, b, a * b);
}

void divide(int a, int b) {
  printf("Resultado: %d / %d = %d\n", a, b, a / b);
}

void clean_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void int_input(int situation, int *ptr) {
  /*
  situation == 0 -> menu input
  situation == 1 -> numbers input
  */
  while (scanf("%d", ptr) != 1) {
    if (situation == 0) {
      printf("Opção inválida! Digite um número de 1 a 5\n");
    } else {
      printf("Entrada inválida! Digite um número\n");
    }
    clean_buffer();
    printf("Digite novamente: ");
  }
  clean_buffer();
}

void values_input(int *a, int *b) {
  printf("Digite o primeiro número: ");
  int_input(1, a);
  printf("Digite o segundo número: ");
  int_input(1, b);
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
  int a, b;
  int opt = 0;
  char confirm;
  while (1) {
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\nOpção: ");
    int_input(0, &opt);
    while (opt > 5 || opt < 1) {
      printf("Opção inválida! Digite um número de 1 a 5\n");
      printf("Digite novamente: ");
      int_input(0, &opt);
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
