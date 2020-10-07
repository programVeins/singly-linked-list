#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#define MAKENODE (node*) malloc (sizeof(node));

node* create(genericType toBoNoded)
{
    node* thisNode = MAKENODE;
    thisNode->data = toBoNoded;
    thisNode->next = NULL;
    return thisNode;
}

genericType displayNode(node* toBeDisplayed)
{
    genericType dataPointer = toBeDisplayed->data;
    return dataPointer;
}

node* insertBeginning(node* head, genericType toBeInserted)
{
    node* startNode = create(toBeInserted);
    startNode->next = head;
    head = startNode;

    return head;
}

int insertEnding(node* head, genericType toBeInserted)
{
    node* endNode = create(toBeInserted);
    node* slider = head; //Creates a slider that points to head
    endNode->next = NULL;

    while(slider->next != NULL)
    {
        slider = slider->next; //Traversal, moves the slider across the list till it's 'next' points to NULL
    }
    slider->next = endNode; //Assigns endNode as the final node
    

    return slider == NULL ? -1 : 0; //Conditional return, returns -1 (Fail) if slider is NULL else returns 0 (Success)
}

int insertAfter(node* head, genericType toBeInserted, genericType afterNodeWithData)
{
    node* tempNode = create(toBeInserted);
    node* slider = head;

    while((slider->data != afterNodeWithData) && (slider->next != NULL))
    {
        slider = slider->next; //Traversal
    }
    if((slider->data != afterNodeWithData) || (slider == NULL))
    {
        return -1;
    }
    tempNode->next = slider->next;
    slider->next = tempNode;

    return 0; 

}

node* deleteNode(node* head, node* toBeDeleted)
{
    node* slider = head;

    if(slider == toBeDeleted)
    {
        head = slider->next;
        free(slider); //De-allocates memory space of head
        return head;
    }

    while(slider->next != toBeDeleted)
    {
        slider = slider->next;
    }
    slider->next = toBeDeleted->next;
    free(toBeDeleted); //De-allocates memory space of node

    return head;
}

node* searchNode(node* head, genericType toBeSearched)
{
    node* slider = head;

    while(slider->next != NULL)
    {
        if(slider->data == toBeSearched)
        {
            return slider;
        }
        slider = slider->next;
    }
    if(slider->data == toBeSearched)
    {
        return slider;
    }
    return NULL;
}