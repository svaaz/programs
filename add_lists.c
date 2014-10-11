static unsigned int add(node *head1, node *head2)
{
unsigned int num1 =0;
unsigned int num2 = 0;


while(head1)
{
num1 = (num1 *10 )+ head1->data;
head1 = head1->next;
}
           
while(head2)
{
num2 = (num2 *10 )+ head2->data;
head2 = head2->next;
}

return (num1+num2);
  
}
