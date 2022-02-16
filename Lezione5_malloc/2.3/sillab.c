#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
  char *s = argv[1];
  int n = strlen(s);
  for(int i=0; i<n; i++){
    printf("%c", s[i]);
    if(s[i] > s[i+1] && s[i+1] != '\0')
      printf("-");
  }
  printf("\n");
  return 0;
}
