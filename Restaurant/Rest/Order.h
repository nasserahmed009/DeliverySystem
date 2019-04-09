#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Frozen, VIP
	REGION Region;  //Region of this order
	int Distance;	//The distance (in meters) between the order location and the resturant 
	                
	double totalMoney;	//Total order money
	int weight; // to calculate the weight for VIP orders only  

	int ArrTime, ServTime, FinishTime;	//arrival, service start, and finish times
	
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Order(int ID, ORD_TYPE r_Type, REGION r_region);
	virtual ~Order();

	int GetID();

	int GetType() const;
	void setType(ORD_TYPE ordType);
	REGION GetRegion() const;

	void SetDistance(int d);
	int GetDistance() const;
	double get_money(); 
	void set_wieght(int x); 
	bool operator > (Order O);
	int get_wight(); 

	//
	// TODO: Add More Member Functions As Needed
	//
};

#endif