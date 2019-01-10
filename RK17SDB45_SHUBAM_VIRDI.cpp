#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include"functions.h"
using namespace std;


int main(){
int ch;
long long int ph=0;
system("cls");
while(ch!=6){
cout<<"\n\t\t\t MAIN MENU"<<endl;
cout<<"\t\t CONTACTS MANAGEMENT SYSTEM"<<endl;
cout<<"1.Add contact"<<endl;
cout<<"2.Delete contact"<<endl;
cout<<"3.Show all contact"<<endl;
cout<<"4.Search Contact"<<endl;
cout<<"5.Edit a Contact"<<endl;
cout<<"6.Exit"<<endl;
cout<<"Enter Your choice::";
cin>>ch;
switch(ch){

case 1: add_contact();
       break;
case 2:
       cout<<"Enter mobile no::";
       cin>>ph;
       delete_contact(ph);
       break;
case 3: Show_all_contacts();
       break;
case 4: search_menu();
       break;
case 5:
       cout<<"Enter Mobile No::";
       cin>>ph;
       edit_contact(ph);
       break;
case 6: thanks();
       exit(0);
       break;
default:cout<<"Wrong choice!!!";
};


}

}
