#include <stdio.h>
#include <string.h>

void smallest_largest (char *s[], int n, char **smallest, char **largest);

int main(void){
  char *s[] = {"ciao","come","stai","tutto","bene", "?"};
  int n = 6;
  char **smallest, **largest;
  smallest_largest(s, n, smallest, largest);
  printf("%s, %s\n", *smallest, *largest);

  return 0;
}

void smallest_largest (char *s[], int n, char **smallest, char **largest){
  for(int i=0; i<n; i++){
    if(strcmp(s[i], *smallest) < 0){
      *smallest = s[i];
    }
    if(strcmp(s[i], *largest) > 0){
      *largest = s[i];
    }
  }
}
