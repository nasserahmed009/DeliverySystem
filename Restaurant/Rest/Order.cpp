#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type, REGION r_region)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	Region = r_region;	
	this->criticalOrder = 0;
}

Order::~Order()
{
}
Order::Order() {
	this->criticalOrder = 0;
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
bool Order::operator > (const Order &O) const{
	if (weight > O.get_wight()){
		return true;
	}
	else return false; 
}
bool Order::operator < (const Order &O) const {
	if (FinishTime < O.FinishTime) {
		return true;
	}
	else if (ServTime < O.ServTime) {
		return true;
	}
	else {
		return false;
	}
}
int  Order::get_wight() const  {
	return weight;
}
bool Order::get_critical_order()
{
	return this->criticalOrder;
}
void Order::set_critical_order(bool c)
{
	this->criticalOrder = c;
}
void Order::set_ARivval_time(int tim) {
	ArrTime = tim;
}
void Order::set_Service_time(int tim) {
	ServTime= tim;
}

void Order::set_Finish_time(int tim) {
	FinishTime = tim;
}
void Order::set_money(double money) {
	totalMoney = money; 
}
int Order::get_AVT() {
	return ArrTime; 
}
int Order::get_FT() {
	return FinishTime;
}
int Order::get_SVT() {
	return ServTime; 
}
void Order::set_wait_time(int time) {
	waiting_time = time; 
}
int Order::get_WT() {
	return waiting_time; 
}
