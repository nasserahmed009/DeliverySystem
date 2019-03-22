#include "PromotionEvent.h"
#include "..\Rest\Restaurant.h"



PromotionEvent::PromotionEvent(int eTime,int oID,double money):Event(eTime,oID)
{
	moneyPaid = money;
}

void PromotionEvent::Execute(Restaurant * pRest)
{
	pRest->promoteOrder(pRest->getOrderById(OrderID));
}


PromotionEvent::~PromotionEvent()
{
}