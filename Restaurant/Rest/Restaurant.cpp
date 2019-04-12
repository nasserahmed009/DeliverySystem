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
	//Simulate();

	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;
	case MODE_DEMO:
		Simulate();
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
	while (EventsQueue.peekFront(pE))	//as long as there are more events
	{
		if (pE->getEventTime() > CurrentTimeStep)	//no more events at current time
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
	ReadInput pIn;
	string name;
	pIn.read(this,pGUI);
	timeStep = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
		{
			NumberOfActiveOrders[i][j] = 0;
		}

	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 3; j++) 
			NumberOfMotorcycles[i][j] = pIn.getMotorCyclesInRegion(static_cast<ORD_TYPE>(j), static_cast<REGION>(i));
	
	

	/* ADD MORE INITIALIZATIONS */

	/* READ INPUT FROM pIn */
	
	while (!EventsQueue.isEmpty())
	{
		Event* tempPtr;

		//remove one order from each type each timeStep
		Order* pOrd;
		for (int i = 0; i < 4; i++) {
			if (vipOrders[i].dequeue(pOrd))
			{
				NumberOfActiveOrders[i][2]--;
				delete pOrd;
			}
			if (FrozenOrders[i].dequeue(pOrd))
			{
				NumberOfActiveOrders[i][1]--;
				delete pOrd;
			}
			if (NormalOrders[i].removeFront(pOrd))
			{
				NumberOfActiveOrders[i][0]--;
				delete pOrd;
			}
		}


		//check if there is more than one event at the same timeStep
		while (EventsQueue.peekFront(tempPtr))
		{
			if (tempPtr->getEventTime() > timeStep) break;

			tempPtr->Execute(this);

			Event* junk;
			EventsQueue.dequeue(junk);
		}
		
		pGUI->ResetDrawingList();
		
		for (int i = 0; i < 4; i++) {
			

			PriorityQueue<Order*> tempVip = vipOrders[i];
			while (tempVip.dequeue(pOrd)) {
				pGUI->AddOrderForDrawing(pOrd);
			}
			Queue<Order*> tempFrozen = FrozenOrders[i];
			while (tempFrozen.dequeue(pOrd)) {
				pGUI->AddOrderForDrawing(pOrd);
			}

			Node<Order*>* tempNormal = NormalOrders[i].getHead();
			while (tempNormal) {
				pOrd = tempNormal ->getItem();
				pGUI->AddOrderForDrawing(pOrd);
				tempNormal = tempNormal->getNext();
			}
			
		}
		updateRestaurantsInfo();
		pGUI->UpdateInterface();
		pGUI->waitForClick();
		timeStep++;
	}
	pGUI->PrintMessage("Simulation Finished Thanks for watching");
	//cout << "Ended successfully" << endl;
}


/* STILL NEED TO BE ADDED THE IN-SERVICE LIST FOR SERVICED ORDERS*/
/*INPUT FUNCTION SHOULD READ FROM EL MAIN NOT FROM SIMULATION FUNCTION*/
/* NEED TO DISPLAY NUMBER OF EVERY THING ON THE DISPLAY ON SEPARATE LINE*/
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
	for (int i = 0; i < EventCnt; i++)
	{
		int O_id = i + 1;

		//Rendomize order type
		int OType;
		if (i < EventCnt*0.2)	//let 1st 20% of orders be VIP (just for sake of demo)
			OType = TYPE_VIP;
		else if (i < EventCnt*0.5)
			OType = TYPE_FROZ;	//let next 30% be Frozen
		else
			OType = TYPE_NRM;	//let the rest be normal


		int reg = rand() % REG_CNT;	//randomize region


		//Randomize event time
		EvTime += rand() % 4;
		pEv = new ArrivalEvent(EvTime, O_id, (ORD_TYPE)OType, (REGION)reg);
		AddEvent(pEv);

	}

	int CurrentTimeStep = 1;
	//as long as events queue is not empty yet
	while (!EventsQueue.isEmpty())
	{
		//print current timestep
		char timestep[10];
		itoa(CurrentTimeStep, timestep, 10);
		pGUI->PrintMessage(timestep);


		ExecuteEvents(CurrentTimeStep);	//execute all events at current time step
		//The above line may add new orders to the DEMO_Queue

		//Let's draw all arrived orders by passing them to the GUI to draw

		while (DEMO_Queue.dequeue(pOrd))
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
	NumberOfActiveOrders[o->GetRegion()][o->GetType()]++;
	vipOrders[o->GetRegion()].enqueue(o);
}

void Restaurant::AddFrozenOrder(Order * o)
{
	NumberOfActiveOrders[o->GetRegion()][o->GetType()]++;
	FrozenOrders[o->GetRegion()].enqueue(o);
}

void Restaurant::AddNormalOrder(Order * o)
{
	NumberOfActiveOrders[o->GetRegion()][o->GetType()]++;
	NormalOrders[o->GetRegion()].insert_at_end(o);
}

Order* Restaurant::getOrderById(int orderID)
{
	for (int i = 0; i < 4; i++)
	{
		Node<Order*>* temp = NormalOrders[i].getHead();
		while (temp) {
			if ((temp->getItem())->GetID() == orderID) return temp->getItem();
			temp = temp->getNext();
		}
	}
	return NULL;
}

void Restaurant::cancelOrder(Order * o)
{
	if (o == NULL || ( o->GetType() != 0)) return;
	NumberOfActiveOrders[o->GetRegion()][0]--;
	NormalOrders[o->GetRegion()].remove(o);
	delete o;
}

