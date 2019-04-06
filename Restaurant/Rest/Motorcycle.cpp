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