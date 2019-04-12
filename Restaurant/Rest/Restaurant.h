#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Generic_DS\LinkedList.h"
#include "..\Generic_DS\PriorityQueue.h"
#include "Motorcycle.h"
#include "Order.h"

// it is the maestro of the project
class Restaurant  
{	
private:
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	
	/// ==> 
	//	DEMO-related members. Should be removed in phases 1&2
	Queue<Order*> DEMO_Queue;	//Important: This is just for demo
	
	PriorityQueue<Order*> vipOrders[4];
	Queue<Order*> FrozenOrders[4];
	LinkedList<Order*> NormalOrders[4];

	PriorityQueue<Order*> inServicsOrder[4];
	int NumberOfActiveOrders[4][3]; // i => region, j => type of order, 0 = normal , 1 = frozen , 2 = vip
	int NumberOfMotorcycles[4][3]; // i => region, j => type of order, 0 = normal , 1 = frozen , 2 = vip
	// Motor cycle data structures; 
	PriorityQueue <Motorcycle *> M_NormalA;
	PriorityQueue <Motorcycle*> M_FrozenA;
	PriorityQueue <Motorcycle*> M_VIPA;
	PriorityQueue <Motorcycle*> M_NormalB;
	PriorityQueue <Motorcycle*> M_FrozenB;
	PriorityQueue <Motorcycle*> M_VIPB;
	PriorityQueue <Motorcycle*> M_NormalC;
	PriorityQueue <Motorcycle*> M_FrozenC;
	PriorityQueue <Motorcycle*> M_VIPC;
	PriorityQueue <Motorcycle*> M_NormalD;
	PriorityQueue <Motorcycle*> M_FrozenD;
	PriorityQueue <Motorcycle *> M_VIPD;
	PriorityQueue <Motorcycle *> in_service_Motorcyles[4]; 
	/// ==>
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Restaurant();
	~Restaurant();

	void AddEvent(Event* pE);	//adds a new event to the queue of events
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();

	/// ==> 
	///  DEMO-related functions. Should be removed in phases 1&2
	void Just_A_Demo();	//just to show a demo and should be removed in phase1 1 & 2
	void Simulate();
	void AddtoDemoQueue(Order* po);	//adds an order to the demo queue
	Order* getDemoOrder();			//return the front order from demo queue

	void AddVipOrder(Order* o);
	void AddFrozenOrder(Order* o);
	void AddNormalOrder(Order* o);

	Order* getOrderById(int orderID);
	void cancelOrder(Order* o);
	void promoteOrder(Order* o);
	void creat_motor_cycles(int *speed, int *regA, int *regB, int *regC, int *regD); 
	void updateRestaurantsInfo(string& s,string& s1, string& s2, string& s3, string& s4,string& s5);
	/// ==> 


	//
	// TODO: Add More Member Functions As Needed
	//

};

#endif