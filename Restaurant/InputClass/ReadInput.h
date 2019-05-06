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
	int AutoPromotionLimit,NumberOfEvents,timeToRepair;
	int motorCyclesInA[3];
	int motorCyclesInB[3];
	int motorCyclesInC[3];
	int motorCyclesInD[3];
	int* NRMspeedA, *NRMspeedB,*NRMspeedC,*NRMspeedD;
	int* FRZspeedA, *FRZspeedB, *FRZspeedC, *FRZspeedD;
	int* VIPspeedA, *VIPspeedB, *VIPspeedC, *VIPspeedD;

public:
	ReadInput();
	bool read(Restaurant*,GUI*& pGUI);
	bool modifiedRead(Restaurant*, GUI*& pGUI);
	int getAutoPromotionLimit();
	int getTimeToRepair();
	int getNumberOfEvents();
	int getMotorCyclesInRegion(ORD_TYPE,REGION);
	~ReadInput();
};

