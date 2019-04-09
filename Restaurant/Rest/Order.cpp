#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type, REGION r_region)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
}

Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


int Order::GetType() const
{
	return type;
}

void Order::setType(ORD_TYPE ordType)
{
	type = ordType;
}

REGION Order::GetRegion() const
{
	return Region;
}

void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}
double Order::get_money() {
	return totalMoney; 
}
void Order::set_wieght(int x) {
	weight = x; 
}
bool Order::operator> (Order O) {
	if (weight > O.get_wight()) {
		return true;
	}
	else return false; 
}
int  Order::get_wight() {
	return weight;
}
