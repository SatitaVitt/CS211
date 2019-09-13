#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[]){
  
  FILE * trainf;
  
  trainf = fopen(argv[1], "r");
  
  int K = 0;
  int N = 0;
  int i = 0;
  int j = 0;
  double temp = 0;
  
  fscanf(trainf, "%d\n%d", &K, &N);
  printf("K: %d, N: %d\n", K, N);
  double X[N][K+1];
  double Y[N];
  
  
  for(i = 0; i < N; i++){
    X[i][0] = 1;
    for(j = 1; j < K+1; j++){
      fscanf(trainf, "%lf,", &temp);
      X[i][j] = temp;
    }
    fscanf(trainf, "%lf\n", &temp);
    Y[i] = temp;
    
  }
  
  printf(" Y:\n");
  
  for(j = 0; j < K; j++){
      //for(i = 0; i < K; i++){
	printf("%f,",Y[j]);
      //}
  }
  
  printf("\n\n\n X:\n");
  
  for(j = 0; j < N; j++){
      for(i = 0; i < K+1; i++){
	printf("%f,",X[j][i]);
      }
      printf("\n");
  }
  
  //W = (X^T * X)^(-1) * X^T * Y
  K = K+1;
  //X^T
  double XT[K][N];
  for(i = 0; i < N; i++){
    for(j = 0; j < K; j++){
      XT[j][i] = X[i][j];
    }
  }
  
  
  printf("\n\n\n XT:\n");
  
  for(j = 0; j < K; j++){
      for(i = 0; i < N; i++){
	printf("%f,",XT[j][i]);
      }
      printf("\n");
  }
  
  
  //X^T * X matrix multiplication
  double XTX [K][K];
  int k = 0;
  double result = 0;
  double number = 0;
  for(i = 0; i < K; i++){
    for(j = 0; j < K; j++){
      for(k = 0; k < N; k++){
	number = XT[i][k];
	//printf("XT[i][k]: %f\t X[k][j]:%f\n",number, X[k][j]);
	result = result + number * X[k][j];
      }
      //printf("product: %f\n", result);
      XTX[i][j] = result;
      result = 0;
    }
  }
  
  printf("\n\n\n XTX:\n");
  
  for(j = 0; j < K; j++){
      for(i = 0; i < K; i++){
	printf("%f,",XTX[j][i]);
      }
      printf("\n");
  }
  
  return 0;
}


