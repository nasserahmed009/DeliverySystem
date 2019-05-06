#ifndef __MOTORCYCLE_H_
#define __MOTORCYCLE_H_


#include "..\Defs.h"

#pragma once
class Motorcycle 
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding motorcycle type 
	int speed;		//meters it can move in one clock tick (in one timestep)
	REGION	region;	//region of the motorcycle
	STATUS	status;	//idle or in-service
	int again_use; // time from which the motor cycle is available again to be used 
	
	//Bonus: damaged motorcycles
	int health;
	bool broken;
	int timeForRepair;

public:
	Motorcycle(int id, ORD_TYPE ot, int sp, REGION reg);
	virtual ~Motorcycle();
	Motorcycle();
	void set_id(int id);
	void set_type(ORD_TYPE ot);
	void set_speed(int sp);
	int get_speed(); 
	void  set_REG(REGION reg); 
	void set_status(STATUS S);
	void set_again_use(int tim); 
	int get_again_use(); 
	STATUS get_status(); 
	int GetType() const;
	bool operator > (const Motorcycle &O) const;
	bool operator < (const Motorcycle  &O) const;

	//Bonus: damaged motorcycles
	int get_health() const;
	bool get_broken() const;
	int get_repair_time() const;
	
	void set_health(int health);
	void set_broken(bool broken);
	void set_repair_time(int repairTime);

	void reduceHealthBy(int dh);
};

#endif