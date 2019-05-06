#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, ORD_TYPE oType, int oID,int Odistance, double Omoney, REGION reg,bool crit):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
	OrdDistance = Odistance;
	OrdMoney = Omoney;
	criticalEvent = crit;
}

ArrivalEvent::ArrivalEvent(int eTime, int O_id, ORD_TYPE OType, REGION reg):Event(eTime,O_id)
{
	OrdType = OType;
	OrdRegion = reg;
}

ORD_TYPE ArrivalEvent::getOrderType()
{
	return OrdType;
}

REGION ArrivalEvent::getOrderRegion()
{
	return OrdRegion;
}

void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create and order and and fills its data 
	// Then adds it to normal, frozen, or VIP order lists that you will create in phase1

	
	
	///For the sake of demo, this function will just create an order and add it to DemoQueue
	///Remove the next code lines in phase 1&2
	Order* pOrd = new Order(OrderID,OrdType,OrdRegion,criticalEvent);
	pOrd->SetDistance(get_ord_dis());
	pOrd->set_ARivval_time(getEventTime());
	pOrd->set_money(get_ord_money());
//	pRest->AddtoDemoQueue(pOrd); for demo only no need to be excuted in phase 1 

	switch (OrdType) {
		case TYPE_NRM:
			pRest->AddNormalOrder(pOrd);
			break;
		case TYPE_FROZ:
			pRest->AddFrozenOrder(pOrd);
			break;
		case TYPE_VIP:
			// Calculation the weight of this viP order 
			double mon = get_ord_money();
			int dis = get_ord_dis();
			int tim = this->getEventTime(); 
			pOrd->set_wieght(2 * mon + dis + tim);
			pRest->AddVipOrder(pOrd);
			break;
	}
		
			
}
double ArrivalEvent::get_ord_money() {
	return OrdMoney; 
}
int ArrivalEvent::get_ord_dis() {
	return OrdDistance;
}