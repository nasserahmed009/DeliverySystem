#include "Motorcycle.h"


Motorcycle::Motorcycle(int id, ORD_TYPE ot, int sp, REGION reg)
{
	// initializations
	health = 100;
	broken = false;
	timeForRepair = -1;
}
Motorcycle::Motorcycle() {
	// initializations
	health = 100;
	broken = false;
	timeForRepair = -1;
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

int Motorcycle::get_health() const
{
	return health;
}

bool Motorcycle::get_broken() const
{
	return broken;
}

int Motorcycle::get_repair_time() const
{
	return timeForRepair;
}

void Motorcycle::set_health(int health)
{
	if (health <= 100 && health >= 0)
		this->health = health;
}

void Motorcycle::set_broken(bool broken)
{
	this->broken = broken;
}

void Motorcycle::set_repair_time(int repairTime)
{
	this->timeForRepair = repairTime;
}

void Motorcycle::reduceHealthBy(int dh)
{
	this->health -= dh;
	if (health < 0)
		health = 0;
}
void Motorcycle::set_ord_id(int x) {
	ord_id = x; 
}
int Motorcycle::get_ord_id() {
	return ord_id; 
}
int Motorcycle::get_id() {
	return ID;
}