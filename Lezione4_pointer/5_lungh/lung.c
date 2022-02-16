#include <stdio.h>

int lung_stringa (char *s);

int main(void){
  char s[] = {'t','e','s','t','a',' ','d','i','\0'};
  printf("%d\n", lung_stringa(s));
  return 0;
}

int lung_stringa (char *s) {
  int count = 0;
  int i = 0;
  while(s[i] != '\0'){
    count++;
    i++;
  }
  return count;
}
