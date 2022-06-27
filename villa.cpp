#include "villa.h"
#include<bits/stdc++.h>
using namespace std;
villa::villa(){
	setinformationforbuyer();
}
void villa::setinformationforbuyer(){
	cout<<"How much space do you want your house start..?,do not care about area enter 0"<<'\n';
	cin>>area;
	while(area<0){
		cout<<"Sorry not allowed enter again"<<'\n';
		cin>>area;
	}
	setarea(area);
	cout<<"How many rooms do you want your house start..?,do not care about num of rooms enter 0"<<'\n';
	cin>>numofrooms;
	while(numofrooms<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms;
	}
	setnumofrooms(numofrooms);
	cout<<"your villa for rent enter 1 for sell enter 0 do not care enter -1"<<'\n';
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
	cout<<"Enter the location of the building do not care enter -1"<<'\n';
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
	cout<<"with garden enter 1 without enter 0 do not care enter -1"<<'\n';
	cin>>withgarden;
	while(withgarden!=-1&&withgarden!=0&&withgarden!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>withgarden;
	}
	setwithgarden(withgarden);
	cout<<"with pool enter 1 without enter 0 do not care enter -1"<<'\n';
	cin>>withpool;
	while(withpool!=-1&&withpool!=0&&withpool!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>withpool;
	}
	setwithpool(withpool);
	searchtxt();
	
}
void villa::searchtxt(){
	fstream s;bool x=1;
	s.open("villa.txt");
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,areaofgarden1,areaofpool1,place1,phone1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1)) { break; } // error
if((area==0||area<=area1)&&(numofrooms==0||numofrooms1>=numofrooms)&&(type==-1||type1==type)&&(price==0||price1<=price)&&(place==-1||place1==place)&&(withpool==-1||areaofpool1==withpool)&&(withgarden==-1||areaofgarden1==withgarden)){
    cout<<"The area of Building : "<<area1<<'\n'<<"The num of rooms : "<<numofrooms1<<'\n';
    if(type1==1){
    	cout<<"The rent per month : "<<price1<<'\n';
	}
	else{
		cout<<"The price of building : "<<price1<<'\n';
	}
	cout<<"The place of building : "<<mm[place1]<<'\n';
	cout<<"The num pools : "<<areaofpool1<<'\n';
	if(areaofgarden1){
		cout<<"The area of garden : "<<areaofgarden1<<" m3"<<'\n';
	}
	else{
		cout<<"The building without garden"<<'\n';
	}
	cout<<"The phone number : "<<phone1<<'\n';x=0;
	
	cout<<"--------------------------------------------------------------------------------------------"<<'\n';
}
}
if(x){
	cout<<"Sorry no building with this Specification"<<'\n';
}
 s.close();
}
villa :: villa(bool c){
	int y;
	cout<<"for insert enter 1"<<'\n';
	cout<<"for delet enter 2"<<'\n';
	cout<<"for update enter 3"<<'\n';
	cin>>y;
	while(y!=1&&y!=2&&y!=3){
		cout<<"Not allowed enter again"<<'\n';
		cin>>y;
	}
	if(y==1){
	setintxt();
	}
	else if(y==2){
		cout<<"Enter the ID of your building"<<'\n';
		cin>>ID;
		while(searchbyID(ID)==0){
			cout<<"sorry no information about it enter again"<<'\n';
			cin>>ID;
		}
		deletintxt();
	}
	else if(y==3){
		cout<<"Enter the ID of your building"<<'\n';
		cin>>ID;
		while(searchbyID(ID)==0){
			cout<<"sorry no information about it enter again"<<'\n';
			cin>>ID;
		}
		updateintxt();
	}
}
void villa::setwithgarden(int withgarden){
	this->withgarden=withgarden;
}
void villa::setwithpool(int withpool){
	this->withpool=withpool;
}
int villa::lastID(){
	fstream s;
	s.open("villa.txt");
	long long y=999;
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,areaofgarden1,areaofpool1,place1,phone1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1)) { break; } // error
//cout<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
    y=id1;
}
 s.close();
	return y+1;
}
void villa::setintxt(){
	fstream s;
	s.open("villa.txt",ios::app);
	ID=lastID();
	cout<<"what is area of  villa"<<'\n';
cin>>area;
while(area<0){
		cout<<"Sorry not allowed enter again"<<'\n';
		cin>>area;
	}
	setarea(area);
	cout<<"What is num of rooms"<<'\n';
	cin>>numofrooms;
	while(numofrooms<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms;
	}
	setnumofrooms(numofrooms);
	cout<<"your villa for rent enter 1 for sell enter 0"<<'\n';
	cin>>type;
	while(type!=0&&type!=1&&type!=-1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type;
	}
	settype(type);
	cout<<"What price do you need "<<'\n';
	cin>>price;
	while(price<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>price;
	}
	setprice(price);
cout<<"Enter the location of the building"<<'\n';
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
	cout<<"with garden enter the area of it without enter 0"<<'\n';
	cin>>withgarden;
	while(withgarden!=-1&&withgarden!=0&&withgarden!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>withgarden;
	}
	setwithgarden(withgarden);
	cout<<"with pool enter 1 without enter 0"<<'\n';
	cin>>withpool;
	while(withpool!=-1&&withpool!=0&&withpool!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>withpool;
	}
	setwithpool(withpool);
	cout<<"Enter your phone number"<<'\n';
	cin>>phonenumber;
	while(phonenumber<1000000000||phonenumber>10000000000){
		cout<<"Not allowed enter again"<<'\n';
		cin>>phonenumber;
	}
	setphone(phonenumber);
	s<<ID<<" "<<area<<" "<<numofrooms<<" "<<type<<" "<<price<<" "<<place<<" "<<withgarden<<" "<<withpool<<" "<<phonenumber<<'\n';
	cout<<"the number of your operation is "<<" "<<ID<<" "<<"please Keep It "<<'\n';
	s.close();
}
bool villa::searchbyID(int y){
	fstream s;
	s.open("villa.txt");
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,areaofgarden1,areaofpool1,place1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1)) { break; } // error
if(id1==y){
	s.close();
	return 1;
}
}
 s.close();
 return 0;
}
void villa::deletintxt(){
	fstream s,temp;
	s.open("villa.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,areaofgarden1,areaofpool1,place1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1 ))
	 { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
	 }
}
s.close();
temp.close();
s.open("villa.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1 ))
	 { break; } // error
	 	s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
}
s.close();
temp.close();
remove("temp.txt");

}
void villa::updateintxt(){
	fstream s,temp;
	s.open("villa.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    int area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1,id1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1))
	 { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
	 }
	 else{
	 	cout<<"Enter the new area "<<'\n';
	 	cin>>area1;
	 	while(area1<0){
		cout<<"Sorry not allowed enter again"<<'\n';
		cin>>area1;
	}
	 	cout<<"Enter the numofrooms"<<'\n';
	 	cin>>numofrooms1;
	 	while(numofrooms1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms1;
	}
	 	cout<<"for rent enter 1 for sell enter 0"<<'\n';
	 	cin>>type1;
	 	while(type1!=0&&type1!=1&&type1!=-1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type1;
	}
	 	cout<<"Enter the price"<<'\n';
	 	cin>>price1;
	 	while(price1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>price1;
	}
	 	cout<<"Enter the location of the building"<<'\n';
	for(int i=0;i<10;i++){
		cout<<i<<" "<<mm[i]<<'\n';
	}
	cin>>place1;
	while(1){
		if(place1>=-1&&place1<=10){
			break;
		}
		else{
			cout<<"Not allowed enter again"<<'\n';
		cin>>place1;
		}
	}
	cout<<"with garden enter 1 without enter 0"<<'\n';
	cin>>areaofgarden1;
	while(areaofgarden1!=-1&&areaofgarden1!=0&&areaofgarden1!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>areaofgarden1;
	}
	cout<<"with pool enter 1 without enter 0"<<'\n';
	cin>>areaofpool1;
	while(areaofpool1!=-1&&areaofpool1!=0&&areaofpool1!=1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>areaofpool1;
	}
		cout<<"Enter your phone number"<<'\n';
	cin>>phone1;
	while(phone1<1000000000||phone1>10000000000){
		cout<<"Not allowed enter again"<<'\n';
		cin>>phone1;
	}
	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
	 }
}
s.close();
temp.close();
s.open("villa.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,areaofgarden1,areaofpool1,place1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1))
	 { break; } // error
	 s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
	 }
s.close();
temp.close();
remove("temp.txt");

}
			
