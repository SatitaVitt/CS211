#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node{
  int data;
  char letter;
  struct node *next;
};

int main(int argc, char* argv[]){

  struct node *head;
  head = NULL;
  struct node *current;
  current = head;
  
if(argc != 2){
printf("error\n");
exit(0);
}

int size = strlen(argv[1]);
//printf("size: %d\n",size);
int resultCount = 0;

int i = 0;
int count = 1;
char prev = argv[1][0];

for(i = 1; i < size+1; i++){
  if(isdigit(argv[1][i])){
    printf("error\n");
    exit(0);
  }
  prev = argv[1][i-1];
  //printf("prev: %c\n", prev);
  if(argv[1][i]==prev){
    count++;
  }else{
    if(head == NULL){
      head = (struct node*)malloc(sizeof(struct node));
      head->letter = prev;
      head->data = count;
      current = head;
      resultCount = resultCount+2;
      count = 1;
    }else{
      current->next = (struct node*)malloc(sizeof(struct node));
      current = current->next;
      current->letter = prev;
      current->data = count;
      resultCount = resultCount+2;
      count = 1;
    }    
  }
}

//printf("resultCount: %d\n", resultCount);
if(resultCount < size){
  current = head;
  while(current != NULL){
    printf("%c%d",current->letter,current->data);
    current = current->next;
  }
  printf("\n");
}else{
  printf("%s\n", argv[1]);
}

free(head);
//free(current);
return 0;
}
