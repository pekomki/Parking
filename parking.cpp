#include <iostream>
#include <stdlib.h>
#include <ctime> 
#include<windows.h> 
#include <fstream>
#include<string>
#include <iomanip>


using namespace std;
 

int xronos(int* hours,int* minutes,int epilogi){
 time_t currentTime;
  struct tm *localTime;
  time(&currentTime);
  localTime = localtime(&currentTime);
hours[epilogi]=localTime->tm_hour;
minutes[epilogi] = localTime->tm_min;

string s = to_string(hours[epilogi]);
string m = to_string(minutes[epilogi]);
ofstream outdata;
outdata.open("outfile.csv",ios::app);
outdata<<" : "<<s<<"."<<m<<endl;
}
int bale(int size,int* pin,int epilogi){
    system("cls");
    ofstream outdata;
    string pinakida;
    cout<<" PINAKIDA OXHMATOS : ";
    cin>>pinakida;
    for(int i=0;i<=size;i++){
        if(pin[i]==0){
            cout<<"\n"<< i << ": KENI";
        }
        else{
            cout<<"\n"<< i << ": GEMATO";
        }
    }
    
  do{
  cin>>epilogi;
  if(pin[epilogi]==1){
    cout<<":H THESI"<<pin[epilogi]<<"EINAI GEMATI:";
  }
  }while(pin[epilogi]!=0); 
  pin[epilogi]=1;
  outdata.open("outfile.csv",ios::app);
  outdata<<"MPHKE : "<<pinakida<<" THESI : "<<pin[epilogi];
  //etoimo
}
int bgale(int size,int* pin,int epilogi){

  system("cls");
    for(int i=0;i<=size;i++){
        if(pin[i]==0){
            cout<<"\n"<< i << ": KENI";
        }
        else{
            cout<<"\n"<< i << ": GEMATO";
        }
    }
do{
  cin>>epilogi;
  if(pin[epilogi]==0){
    cout<<":H THESI"<<pin[epilogi]<<"EINAI ADEIA:";
  }
  }while(pin[epilogi]!=1);
  pin[epilogi]=0;
  Sleep(1000);
 //etoimo
}
int xronosejw(int* hours,int* minutes,int epilogi){
  int wratwra,mintwra;
  time_t currentTime;
  struct tm *localTime;
  time(&currentTime);
  localTime = localtime(&currentTime);
  wratwra=localTime->tm_hour;
  mintwra=localTime->tm_min;
  wratwra=wratwra-hours[epilogi];
  if(wratwra<0){
    wratwra=-wratwra;
  }
  mintwra=mintwra-minutes[epilogi];
  if(mintwra<0){
    mintwra=-mintwra;
  }
  int a=0;
  a=wratwra+mintwra/60;
cout<<"TO AMAJI APO TI THESI:  "<<epilogi<<"  EXEI KOSTOS:"<<a;
Sleep(3000);
//etoimo
}
int view(int size,int* pin){
  system("cls");
   cout<<"::VIEW::";
    for(int i=0;i<=size;i++){
        if(pin[i]==0){
            cout<<"\n"<< i << ": KENI";
        }
        else{
            cout<<"\n"<< i << ": GEMATO";
        }
    }
    cout<<"\n"<<"::0.EXODOS::";
    int ans;
    do{
      cin>>ans;
    }while(ans!=0);
    //etoimo
}
 int loop(int* pin,int size,int epilogi){
// dimiourgia pinakwn gia tis wres kai ta lepta
  
  int e=10;
  int hours[e];
  int minutes[e];
  time_t currentTime;
  struct tm *localTime;
  time(&currentTime);
  localTime = localtime(&currentTime);
  for (int i = 0; i < e; ++i) {
        hours[i] = localTime->tm_hour;
    }
    for (int i = 0; i < e; ++i) {
        minutes[i] = localTime->tm_min;
    }
//etoimo
//DEN PEIRAZEIS TIPOTA APO PANW!
bool exodos=true;
 ofstream outdata;

  do{
  Sleep(100);
   system("cls");
   cout<<"\n"<<"PARKING SYSTEM";
   cout<<"\n"<<"1: EISODOS";
   cout<<"\n"<<"2: EXODOS";
   cout<<"\n"<<"3: VIEW";
   cout<<"\n"<<"4: EXODOS"<<"\n";
   cin>>epilogi;

 if(epilogi==1){
      bale(size,pin,epilogi);
      xronos(hours,minutes,epilogi);
      
    }
  else if(epilogi==2){
    bgale(size,pin,epilogi);
    xronosejw(hours,minutes,epilogi);
   }
   else if(epilogi==3){
    view(size,pin);
   }
   else if(epilogi==4){
    exodos=false;
   }
  }while(exodos);
  cout<<"\n"<<"EFXARISTOUME POLU GIA TIN SYNERGASIA!!!";
  Sleep(5000);
}



int main(){
int slots[9]={0,0,0,0,0,0,0,0,0},epilogi;
 
loop(slots,8,epilogi);
 



    return 0;
}
