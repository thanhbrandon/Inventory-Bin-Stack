#ifndef PARKED_CAR_H
#define PARKED_CAR_H
#include<string>
using namespace std;

class InventoryPart {
private:
	int serialNum;
	string manufactDate;
	int lotNum;

public:
	InventoryPart(int x, string y, int z) {
		serialNum = x;
		manufactDate = y;
		lotNum = z;
	}

	int getSerialNum()
	{
		return serialNum;
	}
	string getManufactDate()
	{
		return manufactDate;
	}
	int getLotNum()
	{
		return lotNum;
	}
};

#endif