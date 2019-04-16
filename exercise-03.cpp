/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Exercise-03
* Tgl : 16 04 2019
*/

#include<iostream>
using namespace std;
 
typedef struct CDLL
{
  char info;
  CDLL *next, *prev;
} *listptr, *list;
 
void newNode(listptr &pNew)
{
  pNew = new CDLL;
  cout << "info : "; cin >> pNew->info;
  pNew->next = NULL;
  pNew->prev = NULL;
}
void Push(list &head, listptr &pAdd)
{
  listptr last;
  if(head==NULL)
  {
    head=pAdd;
    pAdd->next=pAdd;
    pAdd->prev=pAdd;
  }
 
  else
  {
    last=head;
    while(last->next!=head)
    {
      last=last->next;
    }
    pAdd->next=head;
    head->prev=pAdd;
    pAdd->prev=last;
    last->next=pAdd;
    head=pAdd;
  }
}
 
void PushBack(list &head, listptr &pAdd)
{
  listptr last;
  if(head==NULL)
  {
    head=pAdd;
    pAdd->next=pAdd;
    pAdd->prev=pAdd;
  }
 
  else
  {
    last=head;
    while(last->next!=head)
    {
      last=last->next;
    }
    pAdd->prev=last;
    last->next=pAdd;
    pAdd->next=head;
    head->prev=pAdd;
  }
}
 
void deleteFront(list &head, listptr &pDel)
{
  listptr last;
  if(head==NULL){cout << "EMPTY!\n";}
 
  else if(head->next==NULL){head=NULL;}
 
  else
  {
    last=head;
    while(last->next!=head)
    {
      last=last->next;
    }
    pDel=head;
    last->next=pDel->next;
    pDel->next->prev=last;
    head=pDel->next;
    pDel->next=NULL;
    pDel->prev=NULL;
  }
}
 
void deleteBack(list &head, listptr &pDel)
{
  listptr last;
  if(head==NULL)
  {
    pDel=NULL;
    cout << "EMPTY!\n";
  }
 
  else if(head->next==NULL){head=NULL;}
 
  else
  {
    last=head;
    while(last->next!=head)
    {
      last=last->next;
    }
    pDel=last;
    head->prev=pDel->prev;
    pDel->prev->next=head;
    pDel->prev=NULL;
    pDel->next=NULL;
  }
}
 
void traverse(list head)
{
  listptr pAid;
  if(head==NULL){cout << "EMPTY\n";}
 
  else
  {
    pAid=head;
    do
    {
      cout << pAid->info << " ";
      pAid=pAid->next;
    }while(pAid!=head);
    cout << "\n";
  }
}
 
int main()
{
  list meh=NULL;
  listptr p=NULL;
 
  char options;
  char s;
 
  do
    {
      for (int i=0; i<20; i++) {cout << "-";}
      cout << "\nChoose Option!"
           << "\n(1) Push"
           << "\n(2) Push Back"
           << "\n(3) Delete Front"
           << "\n(4) Delete Back"
           << "\n(5) Output Elements\n";
      for (int i=0; i<20; i++) {cout << "-";}
      cout << "\n(|) "; cin >> options;
      switch (options)
        {
          case '1' :
            newNode(p);
            Push(meh, p);
            break;
       
          case '2' :
            newNode(p);
            PushBack(meh, p);
            break;
 
          case '3' :
            deleteFront(meh, p);
			traverse(meh);
            break;
 
          case '4' :
            deleteBack(meh,p);
			traverse(meh);
            break;
 
          case '5' :
            traverse(meh);
            break;
 
          default:
            break;
        }
    }while(options!='0');
}