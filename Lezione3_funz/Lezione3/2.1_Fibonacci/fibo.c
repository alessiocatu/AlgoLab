#include <stdio.h>

int fibonacci(int i);
int fibonacci_iter(int i);
int count = 0;

int main(void) {
  int fibo;

  scanf(" %d", &fibo);
  printf("%d %d\n", fibonacci(fibo), count);
  printf("%d\n", fibonacci_iter(fibo));
}

int fibonacci(int i) {
  count++;
  if (i==1 || i==2)
    return 1;
  return fibonacci(i-1)+fibonacci(i-2);
}

int fibonacci_iter(int i){
  if(i == 1 || i == 2)
    return 1

}
