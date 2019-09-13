#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){

if(argc != 2){
return 0;
}

FILE * fPointer;
fPointer = fopen(argv[1], "r");

if(fPointer == NULL){
  printf("error\n");
  return 0;
}

int totalNum = 0;
int given = 0;
int i = 0;

fscanf(fPointer, "%d\n", &totalNum);
int array[totalNum];  

while(!feof(fPointer)){
  fscanf(fPointer, "%d\t", &given);
  array[i] = given;
  i = i+1;
}
  
  i = 0;
  int j = 0;
  for(i = 0; i < totalNum; i++){
    for(j = i+1; j < totalNum; j++){
      if(array[i] > array[j]){
	given = array[i];
	array[i] = array[j];
	array[j] = given;
      }
    }
  }
  
  for(i = 0; i <(totalNum-1); i++){
    printf("%d\t", array[i]);
  }
  printf("%d", array[i]);
  printf("\n");
  
  fclose(fPointer);
  return 0;
}


