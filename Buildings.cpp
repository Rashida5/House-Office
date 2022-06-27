#include "Buildings.h"
#include<bits/stdc++.h>
using namespace std;
void Buildings::setId(int ID){
			this->ID=ID;
		}
void Buildings::setarea(int area){
			this->area=area;
		}
void Buildings::setnumofrooms(int numofrooms){
			this->numofrooms=numofrooms;
		}
void Buildings::settype(int type){
			this->type=type;
		}
void Buildings::setplace(long long place){
	this->place=place;
}
void Buildings::setphone(long long phonenumber){
	this->phonenumber=phonenumber;
}
void Buildings::setprice(int price){
	this->price=price;
}	
void Buildings::showdataforbuyer(){
	cout<<"The area :"<<area<<'\n';
	cout<<"The num of rooms : "<<numofrooms<<'\n';
	cout<<"The price : "<<price<<'\n';
}
string Buildings::mm[10]={"ElBagour","Ashmoun","ElShohada","BirketelSab","ElSadat","Menouf","Quweisna","ShibinelKom","SersElLyan","Tala"};
