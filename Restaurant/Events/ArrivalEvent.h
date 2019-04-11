#ifndef __ARRIVAL_EVENT_H_
#define __ARRIVAL_EVENT_H_

#include "Event.h"


//class for the arrival event
class ArrivalEvent: public Event
{
	//info about the order ralted to arrival event
	int OrdDistance;	//order distance
	ORD_TYPE OrdType;		//order type: Normal, Frozen, VIP
	REGION OrdRegion;  //Region of this order	                
	double OrdMoney;	//Total order money
public:
	ArrivalEvent (int eTime, ORD_TYPE oType, int oID, int Odistance, double Omoney, REGION reg);
	ArrivalEvent(int eTime, int O_id, ORD_TYPE OType, REGION reg);
	ORD_TYPE getOrderType();
	REGION getOrderRegion();
	double get_ord_money(); 
	int get_ord_dis(); 
	//Add more constructors if needed
	
	virtual void Execute(Restaurant *pRest);	//override execute function

};

#endif