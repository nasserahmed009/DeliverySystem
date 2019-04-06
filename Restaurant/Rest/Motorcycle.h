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

public:
	Motorcycle(int id, ORD_TYPE ot, int sp, REGION reg);
	virtual ~Motorcycle();
	Motorcycle();
	void set_id(int id);
	void set_type(ORD_TYPE ot);
	void set_speed(int sp);
	void  set_REG(REGION reg); 
};

#endif