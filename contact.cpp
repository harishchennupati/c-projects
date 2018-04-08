#include<bits/stdc++.h>
using namespace std;
enum type {
    groups=1,occupation,family,friends
}t;
class contact{
    private:
    enum type s;
    string name;
    int k;
    string no[10];
    string email;
    public:
    friend void addnew();
    friend void update();
    friend void del();
    friend void search();
    friend void addmulti();
    contact(string name,enum type s,int k,string n1,string email):name(name),s(s),k(k),email(email){
        no[k]=n1;
    };
};
list<contact> con;
void addnew()
{
    cout<<"enter details of the contact you want to add: "<<endl;
    cout<<"enter the type of contact you want: ";
    int s;
    cin>>s;
    cout<<"enter the name: ";
    string name;
    cin>>name;
    string no;
    cout<<"\nenter number for: "<<name<<" :";
    cin>>no;
    cout<<"enter email of: "<<name<<": ";
    string email;
    cin>>email;
    contact v(name,(type)s,0,no,email);
    con.push_back(v);
}
void update()
{
    cout<<"enter the name of the contact u want to update: ";
    string s;
    cin>>s;
    int ch;
    list<contact>::iterator i;
    for(i=con.begin();i!=con.end();++i)
    {
        if(i->name==s)
        {
            cout<<"enter what u want to update"<<endl;
            cout<<"enter 1 to update name"<<endl;
            cout<<"enter 2 to update no"<<endl;
            cout<<"enter 3 to update email"<<endl;
            cin>>ch;
            switch(ch){
                case 1:{
                 string name;
                 cout<<"enter the name with what u want to change: ";
                 cin>>name;
                 i->name=name;
                 break;}
                case 2:{
                 cout<<"enter the number with what u want to change: ";
                 int k;
                 cin>>k;
                 cout<<"enter the replacing number :"<<endl;
                 string no;
                 cin>>no;
                 i->no[k]=no;
                 break;}
                case 3:{
                 cout<<"enter email u want to update: ";
                 string email;
                 cin>>email;
                 i->email=email;
                break;}
            }
        }
        else
        cout<<"sorry not there in your contacts"<<endl;
         
    }
}
void del()
{
    cout<<"enter the contact name u want to delete "<<endl;
    string s;
    bool val=false;
    cin>>s;
    for(list<contact>::iterator i=con.begin();i!=con.end();++i)
    {
        if(i->name==s)
        {
            con.erase(i);
            cout<<"contact deleted "<<endl;
            val=true;
            break;
        }
    }
    if(val==false)
    cout<<"sorry contact not there plz add it"<<endl;
}
void search()
{
    cout<<"enter the contact u want to search ";
    string name;
    bool val;
    cin>>name;
    for(list<contact>::iterator i=con.begin();i!=con.end();++i)
    {
        if(i->name==name)
        {
            cout<<"contact found";
            val=true;
        }
    }
    if(val==false){
    cout<<"contact not found ";
    cout<<"if u want to add this contact into list"<<endl;
    cout<<"press 1 if u want to add\n or press 0 if u dont want to add"<<endl;
    int ch;
    cin>>ch;
    int s;
    string email;
    string no;
    switch(ch)
    {
        case 0:
        cout<<"contact not added";
        break;
        case 1:
        cout<<"provide details so that contact can be added into the list";
        cout<<"enter the number to be added "<<endl;
        cin>>no;
        cout<<"enter email to be added ";
        cin>>email;
        cout<<"enter the type of contact you want: ";
        cin>>s;
        break;
    }
      contact v(name,(type)s,0,no,email);
      con.push_back(v);
      cout<<"succesfully added"<<endl;}
}
void addmulti()
{
    cout<<"enter the contact u want to add mutiple numbers"<<endl;
    string name;
    cin>>name;
    for(list<contact>::iterator i=con.begin();i!=con.end();++i)
    {
        if(i->name==name)
        {
            cout<<"enter the number ";
            string no;
            cin>>no;
            int k=(*i).k+1;
            i->no[k]=no;
            cout<<"succesfully added "<<endl;
        }
    }
}
int main(void)
{ cout<<"                     ---------------------------------project title----------------------------"<<endl<<endl;
  cout<<"                     ---------------------------------contacts manager-------------------------"<<endl<<endl;
  int ch;
  do{
     cout<<"1.enter a new contact records"<<endl;
     cout<<"2.update an existing contact"<<endl;
     cout<<"3.delete an existing contact"<<endl;
     cout<<"4.search for a particular contact"<<endl;
     cout<<"5.add a multiple no to an existing contact"<<endl<<endl;
     
     cout<<"user enter your choice: ";
     cin>>ch;
     switch(ch)
     {
         case 1:
         addnew();
         break;
         case 2:
         update();
         break;
         case 3:
         del();
         break;
         case 4:
         search();
         break;
         case 5:
         addmulti();
         break;
     }
}while(ch>=1 && ch<=5);
}
