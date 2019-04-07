#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, ORD_TYPE oType, int oID,int Odistance, double Omoney, REGION reg):Event(eTime, oID)
{
	OrdType = oType;
	OrdRegion = reg;
	OrdDistance = Odistance;
	OrdMoney = Omoney;
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
	Order* pOrd = new Order(OrderID,OrdType,OrdRegion);
	pRest->AddtoDemoQueue(pOrd);

	switch (OrdType) {
		case TYPE_NRM:
			pRest->AddNormalOrder(pOrd);
			break;
		case TYPE_FROZ:
			pRest->AddFrozenOrder(pOrd);
			break;
		case TYPE_VIP:
			pRest->AddVipOrder(pOrd);
			break;
	}
		
			
}
