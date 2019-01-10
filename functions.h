void searchnow(char);
void suggestions(char[]);
void show_contact(long long int);
void Show_all_contacts();
void edit_contact(long long int);
void delete_contact(long long int);
void search_menu();
void searchbyname(char*);
void searchbyemail(char*);
void searchbystatus(char);
void searchbyfriends(int num);
void searchbyfm(int num);
void thanks();
void add_contact();
using namespace std;
class Contacts{
long long int ph;
long long int ph1,ph2;
char name[30];
char email[50];
int family_members,friends;
char status;
public:
  Contacts(){
  ph=ph1=ph2=0;
  family_members=friends=0;
  }
  void getdata(){
  cout<<"Enter Your Mobile No::";
  cin>>ph;
  fflush(stdin);
  cout<<"\nEnter Your Name::";
  fflush(stdin);
  istream& ignore (streamsize n = 1, int delim = EOF);
  gets(name);
  cout<<"\nEnter Your Email::";
  fflush(stdin);
  gets(email);
  cout<<"\nEnter Your Status(W for Working and N for Not Working)::";
  status=getchar();
  fflush(stdin);
  cout<<"Enter No. of Family Members::";
  cin>>family_members;
  fflush(stdin);
  cout<<"Enter the no. of friends do you have::";
  cin>>friends;
  fflush(stdin);
  }

  void showdata(){
  cout<<"\n\n**************************";
  cout<<"\nMobile No::"<<ph<<endl;
  cout<<"Name::"<<name<<endl;
  cout<<"Email::"<<email<<endl;
  cout<<"Status::"<<status<<endl;
  cout<<"Family Members::"<<family_members<<endl;
  cout<<"No. of friends::"<<friends<<endl;
  cout<<"**************************";
  }

  long long int getph(){
  return ph;
  }

  char *getname(){
  return name;
  }

  char *getemail(){
  return email;
  }

  char getstatus(){
  	return status;
  }
  int getfriends(){
  	return friends;
  }
  int getfamilymembers(){
  	return family_members;
  }

  void add_data(){
  if(ph1!=0){
  cout<<"Alternate Mobile no 1::"<<ph1<<endl;

  }else if(ph2!=0){
  cout<<"Alternate Mobile no 2::"<<ph2<<endl;
  }else{
  cout<<"No Alternate Mobile no(s)!!"<<endl;
  }}

};


void search_menu(){
system("cls");
char str[50];
int ch,num;
cout<<"\n\n\t\t SEARCH MODE"<<endl;
cout<<"1.Search by Name"<<endl;
cout<<"2.Search by email"<<endl;
cout<<"3.Search by status"<<endl;
cout<<"4.Search by friends"<<endl;
cout<<"5.Search by Family Members"<<endl;
cout<<"6.Exit"<<endl;
cout<<"Enter Your choice::";
cin>>ch;
switch(ch){
case 1: cout<<"\nEnter Name::";
        fflush(stdin);
        gets(str);
        searchbyname(str);
        break;
case 2: cout<<"\nEnter Email::";
        fflush(stdin);
        gets(str);
        searchbyemail(str);
        break;
case 3: cout<<"\nEnter Status(W/N)::";
        char c;
        cin>>c;
        searchbystatus(c);
        break;
case 4: cout<<"Enter the no. of friends::";
        cin>>num;
        searchbyfriends(num);
        break;
case 5: cout<<"Enter the no. of family members::";
        cin>>num;
        searchbyfm(num);
        break;
case 6: thanks();
        exit(0);
        break;
default: cout<<"Wrong choice!!";



};


}

void thanks(){
cout<<"\n\nTHANKS FOR USING THIS SOFTWARE !!!"<<endl;
cout<<"MADE BY ::"<<endl;
cout<<"NAME::SHUBAM VIRDI"<<endl;
cout<<"SECTION::K17SD"<<endl;
}

void searchbyname(char name[50]){
fstream f;
Contacts C;
bool found=false;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
	cout<<"Cant find file!!";
	exit(0);
}
while(f.read((char*)&C,sizeof(C))){
	if(strcmpi(name,C.getname())==0){
		C.showdata();
		found=true;
	}
}
if(found==false){
	cout<<"\n No contact found with this name!!";
	suggestions(name);
	exit(0);
}
f.close();
}
void searchbyemail(char email[50]){

fstream f;
Contacts C;
bool found=false;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
	cout<<"Cant find file!!";
	exit(0);
}
while(f.read((char*)&C,sizeof(C))){
	if(strcmpi(email,C.getemail())==0){
		cout<<"Contact Found!!\n";
		C.showdata();
		found=true;
	}
}
if(found==false){
	cout<<"\n No contact found with this email!!";
	suggestions(email);
	exit(0);
}
f.close();
}

