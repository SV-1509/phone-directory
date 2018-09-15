#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>
  class Phonedir
  {
    char name[50];
    char hno[10];
    char place[50];
    char landline[15];
    char mobile[15];
  public:
    void addrec();
    void showrec();
    void searchrec();
    void modrec();
    void delrec();
    void searchplace();
    void searchname();
    void searchhno();
    void show(char comp[50]);
  }P;
   void upper(char name[])
   {
      for(int i=0;i<strlen(name);i++)
      {
	 name[i]=toupper(name[i]);
      }
   }
   void el()
  {
    for(int i=0;i<80;i++)
    cout<<"_";
  }
  void Phonedir::addrec()
  {
    fstream f;
    f.open("Phonedir.dat",ios::out|ios::app|ios::binary);
    cout<<"Enter Name->";
    gets(name);
    upper(name);
    cout<<"Enter  House no->";
    gets(hno);
    cout<<"Enter Place->";
    gets(place);
    upper(place);
    cout<<"Enter Landline no->";
    gets(landline);
    cout<<"Enter Moble no->";
    gets(mobile);
    f.write((char*)&P,sizeof(P));
    f.close();
  }
  void Phonedir::showrec()
  {
    fstream f;
    f.open("Phonedir.dat",ios::in|ios::binary);
    f.read((char*)&P,sizeof(P));
    while(!f.eof())
    {
      el();
      cout<<"\nName->";
      cout<<name<<endl;
      cout<<"House no->";
      cout<<hno<<endl;
      cout<<"Place->";
      cout<<place<<endl;
      cout<<"Landline number->";
      cout<<landline<<endl;
      cout<<"Mobile number->";
      cout<<mobile<<endl;
      f.read((char*)&P,sizeof(P));
      el();
    }
    f.close();
  }
     void Phonedir::show(char comp[50])
     {
       fstream f;
       f.open("Phonedir.dat",ios::in|ios::binary);
       f.read((char*)&P,sizeof(P));
       while(!f.eof())
       {
	  if(strcmp(comp,name)==0||strcmp(comp,hno)==0||strcmp(comp,place)==0)
	  {
	     el();
	     cout<<"\nName->";
	     cout<<name<<endl;
	     cout<<"House no->";
	     cout<<hno<<endl;
	     cout<<"Place->";
	     cout<<place<<endl;
	     cout<<"Landline number->";
	     cout<<landline<<endl;
	     cout<<"Mobile number->";
	     cout<<mobile<<endl;
	     el();
	  }
	  f.read((char*)&P,sizeof(P));
       }
       f.close();
     }
   void Phonedir::searchname()
   {
      char ch[50];
      int i=0;
      cout<<"\nEnter the Name of person to be searched->";
      gets(ch);
      upper(ch);
      fstream f;
      f.open("Phonedir.dat",ios::in|ios::binary);
      f.read((char*)&P,sizeof(P));
      while(!f.eof())
      {
	if(strcmp(ch,name)==0)
	{
	  clrscr();
	  i=1;
	  show(ch);
	  break;
	}
	else
	f.read((char*)&P,sizeof(P));
      }
      if(i==0)
      cout<<"\n SORRY record not found\n";
      f.close();
   }
   void Phonedir::searchplace()
   {
      char ch[50];
      int i=0;
      cout<<"\nEnter the Place of person to be searched->";
      gets(ch);
      upper(ch);
      fstream f;
      f.open("Phonedir.dat",ios::in|ios::binary);
      f.read((char*)&P,sizeof(P));
      while(!f.eof())
      {
	if(strcmp(ch,place)==0)
	{
	  clrscr();
	  i=1;
	  show(ch);
	  break;
	}
	else
	f.read((char*)&P,sizeof(P));
      }
      if(i==0)
      cout<<"\n SORRY record not found\n";
      f.close();
   }
   void Phonedir::searchhno()
   {
      char h[10];
      int i=0;
      cout<<"\nEnter the House number of person to be searched->";
      gets(h);
      fstream f;
      f.open("Phonedir.dat",ios::in|ios::binary);
      f.read((char*)&P,sizeof(P));
      while(!f.eof())
      {
	if(strcmp(h,hno)==0)
	{
	  clrscr();
	  i=1;
	  show(h);
	  break;
	}
	else
	f.read((char*)&P,sizeof(P));
      }
      if(i==0)
      cout<<"\n SORRY record not found\n";
      f.close();
   }
  void Phonedir::searchrec()
  {
    int i;
    cout<<"Search by\n";
    cout<<"1-Name\n";
    cout<<"2-House no\n";
    cout<<"3-Place\n";
    cout<<"4-Go back\n";
    cin>>i;
    switch(i)
    {
      case 1:
      searchname();
      break;
      case 2:
      searchhno();
      break;
      case 3:
      searchplace();
      break;
      case 4:
      break;
      default:
      cout<<"\n SORRY WRONG CHOICE!!\n";
      break;
    }
  }
  void Phonedir::modrec()
  {
     char ch[50],confirm;
     int i=0;
     fstream f,e;
     cout<<"Enter name of person whose record is to be modified\n"<<endl;
     gets(ch);
     upper(ch);
     f.open("Phonedir.dat",ios::in|ios::binary);
     e.open("DUP.dat",ios::out|ios::binary);
     f.read((char*)&P,sizeof(P));
     while(!f.eof())
     {
       if(strcmp(ch,name)==0)
       {
	  cout<<"\nAre you sure YES(y)orNO(n)";
	  cin>>confirm;
	  switch(confirm)
	  {
	    case 'Y':case 'y':
		cout<<"Enter Name->";
    gets(name);
    upper(name);
    cout<<"Enter  House no->";
    char(hno);
    cout<<"Enter Place->";
    gets(place);
    upper(place);
    cout<<"Enter Landline no->";
    gets(landline);
    cout<<"Enter Moble no->";
    gets(mobile);
		i=1;
		break;
	    default:
		break;
	  }
	  }
	  e.write((char*)&P,sizeof(P));
	  f.read((
	  char*)&P,sizeof(P));
     }
     if (i==0)
     cout<<"\n Record not found";
     else
     cout<<"\nRecord modified";
     f.close();
     e.close();
     remove("Phonedir.dat");
     rename("DUP.dat","Phonedir.dat");
  }
  void Phonedir::delrec()
  {
      char ch[50],confirm;
     int i=0;
     fstream f,e;
     cout<<"Enter name of person whose record is to be delted\n";
     gets(ch);
     upper(ch);
     f.open("Phonedir.dat",ios::in|ios::binary);
     e.open("DUP.dat",ios::out|ios::binary);
     f.read((char*)&P,sizeof(P));
     while(!f.eof())
     {
       if(strcmp(ch,name)==0)
       {
	  cout<<"\nAre you sure YES(y)orNO(n)";
	  cin>>confirm;
	  switch(confirm)
	  {
	    case 'Y':case 'y':
		i=1;
		cout<<"Record deleted";
		break;
	    case 'N':case 'n':
		i=2;
		e.write((char*)&P,sizeof(P));
		break;
	    default:
		break;
	  }
	  }
	  else
	  e.write((char*)&P,sizeof(P));
	  f.read((char*)&P,sizeof(P));
     }
     if (i==0)
     cout<<"\n Record not found";
     f.close();
     e.close();
     remove("Phonedir.dat");
     rename("DUP.dat","Phonedir.dat");
  }
   void credits()
  {
    clrscr();
    cout<<"Program by"<<endl;
    cout<<"SREEVISHAKH.V"<<endl;
  }
  void func(int i)
  {
    switch(i)
    {
      case 1:
      {
	 clrscr();
	 P.addrec();
	 cout<<"RECORD ADDED";
	 break;
      }
      case 2:
       {
	 clrscr();
	 P.showrec();
	 break;
       }
       case 3:
       {
	 clrscr();
	 P.searchrec();
	 break;
       }
       case 4:
       {
	 clrscr();
	 P.modrec();
	 break;
       }
       case 5:
       {
	 clrscr();
	 P.delrec();
	 break;
       }
       case 6:
       {
	 clrscr();
	 credits();
	 cout<<"THANK   YOU!!!!!!!!";
	 getch();
	 exit(0);
	 break;
       }
       default:
       break;
    }
    void menu();
   }
  void menu()
  {
    clrscr();
    int i;
    cout<<"\t\t\t PHONE DIRECTORY\n\n\n\n";
    cout<<"1-Add a new record"<<endl;
    cout<<"2-Show all record"<<endl;
    cout<<"3-Search a record"<<endl;
    cout<<"4-Modify a record"<<endl;
    cout<<"5-Delete a record"<<endl;
    cout<<"6-Exit"<<endl;
    cout<<"Enter a choice";
    cin>>i;
    func(i);
  }

void main()
{
 clrscr();
 start:
 menu();
 getch();
 goto start;
}