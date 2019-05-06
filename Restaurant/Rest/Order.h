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
	int waiting_time; 
	
	//
	// TODO: Add More Data Members As Needed
	//

	//Bonus : broken motorcycles

	bool criticalOrder;

public:
	Order(int ID, ORD_TYPE r_Type, REGION r_region,bool crit);
	Order(); 
	virtual ~Order();

	int GetID();

	int GetType() const;
	void setType(ORD_TYPE ordType);
	REGION GetRegion() const;

	void SetDistance(int d);
	int GetDistance() const;
	double get_money(); 
	void set_money(double mon); 
	void set_ARivval_time(int tim);
	void set_Service_time(int tim); 
	void set_Finish_time(int tim); 
	int get_AVT(); 
	int get_SVT(); 
	int get_FT(); 
	void set_wait_time(int time); 
	int get_WT(); 
	void set_wieght(int x); 
	bool operator > (const Order  &O) const ;
	bool operator < (const Order  &O) const ;
	int get_wight()const ; 

	//
	// TODO: Add More Member Functions As Needed
	//

	//Bonus: broken motorcycles
	bool get_critical_order();
	void set_critical_order(bool c);
};

#endif