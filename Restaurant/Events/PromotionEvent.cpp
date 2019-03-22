#include "PromotionEvent.h"



PromotionEvent::PromotionEvent(int eTime,int oID,double money):Event(eTime,oID)
{
	moneyPaid = money;
}

void PromotionEvent::Execute(Restaurant * pRest)
{
}


PromotionEvent::~PromotionEvent()
{
}