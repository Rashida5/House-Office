#include "apartmentbuilding.h"
#include<bits/stdc++.h>
using namespace std;
apartmentbuilding::apartmentbuilding(bool c)
{
	cout<<"for insert enter 1"<<'\n';
	cout<<"for delet enter 2"<<'\n';
	cout<<"for update enter 3"<<'\n';
	int t;
	cin>>t;
	while(t!=1&&t!=2&&t!=3){
		cout<<"NOt allowed enter again"<<'\n';cin>>t;
	}
	if(t==1){
		insert();
	}
	else if(t==2){
		cout<<"Enter the ID"<<'\n';
		cin>>ID;
		while(searchbyid(ID)==0){
			cout<<"NO information about it enter again"<<'\n';
			cin>>ID;
		}
		delet();
	}
	else if(t==3){
		cout<<"Enter the ID"<<'\n';
		cin>>ID;
		while(searchbyid(ID)==0){
			cout<<"NO information about it enter again"<<'\n';
			cin>>ID;
		}
		updata();
	}
}
apartmentbuilding::apartmentbuilding(){
	setallinformation();
}
void apartmentbuilding::setnumoffloors(int numoffloors){
	this->numoffloors=numoffloors;
}
void apartmentbuilding::setelevator(int numofelevator){
	this->numofelevator=numofelevator;
}
void apartmentbuilding::Adminorhous(int hous){
	this->hous=hous;
}
void apartmentbuilding::setnumofflats(int numofflats){
	this->numofflats=numofflats;
}
void apartmentbuilding::insert(){
	fstream s;
	s.open("apartmentbuilding.txt",ios::app);
	ID=lastid();
	cout<<"what is area of apartmentbuilding"<<'\n';
cin>>area;
while(area<0){
		cout<<"Sorry not allowed enter again"<<'\n';
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
	cout<<"your building for rent enter 1 for sell enter 0"<<'\n';
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
	cout<<"Enter the num of floors in building"<<'\n';
	cin>>numoffloors;
	while(numoffloors<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numoffloors;
	}
	setnumoffloors(numoffloors);
	cout<<"Enter the num of flats in building"<<'\n';
	cin>>numofflats;
	while(numofflats<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofflats;
	}
	setnumofflats(numofflats);
	cout<<"If your building have enter the num of elevator else enter 0"<<'\n';
	cin>>numofelevator;
	while(numofelevator<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofelevator;
	}
	setelevator(numofelevator);
	cout<<"If your building for housing enter 1 ,Administartive enter 0"<<'\n';
	cin>>hous;
	while(hous!=1&&hous!=0){
		cout<<"Not allowed please enter again"<<'\n';
		cin>>hous;
	}
	Adminorhous(hous);
	cout<<"Enter your phonenumber";
	cin>>phonenumber;
	setphone(phonenumber);
	s<<ID<<" "<<area<<" "<<numofrooms<<" "<<type<<" "<<price<<" "<<place<<" "<<numoffloors<<" "<<numofflats<<" "<<numofelevator<<" "<<hous<<" "<<phonenumber<<'\n';
		cout<<"the number of your operation is "<<" "<<ID<<" "<<"please Keep It "<<'\n';
	s.close();
}
int apartmentbuilding::lastid(){
		fstream s;
	s.open("apartmentbuilding.txt");
	long long y=999;
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,numoffloors1,numofflats1,numofelevator1,hous1,phonenumber1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1)) { break; } // error
//cout<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<areaofgarden1<<" "<<areaofpool1<<" "<<phone1<<'\n';
    y=id1;
}
 s.close();
	return y+1;
}
bool apartmentbuilding::searchbyid(int y){
		fstream s;
	s.open("apartmentbuilding.txt");
 string line;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,numoffloors1,numofflats1,numofelevator1,hous1,phonenumber1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1)) { break; } // error
