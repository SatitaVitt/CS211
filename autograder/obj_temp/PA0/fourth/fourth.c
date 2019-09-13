#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  int i = 0;
  int j = 0;
  int count = 0;
  int exp = 0;
  fscanf(fp, "%d\n", &n);
  int matrix[n][n];
  int matrix2[n][n];
  int matrix3[n][n];
  
  while(!feof(fp)){
    fscanf(fp, "%d\t", &matrix[i][j]);
    matrix2[i][j] = matrix[i][j];
    count++;
    j++;
    if(j == n){
      i++;
      j=0;
    }
    if(count == n*n){
      fscanf(fp, "%d", &exp);
    }
  }
    
  int k = 0;
  int sum = 0;
  int times = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      sum = 0;
      for(k = 0; k<n; k++){
	sum += matrix[i][k] * matrix2[k][j];
      }
      matrix3[i][j] = sum;      
    }
  }
  
  if(exp == 0){
    for(i = 0; i < n; i++){
	for(k = 0; k<n; k++){
	  printf("1\t");
	}
	printf("\n");
    }
    return 0;
  }else if(exp == 1){
    for(i = 0; i < n; i++){
	for(k = 0; k<n; k++){
	  printf("%d\t", matrix[i][k]);
	}
	printf("\n");
    }
    return 0;
  }

  if(exp == 2){
    
    for(i = 0; i < n; i++){
	for(k = 0; k<n; k++){
	  printf("%d\t", matrix3[i][k]);
	}
	printf("\n");
    }
    times = 0;
  }else{
    times = exp - 2;
    
    while(times != 0){
           
      //put matrix3 into matrix and matrix2 remain the same
      for(j = 0; j < n; j++){
	  for(k = 0; k<n; k++){
	    matrix[j][k] = matrix3[j][k];
	  }
	}      
	
      //multiplication
      for(i = 0; i < n; i++){
	for(j = 0; j < n; j++){
	  sum = 0;
	  for(k = 0; k<n; k++){
	    sum += matrix[i][k] * matrix2[k][j];
	  }
	  matrix3[i][j] = sum;      
	}
      }
      times = times - 1;
    }
    
    for(i = 0; i < n; i++){
	for(k = 0; k<n; k++){
	  printf("%d\t", matrix3[i][k]);
	}
	printf("\n");
    }
  }
  
  
  return 0;
}


  
