/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Exercise-02
* Tgl : 16 04 2019
*/

#include <iostream>
using namespace std;
 
typedef struct LinkedList
{
  char info;
  LinkedList* next;
  LinkedList* prev;
} *list, *listptr;
 
void newNode(list& head, listptr& pNew)           
{
  pNew = new LinkedList;
  cout << "Info : "; cin >> pNew->info;                                              
  pNew->next = pNew->prev = NULL;
}
 
void push(list& head, listptr& pAdd)
{
  if(head==NULL){head=pAdd;}
 
  else
  {
    pAdd->next=head;
    head->prev=pAdd;
    head=pAdd;
  }
}
 
void pushBack(list& head, listptr& pAdd)
{
  listptr last;
  if(head==NULL){head=pAdd;}
 
  else
  {
    last=head;
    while (last->next!=NULL)
    {
      last=last->next;
    }
    last->next=pAdd;
    pAdd->prev=last;
  }
}
 
void traverse(list& head)
{
  listptr pOut;
  if(head==NULL){cout << "EMPTY!\n";}
 
  else
    {
      pOut=head;
      do
        {
          cout << pOut->info << " ";
          pOut=pOut->next;
        } while (pOut!=NULL);
      cout << "\n";
    }
}
 
void deleteFront(list& head, listptr& pDel)
{
  if(head==NULL){cout << "EMPTY!\n";}
 
  else if(head->next==NULL)
    {
      pDel=head;
      head=NULL;
    }
 
  else
    {
      pDel=head;
      head=head->next;
      pDel->next=NULL;
    }
}
 
void deleteBack(list& head, listptr pDel)
{
  listptr Last;
  if(head==NULL){cout << "EMPTY!\n";}
 
  else if(head->next==NULL)
  {
    pDel=head;
    head=NULL;
  }
 
  else
  {
    Last=head;
    while (Last->next!=NULL){Last=Last->next;}
    pDel=Last;
    pDel->prev->next=NULL;
    pDel->prev=NULL;
  }
}
 
int main()
{
  listptr p;
  list meh=NULL;
 
  int options;
  char target;
  int f;
   
  do
  {
    for (int i=0; i<20; i++) {cout << "-";}
    cout << "\nChoose Option!"
         << "\n(1)  Push"
         << "\n(2)  Push Back"
         << "\n(3)  Delete Front"
         << "\n(4)  Delete Back"
         << "\n(5) Traverse\n";
    for (int i=0; i<20; i++) {cout << "-";}
    cout << "\n"
         << "(||) ";
    cin >> options;
    switch (options)
      {
        case 1 :
          cout << "(||) Push\n";
          newNode(meh, p);
          push(meh, p);
          break;
       
        case 2 :
          cout << "(||) Push Back\n";
          newNode(meh, p);
          pushBack(meh, p);
          break;
 
        case 3 :
          cout << "(||) Delete Front\n";
          deleteFront(meh, p);
          break;
 
        case 4 :
          cout << "(||) Delete Back\n";
          deleteBack(meh,p);
          break;
 
        case 5 :
          cout << "(||)  Traverse\n";
          traverse(meh);
          break;
 
        default:
          break;
        }
    }while(options!=0);
}