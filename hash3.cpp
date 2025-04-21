#include<iostream>
#include<cstring>
using namespace std;
const int tablesize=10;
struct person{
char name[30];
char phonenumber[15];
bool isfull=false;
};
int hashfunction(const char*phone){
int hash=0;
for(int i=0;phone[i]!='\0';i++)
hash=(hash*10+(phone[i]-'0'))%tablesize;
return hash;
}
void insert(person hashtable[],const char*phone,const char*name){
int comparison=0;
int index=hashfunction(phone),starting=index;
while(hashtable[index].isfull){
 comparison++;
index=(index+1)%tablesize;
if(index==starting){
cout<<"memory full:";
return ;
}
}
strcpy (hashtable[index].phonenumber,phone);
strcpy (hashtable[index].name,name);
hashtable[index].isfull=true;
cout<<"inserted at index"<<index<<" "<<phone<<"->"<<name;

}
void searching(person hashtable[],const char*phone){
int comparison=0;
int index=hashfunction(phone),starting=index;
while(hashtable[index].isfull){
comparison++;
if(strcmp(hashtable[index].phonenumber,phone)==0){

cout<<"found at index:"<<index<<" "<<phone<<"->"<<hashtable[index].name<<"comparison is:"<<comparison;
return;
}
index=(index+1)%tablesize;
if(index==starting)
break;
}
cout<<"phone number is not found:";


}
int main(){

person hashtable[tablesize];
int choice;
char name[30];
char phone[15];
do{
cout<<"1-insert a data:"<<endl;
cout<<"2-search a data:"<<endl;
cout<<"enter a your choice:"<<endl;
cin>>choice;
switch(choice){
case 1:
int n;
cout<<"enter a number of person:";
cin>>n;
for(int i=0;i<n;i++){
cout<<"enter a phone number:";
cin>>phone;
cin.ignore();
cout<<"enter a name of person:";
cin.getline(name,30);
insert(hashtable,phone,name);
}
break;
case 2:
cout<<"enter a phone number:";
cin>>phone;
searching(hashtable,phone);
break;
default:
cout<<"end:";
}

}while(choice!=3);
return 0;
}









 


