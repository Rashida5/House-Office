#include<bits/stdc++.h>
#include"Buildings.h"
#include"villa.h"
#include"apartmentbuilding.h"
#include "apartment.h"
using namespace std;
int main(){
	cout<<"Welcome to our software plese if you are buyer enter 0 else enter 1"<<'\n';
	int c;
	cin>>c;
	while(c!=1&&c!=0){
		cout<<"Not allowed enter 1 or 0"<<'\n';
		cin>>c;
	}
	if(c){
		cout<<"for villa enter 1"<<'\n'<<"for apartment enter 2"<<'\n'<<"for apertmentbuilding enter 3"<<'\n';
		int y;
		cin>>y;
		while(y!=1&&y!=2&&y!=3){
			cout<<"Not allowed enter 1 or 2 or 3"<<'\n';
			cin>>y;
		}
		if(y==1){
			villa a(1);
		}
		else if(y==3){
		apartmentbuilding b(1);	
		}
		else if(y==2){
		apartment c(1);	
		}
	}
	else{
		cout<<"for villa enter 1"<<'\n'<<"for apartment enter 2"<<'\n'<<"for apertmentbuilding enter 3"<<'\n';
		int y;
		cin>>y;
		while(y!=1&&y!=2&&y!=3){
			cout<<"Not allowed enter 1 or 2 or 3"<<'\n';
			cin>>y;
		}
		if(y==1){
			villa a;
		}
		else if(y==3){
		apartmentbuilding b;	
		}
		else if(y==2){
			apartment c;
		}
	}
}
//>>id1>>area1>>numofrooms1>>type1>>price1>>place1>>areaofgarden1>>areaofpool1>>phone1
