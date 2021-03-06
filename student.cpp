#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

//=================================================================
struct STUDENT
{
	int id;
   char name[40];
   float avr;
};
//=================================================================
STUDENT s[40];
int max_student;
//=================================================================
void print_menue();
void add_student();
void list();
void search_by_id();
void search_by_name();
void list_fail();
void list_good();
void search_best();
void del_by_name();
void del_by_id();
//=================================================================
int main ()
{
	int ch;

   max_student=0;
   do{
   	print_menue();
      ch=getche();
      cout<<endl<<endl;
      switch(ch)
      {
      	case '1':
         	add_student();
            cout<<"student successfully added ..."<<endl;
            getch();
            break;
      	case '2':
         	list();
            getch();
            break;
      	case '3':
         	search_by_id();
            getch();
            break;
      	case '4':
         	search_by_name();
            getch();
            break;
      	case '5':
         	list_fail();
            getch();
            break;
      	case '6':
         	search_best();
            getch();
            break;
      	case '7':
         	list_good();
            getch();
            break;
        case '8':
                 del_by_name();
            getch();
            break;
        case '9':
                del_by_id();
            getch();
            break;
         case 'x':
         case 'X':
         case 27:
         	break;
      }
   } while ((ch!=27)&&(ch!='x')&&(ch!='X'));
}
//=================================================================
void print_menue()
{
	clrscr();
	cout<<"1) Add student\n";
	cout<<"2) List students\n";
	cout<<"3) Search by id\n";
	cout<<"4) Search by name\n";
	cout<<"5) List Failed students\n";
	cout<<"6) Best student\n";
	cout<<"7) List of good students\n";
	cout<<"8) Delete student by name\n";
	cout<<"9) Delete student by id\n";
	cout<<"X or ESC) Exit\n";
   cout<<"Press Seelction:";
}
//=================================================================
void add_student()
{
   cout<<"Student id:";
   cin>>s[max_student].id;

   cout<<"Student name:";
   cin>>s[max_student].name;

   cout<<"Student average:";
   cin>>s[max_student].avr;

   max_student++;
}
//=================================================================
void list()
{
	int i;

   for (i=0;i<max_student;i++)
   	cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;
   cout<<"End of list ..."<<endl;
}
//=================================================================
void search_by_id()
{
	int i;
   int id;

   cout<<"Enter id to search:";
   cin>>id;

   for (i=0;i<max_student;i++)
   	if (s[i].id==id)
   		cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;

   cout<<"End of search ..."<<endl;
}
//=================================================================
void search_by_name()
{
	int i;
   char name[40];

   cout<<"Enter id to search:";
   cin>>name;

   for (i=0;i<max_student;i++)
   	if (strcmp(s[i].name,name)==0)
   		cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;

   cout<<"End of search ..."<<endl;
}
//=================================================================
void list_fail()
{
	int i;

   for (i=0;i<max_student;i++)
   	if (s[i].avr<12)
   		cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;

   cout<<"End of search ..."<<endl;
}
//=================================================================
void list_good()
{
	int i;

   for (i=0;i<max_student;i++)
   	if (s[i].avr>=17)
   		cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;

   cout<<"End of search ..."<<endl;
}
//=================================================================
void search_best()
{
	int i;

   int indx=0;
   for (i=1;i<max_student;i++)
   	if (s[i].avr>=s[indx].avr)
      	indx=i;
   if (indx<max_student)
   	cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;
   cout<<"End of search ..."<<endl;
}
//==================================================================
   void del_by_name()
{
	int i,j;
    char name[40];

   cout<<"Enter name to delete:";
   cin>>name;

   for (i=0;i<max_student;i++)
   {
        if (strcmp(s[i].name,name)==0)
        {
        	cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;
        	for (j=i+1;j<max_student;j++)
         {
         	strcpy (s[j-1].name,s[j].name);
            s[j-1].id=s[j].id;
            s[j-1].avr=s[j].avr;
            i--;
         }

        }
   }
   cout<<"End of delete ..."<<endl;
}
//==================================================================
 void del_by_id()
{
	int i;
   int id;

   cout<<"Enter id to delete:";
   cin>>id;

   for (i=0;i<max_student;i++)
   	if (s[i].id!=id)
   		cout<<s[i].id<<"\t"<<s[i].name<<"\t"<<s[i].avr<<endl;

   cout<<"End of delete ..."<<endl;
}
