#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include"../Events/CancellationEvent.h"
#include"../Events/PromotionEvent.h"
#include"../InputClass/ReadInput.h"


Restaurant::Restaurant() 
{
	pGUI = NULL;
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Just_A_Demo();

	};

}



//////////////////////////////////  Event handling functions   /////////////////////////////
void Restaurant::AddEvent(Event* pE)	//adds a new event to the queue of events
{
	EventsQueue.enqueue(pE);
}

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current time
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
		delete pGUI;
}



void Restaurant::Simulate()
{
	int timeStep = 0;
	ReadInput pIn;
	pIn.read("input",this);
	for(int i=0;i<4;i++)
		for (int j = 0; j < 3; j++)
		{
			NumberOfActiveOrders[i][j] = 0;
		}

	for (int i = 0; i < 4; i++) {
		REGION region;
		ORD_TYPE type;
		switch (i) {
		case 0:
			region = A_REG;
			break;
		case 1:
			region = B_REG;
			break;
		case 2:
			region = C_REG;
			break;
		case 3:
			region = D_REG;
			break;
		}
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case(0):
				type = TYPE_NRM;
				break;
			case(1):
				type = TYPE_FROZ;
				break;
			case(2):
				type = TYPE_VIP;
			}
			NumberOfMotorcycles[i][j] = pIn.getMotorCyclesInRegion(type,region);
		}
	}

	/* ADD MORE INITIALIZATIONS */

	/* READ INPUT FROM pIn */

	while (timeStep++)
	{

		Event* tempPtr;
		while (EventsQueue.peekFront(tempPtr))
		{
			if (tempPtr->getEventTime() > timeStep)
				break;

			tempPtr->Execute(this);
			
			/* UPDATE INTERFACE TO DISPLAY ACTIVE ORDERS IN EACH REGION */

			if (dynamic_cast<ArrivalEvent*>(tempPtr)) //Update the number of active orders according to region and type
			{
				int region = dynamic_cast<ArrivalEvent*>(tempPtr)->getOrderRegion();
				int type = dynamic_cast<ArrivalEvent*>(tempPtr)->getOrderType();
				NumberOfActiveOrders[region][type]++;
			}
			else if (dynamic_cast<CancellationEvent*>(tempPtr)) {
				int id = tempPtr->getOrderID();
				Order* orderPtr = getOrderById(id);
				int region = orderPtr->GetRegion();
				NumberOfActiveOrders[region][0]--;
			}


			string s = "Region 1 : NormalOrders = " + NumberOfActiveOrders[0][0]; s += " FrozenOrders = " + NumberOfActiveOrders[0][1]; s += " vipOrders = " + NumberOfActiveOrders[0][2];
			s += " NormalMotorcycles = " + NumberOfMotorcycles[0][0]; s += " FrozenMotorcycles = " + NumberOfMotorcycles[0][1]; s += " vipMotorcycles = " + NumberOfMotorcycles[0][2];
			s += "/nRegion 2 : NormalOrders = " + NumberOfActiveOrders[1][0]; s += " FrozenOrders = " + NumberOfActiveOrders[1][1]; s += " vipOrders = " + NumberOfActiveOrders[1][2];
			s += " NormalMotorcycles = " + NumberOfMotorcycles[1][0]; s += " FrozenMotorcycles = " + NumberOfMotorcycles[1][1]; s += " vipMotorcycles = " + NumberOfMotorcycles[1][2];
			s += "/nRegion 3 : NormalOrders = " + NumberOfActiveOrders[2][0]; s += " FrozenOrders = " + NumberOfActiveOrders[2][1]; s += " vipOrders = " + NumberOfActiveOrders[2][2];
			s += " NormalMotorcycles = " + NumberOfMotorcycles[2][0]; s += " FrozenMotorcycles = " + NumberOfMotorcycles[2][1]; s += " vipMotorcycles = " + NumberOfMotorcycles[2][2];
			s += "/nRegion 4 : NormalOrders = " + NumberOfActiveOrders[3][0]; s += " FrozenOrders = " + NumberOfActiveOrders[3][1]; s += " vipOrders = " + NumberOfActiveOrders[3][2];
			s += " NormalMotorcycles = " + NumberOfMotorcycles[3][0]; s += " FrozenMotorcycles = " + NumberOfMotorcycles[3][1]; s += " vipMotorcycles = " + NumberOfMotorcycles[3][2];
			
			pGUI->PrintMessage(s);

			

			Event* junk;
			EventsQueue.dequeue(junk);
		}

		pGUI->waitForClick();
	}



}


////////////////////////////////////////////////////////////////////////////////
/// ==> 
///  DEMO-related functions. Should be removed in phases 1&2

