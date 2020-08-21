
#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include <string.h>

using namespace std;

const int size_=10;
int Front=-1, rear=-1;

void Insert();
void Delete();
void Display();
void Main_Menu();

struct book
{
    long accno;                 //book accession number
    char title[25];             //book title
}cQueue[size_];

void Insert()
{
    char ch='y';
    int acc_no;
    char Title[25];
    cout<<"\n Enter Book accession number: ";
    cin>>acc_no;
    cin.get();
    cout<<"\n Enter book title: ";
    cin.getline(Title, 25);
    if((Front==0 && rear==size_-1)||(Front==rear+1))
    {
        cout<<"\n OVERFLOW!!!";
        cout<<"\n Do you want to go back to the Main menu? (y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
            Main_Menu();
        else
            exit(0);
    }
    else
        if(rear==-1)
            Front=rear=0;
        else
            if(rear==size_-1)
                rear=0;
            else
                rear++;
    cQueue[rear].accno=acc_no;
    strcpy(cQueue[rear].title, Title);
    Display();
}

void Display()
{
    char ch='y';
    int i=0;
    cout<<"\n Circular Queue is: \n"<<"( Front shown as >>>, Rear shown as <<< AND free space as - )\n";
    if(Front==-1)
    {
        cout<<"\n UNDERFLOW!!!";
        exit(0);
    }
    else
        if(rear>=Front)
    {
        for(i=0; i<Front; i++)
            cout<<"-";
        cout<<" >>> ";
        for(i=Front; i<rear; i++)
            cout<<cQueue[i].accno<<"\t"<<cQueue[i].title<<" <- ";
        cout<<cQueue[rear].accno<<"\t"<<cQueue[rear].title<<" <<< "<<endl;
    }
        else
        {
            for(i=0; i<rear; i++)
                cout<<cQueue[i].accno<<"\t"<<cQueue[i].title<<" <- ";
            cout<<cQueue[rear].accno<<"\t"<<cQueue[rear].title<<" <<< "<<endl;
            for( ; i<Front; i++)
                cout<<"-";
            cout<<" >>> ";
            for(i=Front; i<size_; i++)
                cout<<cQueue[i].accno<<"\t"<<cQueue[i].title<<" <- ";
            cout<<"\t ...wrap around... ";
        }
        cout<<"\n Do you want to go back to the Main menu? (y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
            Main_Menu();
        else
            exit(0);
}

void Delete()
{
    char ch='y';
    book ret;
    if(Front==-1)
    {
        cout<<"\n UNDERFLOW!!!";
        cout<<"\n Do you want to go back to the Main menu? (y/n): ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
            Main_Menu();
        else
            exit(0);
    }
    else
    {
        ret=cQueue[Front];
        if(Front==rear)
            Front=rear=-1;
        else
            if(Front==size_-1)
            Front=0;
        else
            Front++;
    }
    Display();
}

 void Main_Menu()
{
    int choice;
    cout<<"\n  Circular Queue Main Menu:"<<endl;
    cout<<" 1. Insert"<<endl;
    cout<<" 2. Delete"<<endl;
    cout<<" 3. Display"<<endl;
    cout<<" 4. Exit"<<endl;
    cout<<" Enter the number (from 1 to 4) corresponding to the action that you wish to perform to proceed... \t";
    choice_:
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
           cin.ignore();
           Insert();
           break;
        }
    case 2:
        {
            Delete();
            break;
        }
    case 3:
        {
            Display();
            break;
        }
    case 4:
            exit(0);
    default:
        {
            cout<<"Error! Please select a number from 1 to 4. \n";
            goto choice_;
        }
    }
}

int main()
{
    system("cls");
    Main_Menu();

    getch();
    return 0;
}
