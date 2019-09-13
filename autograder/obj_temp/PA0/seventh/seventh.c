#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  
  if(argc == 1){
    printf("error\n");
    return 0;
  }
  
  int i = 0;
  char* input;
  int length = 0;
  
  for(i = 1; i < argc; i++){
    input = argv[i];
    length = strlen(input);
    printf("%c", input[length-1]);
  }
  printf("\n");
  return 0;
}