//This is just a demo function for project introductory phase
//It should be removed starting phase 1
void Restaurant::Just_A_Demo()
{
	
	//
	// THIS IS JUST A DEMO FUNCTION
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	
	int EventCnt;	
	Order* pOrd;
	Event* pEv;
	srand(time(NULL));

	pGUI->PrintMessage("Just a Demo. Enter EVENTS Count(next phases should read I/P filename):");
	EventCnt = atoi(pGUI->GetString().c_str());	//get user input as a string then convert to integer

	pGUI->UpdateInterface();

	pGUI->PrintMessage("Generating orders randomly... In next phases, orders should be loaded from a file");
		
	int EvTime = 0;
	
	//Create Random events
	//All generated event will be "ArrivalEvents" for the demo
	for(int i=0; i<EventCnt; i++)
	{
		int O_id = i+1;
		
		//Rendomize order type
		int OType;
		if(i<EventCnt*0.2)	//let 1st 20% of orders be VIP (just for sake of demo)
			OType = TYPE_VIP;
		else if(i<EventCnt*0.5)	
			OType = TYPE_FROZ;	//let next 30% be Frozen
		else
			OType = TYPE_NRM;	//let the rest be normal

		
		int reg = rand()% REG_CNT;	//randomize region


		//Randomize event time
		EvTime += rand()%4;
		pEv = new ArrivalEvent(EvTime,O_id,(ORD_TYPE)OType,(REGION)reg);
		AddEvent(pEv);

	}	

	int CurrentTimeStep = 1;
	//as long as events queue is not empty yet
	while(!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep,timestep,10);	
		pGUI->PrintMessage(timestep);


		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		//The above line may add new orders to the DEMO_Queue

		//Let's draw all arrived orders by passing them to the GUI to draw

		while(DEMO_Queue.dequeue(pOrd))
		{
			pGUI->AddOrderForDrawing(pOrd);
			pGUI->UpdateInterface();
		}
		Sleep(1000);
		CurrentTimeStep++;	//advance timestep
	}


	pGUI->PrintMessage("generation done, click to END program");
	pGUI->waitForClick();

	
}
////////////////

void Restaurant::AddtoDemoQueue(Order *pOrd)
{
	DEMO_Queue.enqueue(pOrd);
}

Order* Restaurant::getDemoOrder()
{
	Order* pOrd;
	DEMO_Queue.dequeue(pOrd);
	return pOrd;

}

void Restaurant::AddVipOrder(Order * o)
{
	vipOrders[o->GetRegion()].enqueue(o);
}

void Restaurant::AddFrozenOrder(Order * o)
{
	FrozenOrders[o->GetRegion()].enqueue(o);
}

void Restaurant::AddNormalOrder(Order * o)
{
	NormalOrders[o->GetRegion()].insert_at_end(o);
}

Order* Restaurant::getOrderById(int i)
{
	for (int i = 0; i < 4; i++)
	{
		Node<Order*>* temp = NormalOrders[i].getHead();
		while (temp) {
			if ((temp->getItem())->GetID() == i) return temp->getItem();
			temp = temp->getNext();
		}
	}
	return NULL;
}

void Restaurant::cancelOrder(Order * o)
{
	NormalOrders[o->GetRegion()].remove(o);
}

