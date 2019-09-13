#include <stdlib.h>
#include <stdio.h>

struct node{
  int data;
  struct node *next;
};

int main(int argc, char** argv){
  struct node *head;
  head = NULL;

  if(argc != 2){
    return 0;
    //there's no input
  }

  FILE * fPointer;
  fPointer = fopen(argv[1], "r");
  char id = '\0';
  int numb = 0;

  if(fPointer == NULL){
    printf("error\n");
    return 0;
  }

  while(!feof(fPointer)){//until the end of the file
    fscanf(fPointer, "%c\t%d\n", &id, &numb);
    //printf("print before: id: %c \t numb: %d \n", id, numb);
    if(id == '\0'){
      return 0;
    }
    
    struct node *insert =NULL;
    insert = (struct node*)malloc(sizeof(struct node));
    if(id == 'i'){//insert
      //printf("insert: \n");
      if(head == NULL){
        //if inserting the first node in this linked list
        head = (struct node*)malloc(sizeof(struct node));
        head->data = numb;
        head->next = NULL;
        }else{//if head has data
          if(/*case1*/head->data > numb){//if numb is smaller than head, then insert before head
            //printf("case1 // insert: \n");
            //struct node *insertFront;
            //insertFront = (struct node*)malloc(sizeof(struct node));
            insert->data = numb;
            insert->next = head;
            head = insert; //maybe?
            
          }else if(/*case2*/head->data < numb){//if numb is larger than head, check the next node
            //printf("case2 // insert: \n");
            struct node *prev = NULL;
            struct node *current = head;
            while(current != NULL){//loop through the linked list until find a space to insert numb
              if(current->data > numb){//insert before current
                //struct node *insert = (struct node*)malloc(sizeof(struct node));
                insert->data = numb;
                insert->next = current;
                prev->next = insert;
                break;
              }else if(current->data == numb){//if equal, do nothing
                break;
              }
              prev = current;
              current = current->next;
              if(current == NULL){
                //printf("insert for the last node : \n");
                //struct node *insert1 = (struct node*)malloc(sizeof(struct node));
                insert->data = numb;
                insert->next = NULL;
                prev->next = insert;
                break;
              }
            }//end while
          }else if(/*case3*/head->data == numb){
            //do nothing, should not insert any duplicate values
            //printf("case3 // insert: \n");
            continue;//?
          }//end else if case3
        }//end else
      }//end if head == null
    else if(id == 'd'){//delete
        //printf("delete: \n");
        struct node *now = head;
        struct node *prev1 = NULL;
        if(head == NULL){
          continue;//?
        }
      
      while(now != NULL){
        if(now->data == numb){
          //printf("delete, now.data == numb: \n");
          //delete
          if(prev1 == NULL){
            if(now->next == NULL){
              //if there is only one node in the linked list
              head = NULL;
              break;
            }else{
                //printf("in \n");
		//printf("%d before\n", head->data);
                head = head->next;//as if now = head in the moment
                //printf("%d after\n", head->data);
                break;
		
            }
          }else{//if now != head
            prev1->next = now->next;
            break;//?
          }
      	}
      	prev1 = now;
      	now = now->next;
      }//end while
    }//end else if delete
    else{//if the input is not i or d
      printf("0\n\n");
      return 0;
    }
    //free(insert);
  }
    //display the linked list
  struct node *c = head;
  int count = 0;
  while(c != NULL){
    //printf("display linked list: \n");
    //printf("%d\t", c->data);
    c = c->next;
    count++;
  }
  printf("%d\n", count);
  c = head;
  while(c != NULL){
    //printf("display linked list: \n");
    printf("%d\t", c->data);
    c = c->next;
  }

  fclose(fPointer);
  free(head);
  return 0;
}
