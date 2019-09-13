#include<stdio.h>
#include<stdlib.h>

//#define SIZE 10000

struct node{
  int data;
  //struct node *hashNode;//?
  struct node *next;
};

struct dataArray{
  //int index;
  struct node *head;
  //int key;
};

struct dataArray *hashArray;

int main(int argc, char** argv){
  hashArray = (struct dataArray*)calloc(10000, sizeof(struct dataArray));
  if(argc != 2){
    return 0;
  }
  
  FILE * fPointer;
  fPointer = fopen(argv[1],"r");
  char id;
  int numb;
  
  if(fPointer == NULL){
    printf("error\n");
    return 0;
  }
  
  while(!feof(fPointer)){//until reach the end of the file
    fscanf(fPointer, "%c\t%d\n", &id, &numb);
    if(id == '\0'){
      //do not know if needed as second.c
      return 0;
    }
    
    int hashIndex;
    if(numb < 0){
        hashIndex = - (numb % 10000);
    }else{
      hashIndex = numb % 10000;
    }
    
    if(id == 'i'){//insert
      //create a link
      struct node *insert = (struct node*)malloc(sizeof(struct node));
      insert->data = numb;

      if(hashArray[hashIndex].head == NULL){
	hashArray[hashIndex].head = insert;
	insert->next = NULL;
	printf("inserted\n");
	
      }else{//else if head != NULL
	struct node *current = hashArray[hashIndex].head;
	
	if(current->data == numb){
	  printf("duplicate\n");
	  
	}else{//else if current->data != numb
	  if(current->next == NULL){
	    current->next = insert;
	    insert->next = NULL;
	    printf("inserted\n");
	  
	  }else{//else if current->next != NULL
	    //there are multiple nodes in this linked list	    
	    while(current != NULL){
	      if(current->data == numb){
		printf("duplicate\n");
		break;
	      }
	      if(current->next == NULL){
		current->next = insert;
		insert->next = NULL;
		printf("inserted\n");
		break;
	      }
	      current = current->next;
	    }
	//check if this index has a linked list, then check is there is any duplicate
	//if does, print "duplicate
	//if doesn't, linked with other integers
	  }
	}
      }
      //free(insert);
      
    }else if(id == 's'){//search
      struct node* current = hashArray[hashIndex].head;
      
      if(current == NULL){
	//no link list at all
	printf("absent\n");
      }else{
	int count = 0;
	while(current != NULL){
	  if(current->data == numb){
	    printf("present\n");
	    count++;
	    break;
	  }
	  current = current->next;
	}//end while
	if(count == 0){
	  printf("absent\n");
	}
      }
      
    }else{//error
      printf("error\n");
    }
  }//end while
  
  //free(hashArray);
  fclose(fPointer);
  return 0;
}