if(id1==y){
	s.close();
	return 1;
}
}
 s.close();
 return 0;
}
void apartmentbuilding::delet(){
	fstream s,temp;
	int id1,area1,numofrooms1,type1,price1,place1,numoffloors1,numofflats1,numofelevator1,hous1,phonenumber1;
	s.open("apartmentbuilding.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1))
	 { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<numoffloors1<<" "<<numofflats1<<" "<<numofelevator1<<" "<<hous1<<" "<<phonenumber1<<'\n';
	 }
}
s.close();
temp.close();
s.open("apartmentbuilding.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
  //  int id1,area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1))
	 { break; } // error
	 	s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<numoffloors1<<" "<<numofflats1<<" "<<numofelevator1<<" "<<hous1<<" "<<phonenumber1<<'\n';
}
s.close();
temp.close();
remove("temp.txt");
}
void apartmentbuilding::updata(){
	fstream s,temp;
	int id1,area1,numofrooms1,type1,price1,place1,numoffloors1,numofflats1,numofelevator1,hous1,phonenumber1;
	s.open("apartmentbuilding.txt",ios::in);
	temp.open("temp.txt",ios::out);
 string line;
while (getline(s, line))
{
    std::istringstream iss(line);
    
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1))
	 { break; } // error
	 if(id1!=ID){
	 	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<numoffloors1<<" "<<numofflats1<<" "<<numofelevator1<<" "<<hous1<<" "<<phonenumber1<<'\n';
	 }
	 else{
	 	cout<<"what is area of apartmentbuilding"<<'\n';
cin>>area1;
while(area1<0){
		cout<<"Sorry not allowed enter again"<<'\n';
		cin>>area1;
	}
	cout<<"What is num of rooms in the flat"<<'\n';
	cin>>numofrooms1;
	while(numofrooms1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofrooms1;
	}
	cout<<"your villa for rent enter 1 for sell enter 0"<<'\n';
	cin>>type1;
	while(type1!=0&&type1!=1&&type1!=-1){
		cout<<"Not allowed enter again"<<'\n';
		cin>>type1;
	}
	cout<<"What price do you need "<<'\n';
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
	cout<<"Enter the num of floors in building"<<'\n';
	cin>>numoffloors1;
	while(numoffloors1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numoffloors1;
	}
	cout<<"Enter the num of flats in building"<<'\n';
	cin>>numofflats1;
	while(numofflats1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofflats1;
	}
	cout<<"If your building have enter the num of elevator else enter 0"<<'\n';
	cin>>numofelevator1;
	while(numofelevator1<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofelevator1;
	}
	cout<<"If your building for housing enter 1 ,Administartive enter 0"<<'\n';
	cin>>hous1;
	while(hous1!=1&&hous1!=0){
		cout<<"Not allowed please enter again"<<'\n';
		cin>>hous1;
	}
	cout<<"Enter your phonenumber";
	cin>>phonenumber1;
	while(phonenumber1<1000000000||phonenumber1>10000000000){
		cout<<"Not allowed please enter again"<<'\n';
		cin>>phonenumber1;
	}
	temp<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<numoffloors1<<" "<<numofflats1<<" "<<numofelevator1<<" "<<hous1<<" "<<phonenumber1<<'\n';
	 }
}
s.close();
temp.close();
s.open("apartmentbuilding.txt",ios::out);
temp.open("temp.txt",ios::in);
while (getline(temp, line))
{
    std::istringstream iss(line);
  //  int id1,area1,numofrooms1,type1,price1,place1,areaofgarden1,areaofpool1,phone1;
    if (!(iss>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1))
	 { break; } // error
	 	s<<id1<<" "<<area1<<" "<<numofrooms1<<" "<<type1<<" "<<price1<<" "<<place1<<" "<<numoffloors1<<" "<<numofflats1<<" "<<numofelevator1<<" "<<hous1<<" "<<phonenumber1<<'\n';
}
s.close();
temp.close();
remove("temp.txt");
}
void apartmentbuilding::setallinformation(){
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
	cout<<"How many floors do you want your buildings start..?,do not care about num of floors enter 0";
	cin>>numoffloors;
	while(numoffloors<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numoffloors;
	}
	setnumoffloors(numoffloors);
	cout<<"How many flats do you want your buildings start..?,do not care about num of flats enter 0";
	cin>>numofflats;
	while(numofflats<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofflats;
	}
	setnumofflats(numofflats);
	cout<<"How many elevators do you want your buildings start..?,do not care about num of floors enter 0";
	cin>>numofelevator;
	while(numofelevator<0){
		cout<<"Not allowed enter again"<<'\n';
		cin>>numofelevator;
	}
	setelevator(numofflats);
	cout<<"if you need Administartive building enter 0 else enter 1 "<<'\n';
	while(hous!=1&&hous!=0){
		cout<<"Not allowed please enter again"<<'\n';
		cin>>hous;
	}
	Adminorhous(hous);
	searchaboutinformation();

}
void apartmentbuilding::searchaboutinformation(){
	fstream s;
	s.open("apartmentbuilding.txt");
 string line;bool x=1;
while (std::getline(s, line))
{
    std::istringstream iss(line);
    int id1,area1,numofrooms1,type1,price1,place1,numoffloors1,numofflats1,numofelevator1,hous1,phonenumber1;
    if (!(iss >>id1>>area1>>numofrooms1>>type1>>price1>>place1>>numoffloors1>>numofflats1>>numofelevator1>>hous1>>phonenumber1)) { break; } // error
    if((area==0||area<=area1)&&(numofrooms==0||numofrooms1>=numofrooms)&&(type==-1||type1==type)&&(price==0||price1<=price)&&(place==-1||place1==place)&&(numoffloors==0||numoffloors<=numoffloors1)&&(numofflats<=numofflats1)&&(numofelevator<=numofelevator1)&&(hous==hous)){
    	 cout<<"The area of Building : "<<area1<<'\n'<<"The num of rooms : "<<numofrooms1<<'\n';
    if(type1==1){
    	cout<<"The rent per month : "<<price1<<'\n';
	}
	else{
		cout<<"The price of building : "<<price1<<'\n';
	}
	cout<<"The place of building : "<<mm[place1]<<'\n';
	cout<<"The num of floors : "<<numoffloors1<<'\n';
	cout<<"The num of flats : "<<numofflats1<<'\n';
	cout<<"The num of elevators : "<<numofelevator1<<'\n';
	cout<<"The phone number : "<<phonenumber1<<'\n'; x=0;
	cout<<"--------------------------------------------------------------------------------------------"<<'\n';
	}
}
if(x){
	cout<<"Sorry no building with this Specification"<<'\n';
}
s.close();}
