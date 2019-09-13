#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  int height;
  struct node *left;
  struct node *right;
};

void reheight(struct node *r, int h){

  if(r == NULL){
    return;
  }

  r->height = h;
  if(r->right != NULL){
    reheight(r->right, h+1);
  }
  if(r->left != NULL){
    reheight(r->left, h+1);
  }

  return;
}


int main(int argc, char** argv){

  if(argc != 2){
    printf("error\n");
    return 0;
  }

  FILE * fPointer;
  fPointer = fopen(argv[1], "r");
  if(fPointer == NULL){
    printf("error\n");
    return 0;
  }

  char c = '\0';
  int num = 0;
  struct node *root = malloc(sizeof(struct node));
  fscanf(fPointer, "%c\t%d\n", &c, &num);
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
  struct node *parent;

  while(!feof(fPointer)){
    fscanf(fPointer, "%c\t%d\n", &c, &num);
    current = root;
    parent = NULL;
    if(c == 'i'){
      //insert
      struct node *insert = malloc(sizeof(struct node));
      insert->data = num;
      if(current == NULL){
	current = malloc(sizeof(struct node));
	current->data = num;
	current->height = 1;
	printf("inserted %d\n", current->height);
	root = current;
	continue;
      }
	while(current != NULL){
	  if(current->data < num){
	    //right
	    if(current->right != NULL){
	      current = current->right;
	    }else{
	      insert->height = current->height+1;
	      current->right = insert;
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
	      printf("inserted %d\n", insert->height);
	      break;
	    }
	  }else/*when current->data == num*/{
	    printf("duplicate\n");
	    break;
	  }
	}//end while1

    }else if(c == 's'){
      if(current == NULL){
	printf("absent\n");
      }
      //search
      while(current != NULL){
	  if(current->data < num){
	    //right
	    if(current->right != NULL){
	      current = current->right;
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

    }else if(c == 'd'){
      while(current != NULL){
	  if(current->data < num){
	    //right
	    if(current->right != NULL){
	      parent = current;
	      current = current->right;
	    }else{
	      printf("fail\n");
	      break;
	    }
	  }else if(current->data > num){
	    //left
	    if(current->left != NULL){
	      parent = current;
	      current = current->left;
	    }else{
	      printf("fail\n");
	      break;
	    }
	  }else/*when current->data == num*/{
	    //delete:
	    struct node *target = current;
	    struct node *parentOfTarget;
	    if(current->data != root->data){
	      parentOfTarget = parent;
	    }
	    //target is the target to be deleted
	    if(current->right == NULL){
	      if(current->left == NULL){
		if(current == root){
		  root=NULL;
		  printf("success\n");
		  break;
		}
	      }
	      if(parent->left->data == current->data){
		//while current == target
		if(current->left == NULL){
		  parent->left = NULL;
		  printf("success\n");
		  break;
		}else{
		  parent->left = current->left;
		  printf("success\n");
		  break;
		}
	      }else if(parent->right->data == current->data){
		if(current->left==NULL){
		  parent->right = NULL;
		  printf("success\n");
		  break;
		}else{
		  parent->right = current->left;
		  printf("success\n");
		  break;
		}
	      }
	    }else{
	      current = current->right;
	      while(current != NULL){
		if(current->left == NULL){
		  break;
		}else{
		  parent = current;
		  current = current->left;
		}
	      }//end little while

	      if(target->data == root->data){
		//if deleting root
		current->left = target->left;
		current->height = target->height;
		if(target->right != current){
		  if(current->right != NULL){
		    parent->left = current->right;
		    current->right = NULL;
		  }else{
		    parent->left = NULL;
		  }
		  current->right = target->right;
		}
		root = current;
		reheight(root, 1);//recursive method#2
		printf("success\n");
		break;
	      }

	      if(parentOfTarget->left == target){
		//current is the minimum node
		current->left = target->left;
		current->height = target->height;
		if(target->right != current){
		  current->right = target->right;
		}
		parentOfTarget->left = current;
		parent->left = NULL;
		reheight(root, 1);//recursive method#2

		printf("success\n");
		break;

	      }else if(parentOfTarget->right == target){
		current->left = target->left;
		current->height = target->height;
		if(target->right != current){
		  current->right = target->right;
		}
		parentOfTarget->right = current;
		parent->left = NULL;
		reheight(root, 1);//reheight

		printf("success\n");
		break;
	      }
	  }
	}//end while1
      }
    }else{
      //error
      printf("error\n");
    }
  }//end while

  free(root);
  fclose(fPointer);
  return 0;
}

