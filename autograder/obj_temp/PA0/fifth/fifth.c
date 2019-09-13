#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  
  if(argc != 2){
    return 0;
  }
  
  FILE * fp;
  fp = fopen(argv[1], "r");
  
  if(fp == NULL){
    printf("error\n");
    return 0;
  }
  
  int n = 0;
  int temp = 0;
  int i = 0;
  int sum1 = 0;
  int sum2 = 0;
  int j = 0;
  fscanf(fp, "%d\n", &n);
  int matrix[n][n];
  
  while(!feof(fp)){
    fscanf(fp, "%d\t", &matrix[i][j]);
    if(temp == matrix[i][j]){
      printf("not-magic\n");
      return 0;
    }
    temp = matrix[i][j];
    j++;
    if(j == n){
      i++;
      j=0;
    }
  }
  
  for(i = 0; i < n; i++){
    sum1 = 0;
    for(j = 0; j < n; j++){
      sum1 = matrix[i][j]+sum1;
    }
    if(sum1 != sum2 && sum2 != 0){
      //printf("1- sum1: %d\t sum2: %d\n", sum1, sum2);
      printf("not-magic\n");
      return 0;
    }
    sum2 = sum1;
  }
  for(j = 0; j < n; j++){
    sum1 = 0;
    for(i = 0; i < n; i++){
      sum1 = matrix[i][j]+sum1;
    }
    if(sum1 != sum2 && sum2 != 0){
      //printf("2- sum1: %d\t sum2: %d\n", sum1, sum2);
      printf("not-magic\n");
      return 0;
    }
    sum2 = sum1;
  }
  sum1 = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if((i + j) == (n-1)){
      sum1 = matrix[i][j]+sum1;
      }
    }
    
  }
  if(sum1 != sum2){
      //printf("3- sum1: %d\t sum2: %d\n", sum1, sum2);
      printf("not-magic\n");
      return 0;
  }
  printf("magic\n");
  return 0;
}
