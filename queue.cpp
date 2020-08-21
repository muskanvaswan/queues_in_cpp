#include<iostream>
#include<stdio.h>

using namespace std;
struct node
{
  char name[20];
  int age;
  node *link;
}*np, *newptr;
class queue
{
  node *rear, *front,*ptr;
public:
  queue()
  {
    rear= NULL;
    front= NULL;
  }
  node *new_node();
  void queins(node*);
  void quedel();
  void display(node*);
  node* r_front()
  {
    return front;
  }
};
int main()
{
   queue Q;
   node *f;
   char ch;
   while(true)
   {
     newptr = Q.new_node();
     Q.queins(newptr);
     cout<<"\ndo you want to add to the queue? (y/n)  ";
     cin>>ch;
     if(ch=='n')
        break;
   }
   do {
      cout<<"\nthe que now is:\n";
      f=Q.r_front();
      Q.display(f);
      cout<<"\ndo you want to delet first node of queue? (y/n) ";
      cin>>ch;
      Q.quedel();
    } while(ch=='y');
}

node *queue::new_node()
{
  ptr = new node;
  cout<<"enter name: ";
  cin.ignore();
  cin.getline(ptr->name,20);
  cout<<"enter age: ";
  cin>>ptr->age;
  ptr->link= NULL;
  return ptr;
}
void queue::queins(node* np)
{
  if(front==NULL)
  {
    front=rear=np;
  }
  else
  {
    rear->link = np;
    rear=np;
  }
}
void queue::quedel()
{
  if(front==NULL)
  {
    cout<<"UNDERFLOW!";
  }
  else
  {
    ptr = front;
    front = front->link;
    delete ptr;
  }
}
void queue::display(node *np)
{
  while(np!=NULL)
  {
    cout<<np->name<<"-";
    cout<<np->age<<"->  ";
    np= np->link;
  }
  cout<<"ends here!";
}
