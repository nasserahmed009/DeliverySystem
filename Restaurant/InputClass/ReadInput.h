#pragma once
#include"../Generic_DS/Queue.h"
#include"../Rest/Restaurant.h"
#include "../Events/ArrivalEvent.h"
#include "../Events/CancellationEvent.h"
#include "../Events/PromotionEvent.h"
#include <fstream>
#include<iostream>
#include "../Defs.h"
#include<string>
#include<sstream>
#include"../GUI/GUI.h"
using namespace std;

class ReadInput
{
private:
	int NormalSpeed, FrozenSpeed, VipSpeed, AutoPromotionLimit,NumberOfEvents;
	int motorCyclesInA[3];
	int motorCyclesInB[3];
	int motorCyclesInC[3];
	int motorCyclesInD[3];

public:
	ReadInput();
	bool read(Restaurant*,GUI*& pGUI);
	int getNormalSpeed();
	int getFrozenSpeed();
	int getVipSpeed();
	int getAutoPromotionLimit();
	int getNumberOfEvents();
	int getMotorCyclesInRegion(ORD_TYPE,REGION);
	~ReadInput();
};

