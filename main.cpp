#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class Time{
int H,M,S;
public:
Time();
Time(int,int,int);
~Time();
void setT(int,int,int);
void setH(int);
void setM(int);
void setS(int);
int getH()const;
int getM()const;
int getS()const;
void input();
void print()const;
};
class Date{
int Day,Month,Year;
public:
Date();
Date(int,int,int);
void setD(int,int,int);
void sety(int);
void setm(int);
void setd(int);
int gety()const;
int getm()const;
int getd()const;
void input();
void print()const;
};
class roydad{
char work[40];
Time start;
Date open;
public:
roydad();
void input();
void print()const;
};
Time::Time(){H=M=S=0;}
Time::Time(int h,int m,int s){
setT(h,m,s);
}
Time::~Time(){cout<<"\n\nconstroctor is called";}
void Time::setT(int h,int m,int s){
setH(h);
setM(m);
setS(s);
}
void Time::setH(int h){
H=(h>=0&&h<24)?h:0;
}
void Time::setM(int m){
M=(m>=0&&m<60)?m:0;
}
void Time::setS(int s){
S=(s>=0&&s<60)?s:0;
}
int Time::getH()const{return H;}
int Time::getM()const{return M;}
int Time::getS()const{return S;}
void Time::input(){
cout<<"hour=? minute=? second=?";
cin>>H;
cin>>M;
cin>>S;
setT(H,M,S);
}
void Time::print()const{
cout<<"\n"<<H<<":"<<M<<":"<<S<<endl;
ofstream output("file.txt",ios::out);
output<<H<<":";
output<<M<<":";
output<<S<<endl;
}
Date::Date(){Day=Month=Year=0;}
Date::Date(int y,int m,int d){
setD(y,m,d);
}
void Date::setD(int y,int m,int d){
sety(y);
setm(m);
setd(d);
}
void Date::sety(int y){
Year=(y>=2019&&y<2023)?y:0;
}
void Date::setm(int m){
Month=(m>0&&m<=12)?m:0;
}
void Date::setd(int d){
Day=(d>0&&d<31)?d:0;
}
int Date::gety()const{return Year;}
int Date::getm()const{return Month;}
int Date::getd()const{return Day;}
void Date::input(){
cout<<"year=? month=? day=?";
cin>>Year;
cin>>Month;
cin>>Day;
setD(Year,Month,Day);
}
void Date::print()const{
cout<<Year<<"/"<<Month<<"/"<<Day;
ofstream o("file.txt",ios::out);
o<<Year<<"/";
o<<Month<<"/";
o<<Day<<"\t";
}
roydad::roydad(){}
void roydad::input(){
cout<<"\nwhat do you want to do:";
cin.get();
cin.get(work,40);
open.input();
start.input();
}
void roydad::print()const{
cout<<"work:"<<work<<endl;
ofstream out("file.txt",ios::out);
out<<work<<"\t";
open.print();
start.print();
}
int main(){
int n;
cout<<"how many works do you want to do:";
cin>>n;
roydad list[n];
for(int i=0;i<n;i++){
list [i].input();
}
for(int i=0;i<n;i++){
list[i].print();
}
}
