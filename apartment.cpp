#include "apartment.h"
#include<bits/stdc++.h>
using namespace std;
void apartment::setfloor(int floor){
	this->floor=floor;
}
void apartment::setelevator(int elevator){
	this->elevator=elevator;
}
apartment::apartment(){
	setinfo();
}
apartment::apartment(bool c){
	cout<<"for insert enter 1"<<'\n';
	cout<<"for delet enter 2"<<'\n';
	cout<<"for update enter 3"<<'\n';
	int t;
	cin>>t;
	while(t!=1&&t!=2&&t!=3){
		cout<<"NOt allowed enter again"<<'\n';cin>>t;
	}
	if(t==1){
		insertflat();
	}
	else if(t==2){
		cout<<"Enter the ID"<<'\n';
		cin>>ID;
		while(searchidflat(ID)==0){
			cout<<"NO information about it enter again"<<'\n';
			cin>>ID;
		}
		deletflat();
	}
	else if(t==3){
		cout<<"Enter the ID"<<'\n';
		cin>>ID;
		while(searchidflat(ID)==0){
			cout<<"NO information about it enter again"<<'\n';
			cin>>ID;
		}
		updateflat();
	}
}
int apartment::lastidflat(){
		fstream s;
	s.open("apartment.txt");
	long long y=999;
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,floor1,elevator1,phone1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phone1)) { break; } // error
//cout<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
    y=id1;
}
 s.close();
	return y+1;
}
void apartment::insertflat(){
	fstream s;
	s.open("apartment.txt",ios::app);
	ID=lastidflat();
	cout<<"what is area of apartment"<<'\n';
	cin>>area;
	while(area<=0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>area;
	}
	setarea(area);
	cout<<"What is num of rooms in the flat"<<'\n';
	cin>>numofrooms;
	while(numofrooms<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms;
	}
	setnumofrooms(numofrooms);
	cout<<"your flat for rent enter 1 for sell enter 0"<<'\n';
	cin>>type;
	while(type!=1&&type!=0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type;
	}
	settype(type);
	cout<<"What price do you need "<<'\n';
	cin>>price;
	while(price<=0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>price;
	}
	setprice(price);
cout<<"Enter the location of the flat"<<'\n';
	for(int i=0;i<10;i++){
		cout<<i<<" "<<mm[i]<<'\n';
	}
	cin>>place;
	while(place<0||place>9){
		cout<<"Not allowed enter again"<<'\n';
		cin>>place;
	}
	setplace(place);
	cout<<"Enter the floor"<<'\n';
	cin>>floor;
	while(floor<0){
			cout<<"Not allowed enter again"<<'\n';
		cin>>floor;
	}
	setfloor(floor);
	cout<<"If there's an elevator, enter 1. Otherwise, enter 0."<<'\n';
	cin>>elevator;
	while(elevator!=0&&elevator!=2){
		cout<<"Not allowed enter again"<<'\n';
		cin>>elevator;	
	}
	setelevator(elevator);
	cout<<"Enter your phonenumber";
	cin>>phonenumber;
	while(phonenumber<1000000000||phonenumber>=10000000000){
		cout<<"Not allowed your phone number must be 12 digits";
		cin>>phonenumber;
	}
	setphone(phonenumber);
	s<<ID<<" "<<area<<" "<<numofrooms<<" "<<type<<" "<<price<<" "<<place<<" "<<floor<<" "<<elevator<<" "<<phonenumber<<'\n';
		cout<<"the number of your operation is "<<" "<<ID<<" "<<"please Keep It "<<'\n';
}
int apartment::searchidflat(int y){
		fstream s;
	s.open("apartment.txt");
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    //cout<<line<<'\n';
    int id1,area1,numofrooms1,type1,price1,place1,floor1,elevator1,phonenumber1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1)) { break; } 
	// error
