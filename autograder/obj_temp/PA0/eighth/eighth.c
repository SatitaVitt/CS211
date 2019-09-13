#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  int height;
  struct node *left;
  struct node *right;
};

int main(int argc, char* argv[]){
  
  if(argc != 2){
    printf("error\n");
    return 0;
  }
  
  FILE * fp;
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    printf("error\n");
    return 0;
  }

  char c = '\0';
  int num = 0;
  struct node *root = malloc(sizeof(struct node));
  fscanf(fp, "%c\t%d\n", &c, &num);
  //first input
  if(c == 'i'){
    root->data = num;
    root->height = 1;
    printf("inserted %d\n", root->height);
  }else if(c == 's'){
    printf("absent\n");
  }else{
    printf("error\n");
  }

  struct node *current;
  //struct node *parent;

  while(!feof(fp)){
    fscanf(fp, "%c\t%d\n", &c, &num);
    current = root;
    //parent = NULL;
    if(c == 'i'){
      //insert
      struct node *insert = malloc(sizeof(struct node));
      insert->data = num;
	while(current != NULL){
	  if(current->data < num){
	    //right
	    if(current->right != NULL){
	      current = current->right;
	      //parent = current;
	    }else{
	      insert->height = current->height+1;
	      current->right = insert;
	      //h = insert->height;
	      printf("inserted %d\n", insert->height);
	      break;
	    }
	  }else if(current->data > num){
	    //left
	    if(current->left != NULL){
	      current = current->left;
	    }else{
	      insert->height = current->height+1;
	      current->left = insert;
	      //h = insert->height;
	      printf("inserted %d\n", insert->height);
	      break;
	    }
	  }else/*when current->data == num*/{
	    printf("duplicate\n");
	    break;
	  }
	}//end while1

    }else if(c == 's'){
      //search
      while(current != NULL){
	  if(current->data < num){
	    //right
	    if(current->right != NULL){
	      current = current->right;
	      //parent = current;
	    }else{
	      printf("absent\n");
	      break;
	    }
	  }else if(current->data > num){
	    //left
	    if(current->left != NULL){
	      current = current->left;
	    }else{
	      printf("absent\n");
	      break;
	    }
	  }else/*when current->data == num*/{
	    printf("present %d\n", current->height);
	    break;
	  }
	}//end while1

    }else{
      //error
      printf("error\n");
      //return 0;
    }
  }//end while

  free(root);
  fclose(fp);
  return 0;
}

