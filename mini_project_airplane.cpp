#include<iostream>
#include<cstdlib>
#include<fstream>
//#include<windows.h>
//#include<mmsystem.h>
#include<string.h>
using namespace std;
int seat[11][11];
class air_india
{
char name[20];
char gender;
long int phone;
long int passport;


public:

void init();
 void getdata();
 void display();
 void book();
 void pay(int);
};
void air_india::book()
{
    cout<<"\n book ur seat from the available ones : 0 indicates unreserved \n";
     air_india ob;
fstream myfile;
myfile.open("flight.txt",ios::in);
cout<<" seat matrix: of the plane \n";
for(int i = 0; i < 10; i++)
{
     for(int j = 0; j < 10; j++ )
	{
	        myfile >> seat[i][j];
		cout << seat[i][j]<<"\t";
	}
	cout<<"\n";
}
myfile.close();

int k,m,i=0,j=0;
char nam[10];
cout<<"enter ur seat in the form of 1 1 ,0 1 \n";
cin>>k>>m;
fstream fin;
seat[k][m]=1;
fin >> seat[k][m];
fin.close();
cout<<"booked \n";
cout<<"updated seat matrix: of the plane \n";
for(int i = 0; i < 10; i++)
{
     for(int j = 0; j < 10; j++ )
	{
	        myfile >> seat[i][j];
		cout << seat[i][j]<<"\t";
	}
	cout<<"\n";
}


pay(m-1);
}

void air_india::pay(int f)
{
    char temp[15];
    cout<<" your source is Delhi";
    cout<<"enter the destination in CAPITAL only";
    cin>>temp;
    if((strcmp(temp,"JAIPUR")==0)||(strcmp(temp,"BHOPAL")==0)||(strcmp(temp,"NAGPUR")==0)||(strcmp(temp,"HYDERABAD")==0)||(strcmp(temp,"CHENNAI")==0))
    {
        cout<<"your destination is :"<<temp;
        if((strcmp(temp,"JAIPUR")==0)&&((f==1)||(f==9)))
           cout<<" Final fare is Rs. 5000 as its a window seat \n";
        else if(strcmp(temp,"JAIPUR")==0)
            cout<<"Final fare is Rs. 3000\n";

        else if((strcmp(temp,"BHOPAL")==0)&&((f==1)||(f==9)))
            cout<<" Final fare is Rs. 7000 as its a window seat\n";
     	 else if(strcmp(temp,"BHOPAL")==0)
            cout<<"Final fare is Rs. 5000\n";

        else if((strcmp(temp,"NAGPUR")==0)&&((f==1)||(f==9)))
            cout<<" Final fare is Rs. 9000 as its a window seat\n";
            else if(strcmp(temp,"NAGPUR")==0)
            cout<<"Final fare is Rs. 7000\n";

        else if((strcmp(temp,"HYDERABAD")==0)&&((f==1)||(f==9)))
            cout<<" Final fare is Rs. 11000 as its a window seat\n";
            else if(strcmp(temp,"HYDERABAD")==0)
            cout<<"Final fare is Rs. 9000\n";

        else if((strcmp(temp,"CHENNAI")==0)&&((f==1)||(f==9)))
            cout<<" Final fare is Rs. 15000 as its a window seat\n";
            else if(strcmp(temp,"CHENNAI")==0)
            cout<<"Final fare is Rs. 13000\n";

    }
    else
        cout<<" invalid halt \n";


}

void air_india::init()
{
  int d=1;
  fstream f1;
  f1.open("flight.txt");
         seat[0][0]=7;
         f1<<seat[0][0];
        for(int i=1,j=1;i<10,j<10;i++,j++)
        {

            seat[0][j]=d;
            f1<<seat[0][j];
            seat[i][0]=d;
            f1<<seat[i][0];
            d++;
        }


        for(int i=1;i<10;i++)
        {
            for(int j=1;j<10;j++)
            {
            seat[i][j]=0;
            f1<<seat[i][j];
            }
        }



}

void air_india::getdata()
{
    int d;
    fstream f1;
    f1.open("flight.txt");
    air_india ob;
    cout<<"\n enter the no. of seats u want to book";
        cin>>d;
    f1.open("flight.txt",ios::out);
    for(int i=0; i<d;i++)
    {
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"\nEnter Passenger Name  :: ";
    cin>>ob.name;
    cout<<"\nEnter Passport Number ::";
    cin>>ob.passport;
    cout<<"\nEnter gender as M , F and O for other gender ::";
    cin>>ob.gender;
    cout<<"\nEnter phone no. ::";
    cin>>ob.phone;
    cout<<"--------------------------------------------------------------------"<<endl;
    f1.write((char*)&ob,sizeof(ob));
    }
    f1.close();
    for(int i=0;i<d;i++)
    {
        cout<<"BOOKING STARTED FOR : "<<i+1<<" SEAT ";
    book();
    }

}



void air_india::display()
{
    cout<<"\n the Air-India plane details for 24th December 2018 are : \n":
   air_india ob;
fstream f2;
f2.open("flight.txt",ios::in);
f2.read((char*)&ob,sizeof(ob));
    while(f2)
    {
    cout<<"\n Passenger Name  :: "<<ob.name<<endl;
    cout<<"\n Passport Number ::"<<ob.passport<<endl;
    cout<<"\n Gender ::"<<ob.gender<<endl;
    cout<<"\n Phone Number ::"<<ob.phone<<endl;


    f2.read((char*)&ob,sizeof(ob));
    }
f2.close();
fstream myfile;
cout<<" seat matrix: of the plane \n";
for(int i = 0; i < 10; i++)
{
     for(int j = 0; j < 10; j++ )
	{
	        myfile >> seat[i][j];
		cout << seat[i][j]<<"\t";
	}
	cout<<"\n";
}
	myfile.close();

 cout<<"\n\n--------------------------------------------------------------------"<<endl;

}



int main()
{   int choice;
    air_india ai;
    ai.init();
   // PlaySound(TEXT("music1/Recording1.wav"), NULL, SND_SYNC);
    while(1)
    {
    cout<<"\n ***** WELCOME TO AIR INDIA ***** \n";
    cout<<"\n this flight travels from DELHI to CHENNAI via Jaipur, Bhopal, Nagpur , Hyderabad \n "<<endl;
    cout<<"---------------------------------------------";
    cout<<"\n\t\t\tMAIN MENU";
    cout<<"\n1. add passenger and book ticket ";
    cout<<"\n.2. display plane details ";
    cout<<"\n.3.exit ";
    cout<<"---------------------------------------------";
    cout<<"\n\nEnter the choice";
    cin>>choice;
        switch(choice)
        {
            case 1:
                ai.getdata();
                //PlaySound(TEXT("music1/Recording.wav"), NULL, SND_SYNC);
                break;

            case 2:
                ai.display();
            break;
            case 3:
                exit(0);
            break;
        }
    }
    return 0;
}