if(id1==y){
	s.close();
	return 1;
}
}
 s.close();
 return 0;
}
void apartment::deletflat(){
	fstream s,temp;
	int id1,area1,numofrooms1,type1,price1,place1,floor1,elevator1,phonenumber1;
	s.open("apartment.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1)) { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<floor1<<" "<<elevator1<<" "<<phonenumber1<<'\n';
	 }
}
s.close();
temp.close();
s.open("apartment.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
  //  int id1,area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1))
	 { break; } // error
	 	s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<floor1<<" "<<elevator1<<" "<<phonenumber1<<'\n';
}
s.close();
temp.close();
remove("temp.txt");
}
void apartment::updateflat(){
		fstream s,temp;
	int id1,area1,numofrooms1,type1,price1,place1,floor1,elevator1,phonenumber1;
	s.open("apartment.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1)) { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<floor1<<" "<<elevator1<<" "<<phonenumber1<<'\n';
	 }
	 else{
	 		cout<<"what is area of apartment"<<'\n';
            cin>>area1;
    while(area1<=0){
    	cout<<"Not allowed enter again"<<'\n';
    	cin>>area1;
	}
	cout<<"What is num of rooms in the flat"<<'\n';
	cin>>numofrooms1;
	while(numofrooms1<0){
		cout<<"Not allowed enter again"<<'\n';
    	cin>>numofrooms1;
	}
	cout<<"your flat for rent enter 1 for sell enter 0"<<'\n';
	cin>>type1;
	while(type1!=1&&type1!=0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type1;
	}
	cout<<"What price do you need "<<'\n';
	cin>>price1;
	while(price1<=0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>price1;
	}
cout<<"Enter the location of the flat"<<'\n';
	for(int i=0;i<10;i++){
		cout<<i<<" "<<mm[i]<<'\n';
	}
	cin>>place1;
	while(place1<0||place1>9){
		cout<<"Not allowed enter again"<<'\n';
		cin>>place1;
	}
	cout<<"Enter the floor"<<'\n';
	cin>>floor1;
	while(floor1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>floor1;
	}
	cout<<"If there's an elevator, enter 1. Otherwise, enter 0."<<'\n';
	cin>>elevator1;
	while(elevator1!=0&&elevator!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>elevator1;
	}
	cout<<"Enter your phonenumber";
	cin>>phonenumber1;
	while(phonenumber1<1000000000||phonenumber1>=10000000000){
		cout<<"Not allowed your phone number must be 12 digits";
		cin>>phonenumber1;
	}
	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<floor1<<" "<<elevator1<<" "<<phonenumber1<<'\n';
	 }
}
s.close();
temp.close();
s.open("apartment.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
  //  int id1,area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1))
	 { break; } // error
	 	s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<floor1<<" "<<elevator1<<" "<<phonenumber1<<'\n';
}
s.close();
temp.close();
remove("temp.txt");
}
void apartment::setinfo(){
	cout<<"How much space do you want your apartment start..?,do not care about area enter 0"<<'\n';
	cin>>area;
	while(area<0){
		cout<<"Sorry not allowed enter again"<<'\n';
		cin>>area;
	}
	setarea(area);
	cout<<"How many rooms do you want your apertment start..?,do not care about num of rooms enter 0"<<'\n';
	cin>>numofrooms;
	while(numofrooms<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms;
	}
	setnumofrooms(numofrooms);
	cout<<"your apertment for rent enter 1 for sell enter 0 do not care enter -1"<<'\n';
	cin>>type;
	while(type!=0&&type!=1&&type!=-1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type;
	}
	settype(type);
	cout<<"What is maximum of price you need...?do not care enter 0"<<'\n';
	cin>>price;
	while(price<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>price;
	}
	setprice(price);
	cout<<"Enter the location of the apertment do not care enter -1"<<'\n';
	for(int i=0;i<10;i++){
		cout<<i<<" "<<mm[i]<<'\n';
	}
	cin>>place;
	while(1){
		if(place>=-1&&place<=10){
			break;
		}
		else{
			cout<<"Not allowed enter again"<<'\n';
		cin>>place;
		}
	}
	setplace(place);
	cout<<"Enter the maximum floor need if you do not care about floor enter -1"<<'\n';
	cin>>floor;
	while(floor<-1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>floor;
	}
	setfloor(floor);
	searchapartment();
}
void apartment::searchapartment(){
		fstream s;
	s.open("apartment.txt");
 string line;bool x=1;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,floor1,elevator1,phonenumber1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>floor1>>elevator1>>phonenumber1)) { break; } // error
    if((area==0||area<=area1)&&(numofrooms==0||numofrooms1>=numofrooms)&&(type==-1||type1==type)&&(price==0||price1<=price)&&(place==-1||place1==place)&&(floor==-1||floor>=floor1)){
    	 cout<<"The area of Building : "<<area1<<'\n'<<"The num of rooms : "<<numofrooms1<<'\n';
    if(type1==1){
    	cout<<"The rent per month : "<<price1<<'\n';
	}
	else{
		cout<<"The price of building : "<<price1<<'\n';
	}
	cout<<"The place of building : "<<mm[place1]<<'\n';
	cout<<"The num of floor : "<<floor1<<'\n';
	cout<<"The num of elevators : "<<elevator1<<'\n';
	cout<<"The phone number : "<<phonenumber1<<'\n'; x=0;
	cout<<"--------------------------------------------------------------------------------------------"<<'\n';
	}
}
if(x){
	cout<<"Sorry no building with this Specification"<<'\n';
}
s.close();
}
