//
//  main.cpp
//  iview
//
//  Created by Urmila shinde on 8/21/16.
//  Copyright © 2016 Urmila shinde. All rights reserved.
//

#include <iostream>

typedef struct node{
    int data;
    struct node* next;
}node;

void PrintList(node* head)
{
    node* current = head;
    
    if(current == nullptr)
    {
        std::cout << "List is empty \n";
    }
    
    while(current != nullptr)
    {
       std::cout<< current->data<<"\n";
        //printf("data = %d \n", current->data);
        current = current->next;
        
    }
    
}

void Push(node** head, int data)
{
    struct node* newnode = (node*)malloc(sizeof(struct node));
    
    newnode->data = data;
    newnode->next = *head;
    
    *head = newnode;
    
}

int Pop(node** head)
{
    int data = 0;
    
    struct node* temp = *head;
    
    if(*head != NULL)
    {
        data = temp->data;
        *head = temp->next;
        free(temp);
    }
    else
    {
        std::cout << "List is epmty \n";
    }
    
    return data;
}

int Length(node* head)
{
    struct node* current = head;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    
    return count;
}

int Count(node* head, int data)
{
    int count = 0;
    
    struct node* current = head;
    
    while(current != NULL)
    {
        if(current->data == data)
        {
            count++;
        }
        current = current->next;
    }
    
    return count;
}

void InsertNth(node** head, int n, int data)
{
    struct node* current = *head;
    struct node* temp = current;
    struct node* newnode = (node*)malloc(sizeof(struct node));
    
    int count = 1;
    
    if(current == NULL) {
        
        if( n== 1)
        {
            Push( head, data);
        }
        else{
            
            printf("list is empty \n");
        }
        return;
    }
    
    
    while(current != NULL)
    {
        if(count == n)
        {
            newnode->data = data;
            newnode->next = current;
            temp->next = newnode;
            return;
            
        }
        count++;
        temp = current;
        current = current->next;
        
    }
    
}

void ReverseList(node** head)
{
    struct node* current = *head;
    struct node* next ;
    struct node* temp = *head;
    
    while(current != NULL)
    {
        next = current->next;
        if(current == *head)
        {
            current->next = NULL;
        }
        else
        {
            
            current->next = temp;
            
        }
        temp = current;
        current = next;
        
    }
    
    *head = temp;
}

node* CopyList(node* head)
{
    struct node* newlist = NULL;
    
    struct node* current = head;
    
    struct node* tail = NULL;
    
    while(current != NULL)
    {
        if(newlist == NULL)
        {
            Push(&newlist, current->data);
            tail = newlist;
        }
        else{
            
            Push(&(tail->next), current->data);
            tail = tail->next;
        }
        current = current->next;
    }
    
    
    return(newlist);
}

void DeleteList(node** head)
{
    struct node* temp;
    struct node* current = *head;
    
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);

    }
    
    *head = NULL;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    struct node* head = nullptr;
    
    ReverseList(&head);
    
    printf("Reverse list \n");
    
    PrintList(head);
    
    
    Push(&head, 5);
    
    
    ReverseList(&head);
    
    printf("Reverse list \n");
    
    PrintList(head);


    
    struct node* newlist = nullptr;
    
    struct node* insertlist = nullptr;
    
    int i = 5;
    
    for( i=5; i>=1; i--)
    {
        Push(&head, i);
    }
    
    PrintList(head);
    
    printf("length of the list is %d \n", Length(head));
    
    printf("number of times 2 is in the list is %d \n", Count(head, 6));
    
    //newlist = CopyList(head);
    
    //PrintList(newlist);
    
    ReverseList(&head);
    
    printf("Reverse list \n");
    
    PrintList(head);
    
    //InsertNth(&head, 2, 7);
    
   // std::cout << "after Nth insert \n";
    
   // PrintList(head);
    
   // InsertNth(&insertlist, 3, 8);
    
//    std::cout << "after Nth insert \n";
    
//    PrintList(insertlist);
//    
//    InsertNth(&insertlist, 1, 8);
//    
//    std::cout << "after Nth insert \n";
//    
//    PrintList(insertlist);
//    
//    printf("Popped data is %d \n", Pop(&head));
    
    DeleteList(&head);
//    DeleteList(&newlist);
    
//    std::cout << "after delete \n";
    
//    printf("Popped data is %d \n", Pop(&head));
//    
//    PrintList(head);
//    PrintList(newlist);
    
    
    return 0;
}
