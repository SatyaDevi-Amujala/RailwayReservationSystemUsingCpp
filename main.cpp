#include<iostream>
#include<vector>
#include<map>
using namespace std;
 map<int,int>age;
     map<int,string>name;
      map<int,char>berth;
class Bookticket{
    public:
    static int L;
    static int M;
    static int U;
    static int rac;
    static int id;
    static int waitlist;
    
     int fun(){
        int a;
        char c;
        string b;
        cout<<"Enter Name:";
        getline(cin>>ws,b);
        cout<<"Enter age:"; 
        cin>>a;
        cout<<"Enter Berth preference(Ex:for Lower->L,for Upper->U,for Middle->M)";
        cin>>c;

        if(waitlist<=0){
                cout<<"Tickets are not available";
        }
        else{
                name.insert({id,b});
                age.insert({id,a});
         if((c=='L' || c=='l') && (rac==1 and waitlist==1) && (L>0 || U>0 ||M>0)){
          if(L>0){
              berth.insert({id,toupper(c)});
              cout<<"-----------Booked Successfully-----------\n";
              cout<<"berth is Lower\n";
              cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              L--;id++;}
        else{
                if(M>0){
                berth.insert({id,'M'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Lower berth is not available alloted berth is Middle\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              M--;id++;}  
              else if(U>0){
                berth.insert({id,'U'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Lower berth is not available alloted berth is Upper\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              U--;id++;}        
                }
                }

       else if((c=='M' || c=='m') && (rac==1 and waitlist==1) && (L>0 || U>0 ||M>0)){
       if(M>0){
              berth.insert({id,toupper(c)});
                cout<<"-----------Booked Successfully-----------\n";
                 cout<<"berth is Middle\n";
                 cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
                M--;id++;
        }
         else{
                if(U>0){
                berth.insert({id,'U'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Middle berth is not available alloted berth is Upper\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              U--;id++;}  
              else if(L>0){
                berth.insert({id,'U'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Middle berth is not available alloted berth is Lower\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              L--;id++;}        
                }}
       else if((c=='U' || c=='u') && (rac==1 and waitlist==1) && (L>0 || U>0 ||M>0)){
                if(U>0){
              berth.insert({id,toupper(c)});
                cout<<"-----------Booked Successfully-----------\n";
                 cout<<"berth is Upper\n";
                 cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
                U--;id++;
        }
        else{
                if(M>0){
                berth.insert({id,'M'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Upper berth is not available alloted berth is Middle\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              M--;id++;}  
              else if(L>0){
                berth.insert({id,'U'});
                cout<<"-----------Booked Successfully-----------\n";
                cout<<"Upper berth is not available alloted berth is Lower\n";
                cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
              L--;id++;}        
                }}
       else if(rac > 0){
              berth.insert({id,'R'});
                cout<<"Your Ticket is RAC check status for confirming your ticket\n";
                 cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
                rac--;id++;
        }
        else{
           berth.insert({id,'W'}); 
           cout<<"Your Ticket is waiting List check status for confirming your ticket\n";
            cout<<"Your Ticket id is "<<id<<"\nPlease remember your id for further process.\n";
             waitlist--;id++; 
        }

        }

}
};
int Bookticket ::L=2; 
int Bookticket :: M=2;
int Bookticket :: U=1;
int Bookticket :: rac=1;
int Bookticket :: id=0;
int Bookticket :: waitlist=1;
class Cancelticket : public Bookticket{
    public:
    int l=10000;
     int fun1(){
        int id;
        cout<<"Enter Id:";
        cin>>id;
        if(berth[id] =='W'){
           berth.erase(id);
           age.erase(id);
           name.erase(id); 
           waitlist++;    
        }
        else if(berth[id]=='R'){
            berth.erase(id);
           age.erase(id);
           name.erase(id); 
           for(auto i=berth.begin();i!=berth.end();i++){
                if(i->second=='W'){
                  l=min(l,i->first);     
                } }
                berth[l]='R';
                waitlist++;    
        }
        else if(berth[id]=='L' || berth[id]=='U'|| berth[id]=='M'){
                char c=berth[id];
            berth.erase(id);
           age.erase(id);
           name.erase(id); 
           for(auto i=berth.begin();i!=berth.end();i++){
                if(i->second=='R'){
                  l=min(l,i->first);     
                } }
                if(l!=100){
                berth[l]=c;
                if(c=='U')U++;
                if(c=='M')M++;
                if(c=='L')L++;}
                 for(auto i=berth.begin();i!=berth.end();i++){
                if(i->second=='W'){
                  l=min(l,i->first);     
                } }
                if(l!=100){
                berth[l]='R';
                waitlist++; }
                   
        }
        }
};
class Availabletickets: public Bookticket{
    public:
     
     int fun2(){
        cout<<"Available Lower berth Tickets are:"<<L<<"\n";
        cout<<"Available Middle berth Tickets are:"<<M<<"\n";
        cout<<"Available Upper berth Tickets are:"<<U<<"\n";
        cout<<"RAC Tickets are:"<<rac<<"\n";
        cout<<"waiting List:"<<waitlist<<"\n";
}
};
class Bookedtickets{
    public:

     int fun3(){
                for(auto i=name.begin();i!=name.end();i++){
                        cout<<"Name:"<<i->second<<"\n";
                        cout<<"Age:"<<age[i->first]<<"\n";
                        cout<<"berth:"<<berth[i->first]<<"\n";
                        cout<<"\n";
                }}
};

int main(){
    
    bool loop=true;
while(loop){
 cout<<"\n-----Choose option--------\n";
 cout<<"1.Book ticket\n";
 cout<<"2.Cancel ticket\n";
 cout<<"3.Available Tickets\n";
 cout<<"4.Booked Tickets\n";
 cout<<"5.Exit\n";
 int num;
 cin>>num;
 switch(num){
case 1:{Bookticket obj;
        obj.fun();
        break;}
case 2:{Cancelticket obj1;
        obj1.fun1();
        break;}
case 3:{Availabletickets obj2;
        obj2.fun2();
        break;}
case 4:{Bookedtickets obj3;
        obj3.fun3();
        break;}
case 5:loop=false;
 }
    }
   
}