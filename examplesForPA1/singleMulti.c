#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){

  int result = 0;
  int N = 4;
  int K = 2;
  int i = 0;
  int j = 0;
  int k = 2;
  int Y[N];
  int XXX[K][N];
  
  printf("Y:\n");
  for(j = 0; j < N; j++){
      k++;
      Y[j] = k+3;
      printf("%d\t",Y[j]);
      
    }
    printf("\n");
  
    printf("XXX:\n");
  for(i = 0; i < K; i++){
    for(j = 0; j < N; j++){
      k++;
      XXX[i][j] = k;
      printf("%d\t", XXX[i][j]);
      
    }
    printf("\n");
  }
      printf("\n");

  
  
  int W[K];
  for(i = 0; i < K; i++){
    //for(j = 0; j < K; j++){
      for(k = 0; k < N; k++){
	result += XXX[i][k] * Y[k];
      }
      W[i] = result;
      printf("%d\t",W[i]);
      result = 0;
    //}
  }
    printf("\n");

  return 0;
}