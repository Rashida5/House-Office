#ifndef BUILDINGS_H
#define BUILDINGS_H
#include<bits/stdc++.h>
using namespace std;
class Buildings
{
	public:
		void setId(int);
		void setarea(int);
			void setnumofrooms(int);
			void settype(int);
			//void setplace(int);
			void setphone(long long);
			void setplace(long long);
			void showdataforowener();
			void showdataforbuyer();
			void setprice(int);
	protected:
		int ID;
		int area;
		int numofrooms;
		int type;
		long long phonenumber;
		long long place;
		int price;
	static string mm[];
		
};

#endif
