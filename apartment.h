#ifndef APARTMENT_H
#define APARTMENT_H

#include "Buildings.h"

class apartment : public Buildings
{
	private :
		int floor;
		int elevator;
	public:
		apartment();
		apartment(bool);
		void setfloor(int);
		void searchapartment();
		void setelevator(int);
		void insertflat();
		void deletflat();
		void updateflat();
		int lastidflat();
		void setinfo();
		int searchidflat(int);
};

#endif
