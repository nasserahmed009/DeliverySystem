#pragma once
#include "Event.h"
class PromotionEvent :
	public Event
{
	//info about the order ralted to promotion event
	double moneyPaid;
public:
	PromotionEvent(int eTime,int oId,double money);
	virtual void Execute(Restaurant* pRest);
	~PromotionEvent();
};

