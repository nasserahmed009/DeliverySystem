#include "Motorcycle.h"


Motorcycle::Motorcycle(int id, ORD_TYPE ot, int sp, REGION reg)
{
}
Motorcycle::Motorcycle() {

}

Motorcycle::~Motorcycle()
{
}
void Motorcycle::set_id(int id) {
	ID = id; 
}
void Motorcycle::set_speed(int sp) {
	speed = sp;
}
void Motorcycle::set_REG(REGION reg) {
	region = reg;
}
void Motorcycle::set_type(ORD_TYPE ot) {
	type = ot;
}
void Motorcycle::set_status(STATUS S) {
	status = S; 
}
STATUS Motorcycle::get_status() {
	return status; 
}
int Motorcycle::get_speed() {
	return speed; 
}
void Motorcycle::set_again_use(int time) {
	again_use = time; 
}
int Motorcycle::get_again_use() {
	return again_use; 
}
bool Motorcycle:: operator <  (const Motorcycle  &M) const {
	if (again_use < M.again_use) {
		return true; 
}
	else {
		return false; 
	}
}
bool Motorcycle:: operator > (const Motorcycle  &M) const {
	if (speed > M.speed) {
		return true;
	}
	else {
		return false;
	}
}
int Motorcycle::GetType() const
{
	return type;
}