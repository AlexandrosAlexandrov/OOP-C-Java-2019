#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

struct parcel{
	int parcelid, branchid, space;
};

int myrand(){
	return log(rand());
}

parcel* Func (int branchID, int* parcelCount){
	static int parcelID = 0;
	
	*parcelCount = myrand();
	parcel* parcels = new parcel[*parcelCount];
	
	for (int i = 0; i < *parcelCount; i++)
	{
		parcels[i].parcelid = parcelID;
		parcels[i].branchid = branchID;
		parcels[i].space = myrand();
		
		parcelID++;
	}
	
	return parcels;
}

int main(){
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++)
	{
		int parcelCount = 0;
		parcel* parcels = Func(i, &parcelCount);
		
		for (int j = 0; j < parcelCount; j++)
		{
			cout << parcels[j].parcelid << endl;
		}
		
	}
	
}

