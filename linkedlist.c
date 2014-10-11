#include<stdio.h>
#include<stdlib.h>

struct _node
{
   int data;
   struct node *next;    
};

typedef struct _node node;

static int reverse(node **head)
{
 node *temp= *head;
 node *prev_node = NULL;
 node  *next_node = NULL;
 
  
 while(temp)
 {
  next_node = temp->next;
  temp->next= prev_node;
  prev_node = temp;  
  temp = next_node;    
 }  
   
*head= prev_node;

return 0;       
}

static int insert(node *head, int data)
{
node *temp= head;
node *new_node = malloc(sizeof(node));

while(temp->next)
{
temp = temp->next;
}
           
new_node->data = data;
new_node->next= NULL;
temp->next = new_node;
}

static int print(node *head)
{
while(head)
{
printf("%d ->",head->data);
head = head->next;       
}
printf("null\n");

return 0;
}


int main()
{

node *head = malloc (sizeof(node));
head->data= 1;
head->next = NULL;

insert(head,2);
insert(head,5);
insert(head, 6);
insert(head, 22);

print(head);

reverse(&head);

print(head);

getchar();
return 0;
}
