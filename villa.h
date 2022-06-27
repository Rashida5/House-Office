#ifndef VILLA_H
#define VILLA_H

#include "Buildings.h"

class villa : public Buildings
{
private:
	int withgarden;
	int withpool;
	public:
		villa();
		villa(bool);
		void setwithgarden(int);
		void setwithpool(int);
		bool searchbyID(int);
		void setintxt();
		void searchtxt();
		void deletintxt();
		void updateintxt();
		void setinformationforbuyer();
		void searchaboutinformation() ;//search about 
		int lastID();
		
};

#endif
