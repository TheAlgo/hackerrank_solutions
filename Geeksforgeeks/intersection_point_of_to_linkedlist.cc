void removeLoop(Node* head,Node* loop)
{
    //Node* ptr1,ptr2;
    Node* ptr1=head;
    Node* ptr2=loop;
    while(ptr1!=ptr2)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    ptr1=loop;
    while(ptr1->next!=ptr2)
    ptr1=ptr1->next;
    
    ptr1->next=NULL;
    
}
void removeTheLoop(Node *head)
{
     Node* fast=head;
     Node* slow=head;
     
     while(fast!=NULL && fast->next!=NULL)
     {
         slow=slow->next;
         fast=fast->next->next;
         if(slow==fast)
         {
             removeLoop(head,slow);
             return;
         }
     }
}
