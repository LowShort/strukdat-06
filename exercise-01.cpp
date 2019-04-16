/*
* Author : Muhammad Iqbal Alif Fadilla
* NPM : 140810180020
* Kelas : B
* Deskripsi : Exercise-01
* Tgl : 16 04 2019
*/

#include<iostream>
using namespace std;
 
typedef struct LinkedList
{
    char info;
    LinkedList* next;
}   *List, *listptr;
 
void createList(List&);
void newNode(List&, listptr&);
void push(List&, listptr&);
void pushBack(List&, listptr&);
void traverse(List&);
void deleteFront(List&, listptr&);
void deleteBack(List&, listptr&);
 
int main()
{
    listptr p;
    List meh;
 
    createList(meh);
 
    char options;
    char s;
    int f;
   
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
        cout << "\n"
             << "(|) ";
        cin >> options;
        switch (options)
        {
            case '1' :
                newNode(meh, p);
                push(meh, p);
                traverse(meh);
                break;
       
            case '2' :
                newNode(meh, p);
                pushBack(meh, p);
				traverse(meh);
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
    }while(options=='1'||options=='2'||options=='3'||options=='4'||options=='5');
}
 
void createList(List& head)
{
    head=NULL;
}
 
void newNode(List& head, listptr& pNew)
{
    pNew=new LinkedList;
    cout << "\nInput Character!\n";
    cin >> pNew->info;
    pNew->next=NULL;
}
 
void push(List& head, listptr& pAdd)
{
    if(head==NULL)
        head=pAdd;
    else
        pAdd->next=head;
        head=pAdd;
}
 
void pushBack(List& head, listptr& pAdd)
{
    listptr Last;
    if(head==NULL){head=pAdd;}
 
    else
    {
        Last=head;
        while(Last->next!=NULL)
            Last=Last->next;
        Last->next=pAdd;
    }
}
 
 
void traverse(List& head)
{
    listptr pAid;
    if(head==NULL)
        cout << "EMPTY\n";
    else
    {
        pAid=head;
        do
        {
            cout << pAid->info << " ";
            pAid=pAid->next;
        }while(pAid!=NULL);
        cout << "\n";
    }
}
 
void deleteFront(List& head, listptr& pDel)
{
  if(head==NULL) {cout << "EMPTY!\n";}
 
  else if(head->next==NULL)
  {
    pDel=head;
    head=NULL;
  }
 
  else
  {
    pDel=head;
    head=pDel->next;
    pDel->next=NULL;
  }
}
 
void deleteBack(List& head, listptr& pDel)
{
  listptr Last, preLast;
  if(head==NULL){cout << "EMPTY!\n";}
 
  else if(head->next==NULL)
  {
    pDel=head;
    head=NULL;
  }
  else
  {
    Last=head;
    preLast=NULL;
    while(Last->next!=NULL)
    {
        preLast=Last;
        Last=Last->next;
    }
    preLast->next=NULL;
  }

}