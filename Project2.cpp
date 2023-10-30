#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	
{
private:
	char  *author,*title,*publisher;
	float *price;
	int *bookID,*inventory;
public:	
	book()
    {
	author= new char[20];
	title=new char[20];
	publisher=new char[20];
	price= new float;
    bookID = new int;
	inventory=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(int id,char[],char[]);
	void buybook();
	
};

void book::feeddata()	
{
	cin.ignore();
	cout<<"\nEnter Author Name: ";
    cin.getline(author,20);
	cout<<"Enter Title Name: ";      
    cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   
    cin.getline(publisher,20);
	cout<<"Enter Price: ";            
    cin>>*price;
    cout<<"Enter the book ID: ";      
    cin>>*bookID;
	cout<<"Enter inventory Position: ";   
    cin>>*inventory;   
	
}

void book::editdata()	
{
	
	cout<<"\nEnter Author Name: ";      
    cin.getline(author,20);
	cout<<"Enter Title Name: ";       
    cin.getline(title,20);
	cout<<"Enter Publisher Name: ";  
    cin.getline(publisher,20);
	cout<<"Enter Price: ";           
    cin>>*price;
    cout<<"Enter the book ID: ";      
    cin>>*bookID;
	cout<<"Enter inventory Position: ";   
    cin>>*inventory;   
	
}

void book::showdata()	
{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nPublisher Name: "<<publisher;
	cout<<"\nPrice: "<<*price;
    cout<<"\nBook ID: "<<*bookID;
	cout<<"\ninventory Position: "<<*inventory;   
	
}

int book::search(int id,char tbuy[20],char abuy[20] )	
{
	if(strcmpi(tbuy,title)==0 && strcmpi(abuy,author)==0 && (id == *bookID))
    {
       return 1;
    }
	else return 0;
		
}

void book::buybook()	
{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*inventory)	
    {
		*inventory=*inventory-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
    {
		cout<<"\nRequired Copies not in inventory";
    }
}

int main()	
{
	book *B[20];
	int i=0,r,t,choice, ID;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	
        {
			case 1:	B[i] = new book;
				B[i]->feeddata();
				i++;	
                break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
                cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: "; 
                cin.getline(authorbuy,20);
                cout<<"Enter the Book ID: ";
                cin>>ID;
    
				for(t=0;t<i;t++)	{
					if(B[t]->search(ID,titlebuy,authorbuy))	
                    {
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in inventory";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
                cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  
                cin.getline(authorbuy,20);
                cout<<"Enter the Book ID: ";
                cin>>ID;
                
				for(t=0;t<i;t++)	
                {
					if(B[t]->search(ID,titlebuy,authorbuy))	
                    {
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in inventory";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Book: "; 
                cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  
                cin.getline(authorbuy,20);
                cout<<"Enter the Book ID: ";
                cin>>ID;
				
				for(t=0;t<i;t++)	
                {
					if(B[t]->search(ID,titlebuy,authorbuy))	
                    {
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in inventory";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	return 0;
}