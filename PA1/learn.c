//#include<stdio.h>
//#include<stdlib.h>
#include "learn.h"

int main(int argc, char* argv[]){

  if(argc != 3){
    printf("error\n");
    return 0;
  }
  
  FILE * trainf;
  FILE * testf;
  
  trainf = fopen(argv[1], "r");
  testf = fopen(argv[2], "r");
  
  if(trainf == NULL || testf == NULL){
    printf("error\n");
    return 0 ;
  }
  
  int K = 0;
  int N = 0;
  int i = 0;
  int j = 0;
  double temp = 0;
  
  fscanf(trainf, "%d\n%d", &K, &N);
  //printf("K: %d, N: %d\n", K, N);
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
  
  int M = 0;
  fscanf(testf, "%d\n", &M);
  double testData[M][K+1];
  
  for(i = 0; i < M; i++){
    testData[i][0] = 1;
    for(j = 1; j < K+1; j++){
      fscanf(testf, "%lf,", &temp);
      testData[i][j] = temp;
    }
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
  
  //X^T * X matrix multiplication
  double XTX [K][K];
  int k = 0;
  double result = 0;
  for(i = 0; i < K; i++){
    for(j = 0; j < K; j++){
      for(k = 0; k < N; k++){
	result += XT[i][k] * X[k][j];
      }
      XTX[i][j] = result;
      result = 0;
    }
  }
  
  //(X^T * X)^(-1) inverse
  double XTX1[K][K*2];
  for(i = 0; i < K; i++){
    for(j = 0; j < K*2; j++){
      if(j < K){
	XTX1[i][j] = XTX[i][j];
      }else{
	if(i == (j-K)){
	  XTX1[i][j] = 1;
	}else{
	  XTX1[i][j] = 0;
	}
      }
    }
  }
  
  /*printf("\nXTX:\n");
  
  for(j = 0; j < K; j++){
      for(i = 0; i < K; i++){
	printf("%f\t",XTX[j][i]);
      }
      printf("\n");
  }*/
  
  int z = 0;
  int zz = 0;
  
  
  //Gauss-Jordan Elimination
  int w = 0;
  int count = 0;
  double times = 0;
  for(i = 0; i < K; i++){
      for(j = 0; j < K*2; j++){
	if(j < K){

	  if((i != j) && (j < i)){
	    if(XTX1[i][j] != 0){
	      count = 0;
	      for(k = 0; k < K; k++){
		if(XTX1[i][j] == XTX1[k][j] && i != k){
		   count++;
		  for(w = 0; w < K*2; w++){
		    XTX1[i][w] = XTX1[i][w] - XTX1[k][w];
		  }
		  break;
		}
	      }//end for-loop for k
	      if(count == 0){
		for(k = 0; k< K; k++){
		  if(XTX1[k][j] == 1){
		    times = XTX1[i][j];
		    for(w = 0; w < K*2; w++){
		      XTX1[i][w] = XTX1[i][w] - (times*XTX1[k][w]);
		    }
		    break;
		  }
		}
	    }//end if count /*if there is no same number to make ti substract to 0
	    
	    }/*end <XTX1[i][j] != 0>*/
	  }/*end <i != j && i < j>*/
	
	  if(i == j){
	    if(XTX1[i][j] != 1){
	      times = XTX1[i][j];
	      for(k = 0; k < K*2; k++){
		XTX1[i][k] = XTX1[i][k]/times;
		
	      }
	    }
	  }
	}
	
      }
      
  }
  
  //Go-Over to make LHS be identity matrix
  double tt = 0;
  for(i = K-2; i >= 0; i--){
      for(j = K-1; j >= 0; j--){
	count = 0;
	if(j < K){ 
	  if(i != j && j > i){
	    if(XTX1[i][j] != 0){
		tt = XTX1[i][j];
		for(k = 0; k< K; k++){
		  if(XTX1[k][j] == 1){
		    for(w = 0; w < K*2; w++){
		      XTX1[i][w] = XTX1[i][w] - (tt * XTX1[k][w]);
		    }
		    break;
		  }
		}
	    }/*end <XTX1[i][j] != 0>*/
	    
	  }/*end <i != j && i < j>*/
	
	}	
	
      }
  }
  
  //printf("HERE:\n");
  //individualMatrixFor XTX1
  double XTX11[K][K];
  for(i = 0; i < K; i++){
    for(j = 0; j < K; j++){
      XTX11[i][j] = XTX1[i][j+K];
      //printf("%f\t",XTX11[i][j]);
    }
    //printf("\n");
  }
  
  //Matrix Multi XTX11*X^T
  result = 0;
  double XXX[K][N];
  for(i = 0; i < K; i++){
    for(j = 0; j < N; j++){
      for(k = 0; k < K; k++){
	result += XTX11[i][k] * XT[k][j];
      }
      XXX[i][j] = result;
      result = 0;
    }
  }
  
  //printf("W:\n");
  result = 0;
  double ww = 0;
  double W[K];
  for(i = 0; i < K; i++){
    //for(j = 0; j < K; j++){
      for(k = 0; k < N; k++){
	ww = XXX[i][k];
	result += ww * Y[k];
      }
      W[i] = result;
      //printf("%f\t",W[i]);
      result = 0;
    //}
  }
    //printf("\n");

  //output Y = X * W:
  //printf("YY:\n");
  double YY[M];
  result = 0;
  for(i = 0; i < M; i++){
    //for(j = 0; j < K; j++){
      for(k = 0; k < K; k++){
	ww = testData[i][k];
	result += ww * W[k];
      }
      YY[i] = result;
      printf("%0.0f\n",YY[i]);
      result = 0;
    //}
  }
  //printf("\n"); 
  
  
  
  
  
  
  
  
  /*
  
  //print training data file:
  printf("\nX:\n");
  for(j = 0; j < N; j++){
      for(i = 0; i < K; i++){
	printf("%f,",X[j][i]);
      }
      printf("\n");
  }
  printf("\n\n XT:\n");
  for(j = 0; j < K; j++){
      for(i = 0; i < N; i++){
	printf("%f,",XT[j][i]);
      }
      printf("\n");
  }
  
  printf("\n\n\n XTX:\n");
  
  for(j = 0; j < K; j++){
      for(i = 0; i < K; i++){
	printf("%f,",XTX[j][i]);
      }
      printf("\n");
  }
  
  
  
  printf("price:\n");
  for(i = 0; i < N; i++){
    printf("%f, ", Y[i]);
  }
  
  
  */
  
  fclose(trainf);
  fclose(testf);
  
  return 0;

}
