#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "..\Generic_DS\LinkedList.h"
#include "..\Generic_DS\PriorityQueue.h"
#include "..\Generic_DS\ComparisonStructs.h"
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
	
	PriorityQueue < Order*, greater_ptrs<Order*> > vipOrders[4];
	Queue<Order*> FrozenOrders[4];
	LinkedList<Order*> NormalOrders[4];

	PriorityQueue < Order*, less_ptrs<Order*> > inServicsOrder[4]; // they are enqued according to Finsih time; 
	Queue<Order*> Delivered_orders[4];
	int NumberOfActiveOrders[4][3]; // i => region, j => type of order, 0 = normal , 1 = frozen , 2 = vip
	int NumberOfMotorcycles[4][3]; // i => region, j => type of order, 0 = normal , 1 = frozen , 2 = vip
	// Motor cycle data structures; 
	PriorityQueue <Motorcycle*, greater_ptrs<Motorcycle*> > M_Normal[4];
	PriorityQueue <Motorcycle*, greater_ptrs<Motorcycle*> > M_Frozen[4];
	PriorityQueue <Motorcycle*, greater_ptrs<Motorcycle*> > M_VIP[4];
	PriorityQueue <Motorcycle *, less_ptrs<Motorcycle*> > in_service_Motorcyles[4]; // thery are enqueud according to in_use_again time
	/// ==>
	
	int timeStep;
	int  GUI_mode; // 0 for interactive and for and 1 for click by click 
	int auto_promo_limit; 
	//
	// TODO: Add More Data Members As Needed
	//

public:
	
	Restaurant();
	~Restaurant();

	void DeleteMotorcycles();

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
	void updateStringsInfo(string& s, string& s1, string& s2, string& s3, string& s4, string& s5, string &s6, int timeStep);
	void updateRestaurantsInfo();
	void go_without_simulation();  // for silent mode Only 
	bool checker(); 
	void output_file(); 
	void set_auto_promo(int x); 
	int get_auto_promo(); 
	void check_auto_promo(int tim); 
	/// ==> 


	//
	// TODO: Add More Member Functions As Needed
	//

};

#endif