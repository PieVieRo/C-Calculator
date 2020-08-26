/* 
 * This project is made to test out WSL2
 * I'm very bad at C
 * Any feedback is appreciated
 * */

#include <stdio.h>
#include <math.h>

#define ERROR "\033[1;31m"

int add(int first,int second);
int sub(int first,int second);
int div(int first,int second);
int mul(int first,int second);
int power(int first,int second);

int main(int argc, const char **argv){
  if(argc > 4) {
    printf(ERROR);
    printf("Not enough arguments. Expected 3, got %d\n", argc-1);
    printf("Use: \"./calculator [first number] [operation] [second number]\"\n");
    return 1;
  }

  if(argc < 4) {
    printf(ERROR);
    printf("Too many arguments. Expected 3, got %d\n", argc-1);
    printf("Use: \"./calculator [first number] [operation] [second number]\"\n");
    return 1;
  }
  
  for(int i=0; i < sizeof(argv); i++) {
    printf("%d", argv);
  }

  const int first = (int) argv[1];
  const char op = (char) argv[2];
  const int second = (int) argv[3];
  
  printf("first: %i\n", first);
  printf("op: %c, %i\n", op, op);
  printf("second: %i\n", second);

  int answer;
  switch(op) {
    case '+': 
      answer = add(first,second);
      break;
    case '-':
      answer = sub(first,second);
      break;
    case '*':
      answer = mul(first, second);
      break;
    case '/':
      answer = div(first,second);
      break;
    case '^':
      answer = power(first, second);
      break;
    default:
      printf(ERROR);
      printf("Wrong character: %c.\n");
      printf("Characters currently supported:\n");
      printf("+: addition\n");
      printf("-: subtraction\n");
      printf("*: multiplication\n");
      printf("/: division\n");
      printf("^: power\n");
      return 1;
  }
  
  printf("answer: %d\n", answer);

  return 0;
}

int add(int first, int second) {
  return first + second; 
}

int sub(int first, int second) {
  return first - second;
}

int mul(int first, int second) {
  return first * second;
}

int div(int first, int second) {
  return first / second;
}

int power(int first, int second) {
  return (int)pow(first, second);
}