void Restaurant::promoteOrder(Order * o)
{
	if (o == NULL) return;
	o->setType(TYPE_VIP);
	vipOrders[o->GetRegion()].enqueue(o);
	NormalOrders[o->GetRegion()].remove(o);
	NumberOfActiveOrders[o->GetRegion()][0]--;
	NumberOfActiveOrders[o->GetRegion()][2]++;
}
void Restaurant::creat_motor_cycles(int *speed, int *regA, int *regB, int *regC, int *regD) {
	int i = 0;
	for (i = 0; i < regA[0]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(i);  M->set_REG(A_REG);  M->set_speed(speed[0]);  M->set_type(TYPE_NRM); M_NormalA.enqueue(M);
	}
	int k = i;
	for (i = 0; i < regB[0]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(B_REG);  M->set_speed(speed[0]);  M->set_type(TYPE_NRM); M_NormalB.enqueue(M); k++;
	}
	for (i = 0; i < regC[0]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(C_REG);  M->set_speed(speed[0]);  M->set_type(TYPE_NRM); M_NormalC.enqueue(M);  k++;
	}
	for (i = 0; i < regD[0]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(D_REG);  M->set_speed(speed[0]);  M->set_type(TYPE_NRM); M_NormalD.enqueue(M);  k++;
	}
	for (i = 0; i < regA[1]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(A_REG);  M->set_speed(speed[1]);  M->set_type(TYPE_FROZ); M_FrozenA.enqueue(M);   k++;
	}
	for (i = 0; i < regB[1]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(B_REG);  M->set_speed(speed[1]);  M->set_type(TYPE_FROZ); M_FrozenB.enqueue(M);   k++;
	}
	for (i = 0; i < regC[1]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(C_REG);  M->set_speed(speed[1]);  M->set_type(TYPE_FROZ); M_FrozenC.enqueue(M);   k++;
	}
	for (i = 0; i < regD[1]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(D_REG);  M->set_speed(speed[1]);  M->set_type(TYPE_FROZ); M_FrozenD.enqueue(M);   k++;
	}
	for (i = 0; i < regA[2]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(i);  M->set_REG(A_REG);  M->set_speed(speed[2]);  M->set_type(TYPE_VIP); M_VIPA.enqueue(M);   k++;
	}
	for (i = 0; i < regB[2]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(B_REG);  M->set_speed(speed[2]);  M->set_type(TYPE_VIP); M_VIPB.enqueue(M);   k++;
	}
	for (i = 0; i < regC[2]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(C_REG);  M->set_speed(speed[2]);  M->set_type(TYPE_VIP); M_VIPC.enqueue(M);   k++;
	}
	for (i = 0; i < regD[2]; i++) {
		Motorcycle * M = new Motorcycle;
		M->set_id(k);  M->set_REG(D_REG);  M->set_speed(speed[2]);  M->set_type(TYPE_VIP); M_VIPD.enqueue(M);   k++;
	}

}

void Restaurant::updateRestaurantsInfo()
{
	string s, s1, s2, s3, s4, s5, s6;

	updateStringsInfo(s, s1, s2, s3, s4, s5, s6, timeStep);
	pGUI->print_msg_multi(s, s1, s2, s3, s4, s5, s6);
}


void Restaurant::updateStringsInfo(string& s,string & s1, string & s2, string & s3, string & s4, string & s5,string &s6,int timeStep)
{
	s = "                                   Orders                Motorcycles";
	s1 = "                                   N   F   V                    N   F   V";

	s2 = "Region A                    ";
	s2 += to_string(NumberOfActiveOrders[0][0]);
	s2 += "   " + to_string(NumberOfActiveOrders[0][1]);
	s2 += "   " + to_string(NumberOfActiveOrders[0][2]);
	s2 += "                     " + to_string(NumberOfMotorcycles[0][0]);
	s2 += "   " + to_string(NumberOfMotorcycles[0][1]);
	s2 += "   " + to_string(NumberOfMotorcycles[0][2]);

	s3 = "Region B                   ";
	s3 += to_string(NumberOfActiveOrders[1][0]);
	s3 += "   " + to_string(NumberOfActiveOrders[1][1]);
	s3 += "   " + to_string(NumberOfActiveOrders[1][2]);
	s3 += "                     " + to_string(NumberOfMotorcycles[1][0]);
	s3 += "   " + to_string(NumberOfMotorcycles[1][1]);
	s3 += "   " + to_string(NumberOfMotorcycles[1][2]);

	s4 = "Region C                   " + to_string(NumberOfActiveOrders[2][0]);
	s4 += "   " + to_string(NumberOfActiveOrders[2][1]);
	s4 += "   " + to_string(NumberOfActiveOrders[2][2]);
	s4 += "                     " + to_string(NumberOfMotorcycles[2][0]);
	s4 += "   " + to_string(NumberOfMotorcycles[2][1]);
	s4 += "   " + to_string(NumberOfMotorcycles[2][2]);

	s5 = "Region D                   " + to_string(NumberOfActiveOrders[3][0]);
	s5 += "   " + to_string(NumberOfActiveOrders[3][1]);
	s5 += "   " + to_string(NumberOfActiveOrders[3][2]);
	s5 += "                     " + to_string(NumberOfMotorcycles[3][0]);
	s5 += "   " + to_string(NumberOfMotorcycles[3][1]);
	s5 += "   " + to_string(NumberOfMotorcycles[3][2]);
	
	s6 = "Timestep: " + to_string(timeStep);
}



/// ==> end of DEMO-related function