void searchbystatus(char C){
 switch(C){
 	case 'W':
 	case 'N':searchnow(C);
 		     break;
 	default:cout<<"Wrong status Entered!!"<<endl;
 }
}
void searchbyfriends(int num){
fstream f;
Contacts C;
bool found=false;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
	cout<<"Cant find file!!";
	exit(0);
}
while(f.read((char*)&C,sizeof(C))){
	if(num==C.getfriends()){
		cout<<"Contact Found!!\n";
		C.showdata();
		found=true;
	}
}
if(found==false){
	cout<<"\n No contact found with this No. of friends!!";
	exit(0);
}
f.close();
}
void searchbyfm(int num){
fstream f;
Contacts C;
bool found=false;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
	cout<<"Cant find file!!";
	exit(0);
}
while(f.read((char*)&C,sizeof(C))){
	if(num==C.getfamilymembers()){
		cout<<"Contact Found!!\n";
		C.showdata();
		found=true;
	}
	f.close();
}
if(found==false){
	cout<<"\n No contact found with this No. of family Members!!";
	exit(0);
}

}
void searchnow(char d){
fstream f;
Contacts C;
bool found=false;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
	cout<<"Cant find file!!";
	exit(0);
}
while(f.read((char*)&C,sizeof(C))){
	if(d==C.getstatus()){
		cout<<"Contact Found!!\n";
		C.showdata();
		found=true;
	}
}
if(found==false){
	cout<<"\n No contact found with this status!!";
	exit(0);
}
f.close();
}
void suggestions(char Suggest[50]){
	fstream f;
	Contacts C;
	char email[50];
	char name[50];
	bool sug=false;
	f.open("cont.dat",ios::in|ios::binary);
	if(!f){
		cout<<"File not found!!";
		exit(0);
	}
	cout<<"\nHere Are Some Suggestions!!!\n\n";

	int i=0,j=0;
	while(f.read((char*)&C,sizeof(C))){
	     strcpy(name,C.getname());
	     strcpy(email,C.getemail());
	     int len = strlen(name);
	     bool shown=false;
       for(i=0;i<len;++i)
        for(j=0;j<len;++j){


		if(email[i]==Suggest[j] && shown==false){
			cout<<"\nSuggested Email::\n";
			cout<<email;
			shown = true;
			sug=true;

		}else if(Suggest[j]==name[i]&&shown==false){
			cout<<"\nSuggested Name::\n";
			cout<<name;
			sug=true;
			shown=true;

		}
		}}

	if(sug==false){
		cout<<"\n\n No Suggestions Available!!";
		exit(0);
	}
	f.close();
}


void add_contact(){
fstream f;
Contacts C;
long long int ph;
bool found=false;
f.open("cont.dat",ios::app|ios::binary|ios::out);
if(!f){
cout<<"File cant be opened!!"<<endl;
exit(0);
}
cout<<"Enter Mobile No::";
cin>>ph;
while(f.read((char*)&C,sizeof(C))){
    if(ph==C.getph())
    {
        cout<<"Contact Already Exist!!"<<endl;
        found=true;
        exit(0);


    }
}
if(found==false){
      cout<<"\n\nNew Contact::\n\n";
        C.getdata();
    f.write((char*)&C,sizeof(C));
cout<<"Successfully saved!!"<<endl;

}

f.close();
}


void show_contact(long long int ph){
bool found=false;
fstream f;
Contacts C;
f.open("cont.dat",ios::in|ios::binary);
if(!f){
cout<<"File cant be opened!!"<<endl;
exit(0);
}
while(f.read((char*)&C,sizeof(C))){
if(C.getph()==ph){
C.showdata();
C.add_data();
found=true;
}
if(found==false){
cout<<"No Record Found for This Mobile No!!"<<endl;
}
}
f.close();
}
void delete_contact(long long int ph){
    Contacts C;
    bool found=false;
    fstream f,temp;
    f.open("cont.dat",ios::in|ios::binary);
    temp.open("temp.dat",ios::out|ios::binary);
    if(!f){
    cout<<"File cant be opened!!!"<<endl;
    exit(0);
    }
    if(!temp){
    cout<<"File cant be opened!!!"<<endl;
    exit(0);
    }

	while(f.read((char*)&C,sizeof(C)))
	{
		if(C.getph()!=ph)
		{
			temp.write((char*)&C,sizeof(C));
			found=false;
		}else{
		found=true;
		}
	}
	if(found==false){
	cout<<"\nNo contact found with this mobile no!!!\n";
	}
	f.close();
	temp.close();
	remove("cont.dat");
	if(rename("temp.dat","cont.dat")){
        cout<<"Success"<<endl;

	}



}
void Show_all_contacts(){

 Contacts C;
    fstream f;
    f.open("cont.dat",ios::in|ios::binary);
    if(!f){

    cout<<"File cant be opened!!!"<<endl;
    exit(0);
    }

	while(f.read((char*)&C,sizeof(C)))
	{
	C.showdata();
	}
   f.close();
}
void edit_contact(long long int ph){
    Contacts C;
    fstream f;
    long pos;
    bool found=false;
    f.open("cont.dat",ios::in|ios::binary|ios::out);
    if(!f){
    cout<<"File cant be opened!!!"<<endl;
    exit(0);
    }

	while(f.read((char*)&C,sizeof(C)))
	{
		if(C.getph()==ph)
		{

			C.showdata();
            cout<<"\nPlease Enter The New Details of Contact: "<<endl;
			pos=-1*sizeof(C);
			f.seekp(pos,ios::cur);
			C.getdata();
			f.write((char*)&C,sizeof(C));
			cout<<endl<<endl<<"\n Contact Successfully Updated...\n";
			found=true;
		}
	}
	if(found==false){
	cout<<"\n\nNo contact found with this mobile no!!!\n\n";
	}
f.close();

}


