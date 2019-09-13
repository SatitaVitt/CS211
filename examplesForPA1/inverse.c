#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[]){

  FILE * trainf;
  
  trainf = fopen(argv[1], "r");
  
  if(trainf == NULL){
    printf("error\n");
    return 0 ;
  }
  
  int K = 0;
  int N = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  double temp = 0;
  
  fscanf(trainf, "%d\n%d", &K, &N);
  printf("K: %d, N: %d\n", K, N);
  double X[N][K];
  
  
  for(i = 0; i < N; i++){
    for(j = 0; j < K; j++){
      fscanf(trainf, "%lf,", &temp);
      X[i][j] = temp;
    }
    fscanf(trainf, "%lf\n", &temp);
    
  }
  
  double XTX1[K][K*2];
  for(i = 0; i < K; i++){
    for(j = 0; j < K*2; j++){
      if(j < K){
	XTX1[i][j] = X[i][j];
      }else{
	if(i == (j-K)){
	  printf("i: %d\t j: %d\n",i,j);
	  XTX1[i][j] = 1;
	}else{
	  XTX1[i][j] = 0;
	}
      }
    }
  }
  
  printf("\nXTX:\n");
  
  for(j = 0; j < K; j++){
      for(i = 0; i < K; i++){
	printf("%f\t",X[j][i]);
      }
      printf("\n");
  }
  
  int z = 0;
  int zz = 0;
  
  
  
  
//Gauss-Jordan Elimination
  int w = 0;
  int count = 0;
  double times = 0;
  for(i = 0; i < K; i++){
      for(j = 0; j < K*2; j++){
	printf("###i:%d\t j:%d\n",i,j);
	if(j < K){

	  if((i != j) && (j < i)){
	    if(XTX1[i][j] != 0){
	      count = 0;
	      for(k = 0; k < K; k++){
		printf("**k:%d\t XTX1[i][j]:%f**\n",k,XTX1[i][j]);
		if(XTX1[i][j] == XTX1[k][j] && i != k){
		   count++;
		  for(w = 0; w < K*2; w++){
		    XTX1[i][w] = XTX1[i][w] - XTX1[k][w];
		  }
		  break;
		}
	      }//end for-loop for k
	      if(count == 0){
		printf("count == 0\t XTX1[i][j]:%f\n",XTX1[i][j]);
		for(k = 0; k< K; k++){
		  printf("kkkkkk:%d\t [k][j]:%f\n",k,XTX1[k][j]);
		  if(XTX1[k][j] == 1){
		    printf("k = %d\n", k);
		    times = XTX1[i][j];
		    for(w = 0; w < K*2; w++){
		      XTX1[i][w] = XTX1[i][w] - (times*XTX1[k][w]);
		    }
		    break;
		  }
		}
		printf("count == 0\t XTX1[i][j]:%f\n",XTX1[i][j]);

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
	if(i == 2){
	printf("\n\n ** XTX1 after *JUSTNEEDTO CHECK* time go over:\n");
      for(z = 0; z < K; z++){
	for(zz = 0; zz < K*2; zz++){
	  printf("%f\t",XTX1[z][zz]);
	}
	printf("\n");
      }
      printf("\n");
      }
      }
      
      printf("\n\n ** XTX1 after *MIDDLE* time go over:\n");
      for(z = 0; z < K; z++){
	for(zz = 0; zz < K*2; zz++){
	  printf("%f\t",XTX1[z][zz]);
	}
	printf("\n");
      }
      printf("\n");
      
      
  }
  
  printf("\n\n ** XTX1 after *FIRST* time go over:\n");
  for(j = 0; j < K; j++){
      for(i = 0; i < K*2; i++){
	printf("%f\t",XTX1[j][i]);
      }
      printf("\n");
  }
  //Go-Over to make LHS be identity matrix
  double tt = 0;
  for(i = K-2; i >= 0; i--){
      for(j = K-1; j >= 0; j--){
	count = 0;
	if(j < K){
	  
	  if(i != j && j > i){
	    
	    if(XTX1[i][j] != 0){
	      
		printf("XTX1[i][j]:%f\n",XTX1[i][j]);
		tt = XTX1[i][j];
		for(k = 0; k< K; k++){
		  printf("k:%d\t [k][j]:%f\n",k,XTX1[k][j]);
		  if(XTX1[k][j] == 1){
		    printf("k = %d\n", k);
		    for(w = 0; w < K*2; w++){
		      XTX1[i][w] = XTX1[i][w] - (tt * XTX1[k][w]);
		    }
		    break;
		  }
		}
		printf("count == 0\t XTX1[i][j]:%f\n",XTX1[i][j]);
	    }/*end <XTX1[i][j] != 0>*/
	    
	  }/*end <i != j && i < j>*/
	
	}
	
	printf("\n\n ** XTX1 after *MIDDLE222* time go over:\n");
      for(z = 0; z < K; z++){
	for(zz = 0; zz < K*2; zz++){
	  printf("%f\t",XTX1[z][zz]);
	}
	printf("\n");
      }
      printf("\n");
	
	
      }
  }
  
  printf("\n\n ** XTX1 after *SECOND* time go over:\n");
  for(j = 0; j < K; j++){
      for(i = 0; i < K*2; i++){
	printf("%f\t",XTX1[j][i]);
      }
      printf("\n");
  }
  
  fclose(trainf);

return 0;
}