void Restaurant::promoteOrder(Order * o)
{
	NormalOrders[o->GetRegion()].remove(o);
	vipOrders[o->GetRegion()].enqueue(o);
}
void Restaurant::creat_motor_cycles(int *speed, int *regA, int *regB, int *regC, int *regD) {
	Queue <Motorcycle> M_NormalA; 
	Queue <Motorcycle> M_FrozenA;
	Queue <Motorcycle> M_VIPA;
	Queue <Motorcycle> M_NormalB;
	Queue <Motorcycle> M_FrozenB;
	Queue <Motorcycle> M_VIPB;
	Queue <Motorcycle> M_NormalC;
	Queue <Motorcycle> M_FrozenC;
	Queue <Motorcycle> M_VIPC;
	Queue <Motorcycle> M_NormalD;
	Queue <Motorcycle> M_FrozenD;
	Queue <Motorcycle> M_VIPD;
	int i;
	int x1 = regA[0] + regB[0] + regC[0] + regD[0];
	int x2 = regA[1] + regB[1] + regC[1] + regD[1];
	int x3 = regA[2] + regB[2] + regC[2] + regD[2];
	Motorcycle *MN = new Motorcycle[x1];
	Motorcycle *MF = new Motorcycle[x2];
	Motorcycle *MV = new Motorcycle[x3];

	// filling the data of type normal 
	for (i = 0; i < regA[0]; i++) {
		MN[i].set_id(i);
		MN[i].set_REG(A_REG);
		MN[i].set_speed(speed[0]);
		MN[i].set_type(TYPE_NRM);
	}
	int temp1 = i+regB[0];
	for (i; i < temp1; i++) {
		MN[i].set_id(i);
		MN[i].set_REG(B_REG);
		MN[i].set_speed(speed[0]);
		MN[i].set_type(TYPE_NRM);
	}
	int temp2 = i+regC[0]; 
	for (i ; i < temp2; i++) {
		MN[i].set_id(i);
		MN[i].set_REG(C_REG);
		MN[i].set_speed(speed[0]);
		MN[i].set_type(TYPE_NRM);
	}
	int temp3 = i+regD[0];
	for (i ; i < temp3; i++) {
		MN[i].set_id(i);
		MN[i].set_REG(D_REG);
		MN[i].set_speed(speed[0]);
		MN[i].set_type(TYPE_NRM);
	}
	// enqueing the normal order each in region 
	int j;
	for (j= 0; j < regA[0]; j++) {
		M_NormalA.enqueue(MN[j]);
	}
	for (j; j  < regB[0]; j++) {
		M_NormalB.enqueue(MN[j]);
	}
	for (j; j < regC[0]; j++) {
		M_NormalC.enqueue(MN[j]);
	}
	for (j; j< regD[0]; j++) {
		M_NormalD.enqueue(MN[j]);
	}
	// filling the data of motorcycles of type frozen
	int k = i; 
	for (i = 0; i < regA[1]; i++) {
		MF[i].set_id(k);
		MF[i].set_REG(A_REG);
		MF[i].set_speed(speed[1]);
		MF[i].set_type(TYPE_FROZ);
		k++;
	}
	temp1=  i+regB[1] ;
	for (i; i < temp1; i++) {
		MF[i].set_id(k);
		MF[i].set_REG(B_REG);
		MF[i].set_speed(speed[1]);
		MF[i].set_type(TYPE_FROZ);
		k++;
	}
	temp2 = i + regC[1];
	for (i; i < temp2; i++) {
		MF[i].set_id(k);
		MF[i].set_REG(C_REG);
		MF[i].set_speed(speed[1]);
		MF[i].set_type(TYPE_FROZ);
		k++;
	}
	temp3 = i + regD[1];
	for (i; i < temp3; i++) {
		MF[i].set_id(k);
		MF[i].set_REG(D_REG);
		MF[i].set_speed(speed[1]);
		MF[i].set_type(TYPE_FROZ);
		k++;
	}
	// enqueing The frozen order each in specific zone 
	for (j = 0; j < regA[1]; j++) {
		M_FrozenA.enqueue(MF[j]);
	}
	for (j; j < regB[1]; j++) {
		M_FrozenB.enqueue(MF[j]);
	}
	for (j; j < regC[1]; j++) {
		M_FrozenC.enqueue(MF[j]);
	}
	for (j; j < regD[1]; j++) {
		M_FrozenD.enqueue(MF[j]);
	}
	// filling the data of type VIP 
	for (i = 0; i < regA[2]; i++) {
		MV[i].set_id(k);
		MV[i].set_REG(A_REG);
		MV[i].set_speed(speed[2]);
		MV[i].set_type(TYPE_VIP);
		k++;
	}
	temp1 = i + regB[2];
	for (i; i < temp1; i++) {
		MV[i].set_id(k);
		MV[i].set_REG(B_REG);
		MV[i].set_speed(speed[2]);
		MV[i].set_type(TYPE_VIP);
		k++;
	}
	temp2 = i + regC[2];
	for (i; i < temp2; i++) {
		MV[i].set_id(k);
		MV[i].set_REG(C_REG);
		MV[i].set_speed(speed[2]);
		MV[i].set_type(TYPE_VIP);
		k++;
	}
	temp3 = i + regD[2];
	for (i; i < temp3; i++) {
		MV[i].set_id(k);
		MV[i].set_REG(D_REG);
		MV[i].set_speed(speed[2]);
		MV[i].set_type(TYPE_VIP);
		k++;
	}
	// enqueing The VIP orders each in specific zone 
	for (j = 0; j < regA[2]; j++) {
		M_VIPA.enqueue(MV[j]);
	}
	for (j; j < regB[2]; j++) {
		M_VIPB.enqueue(MV[j]);
	}
	for (j; j < regC[2]; j++) {
		M_VIPC.enqueue(MV[j]);
	}
	for (j; j < regD[2]; j++) {
		M_VIPD.enqueue(MV[j]);
	}

}



/// ==> end of DEMO-related function