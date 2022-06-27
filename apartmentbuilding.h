#ifndef APARTMENTBUILDING_H
#define APARTMENTBUILDING_H

#include "Buildings.h"

class apartmentbuilding : public Buildings
{
	public:
		apartmentbuilding();
		apartmentbuilding(bool);
		void setnumoffloors(int);
		void setelevator(int);
		void setnumofflats(int);
		void Adminorhous(int);
		void insert();
		int lastid();
		void delet();
		void updata();
		bool searchbyid(int);
		void setallinformation();
		void searchaboutinformation();
	private:
		int numoffloors;
		int numofflats;
		int numofelevator;
		int hous;
};

#endif
