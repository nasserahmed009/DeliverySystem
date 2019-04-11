//#include "Drawing.h"
#include "Rest\Restaurant.h"
#include "Generic_DS\PriorityQueue.h"
#include "Rest\Restaurant.h"
#include"InputClass/ReadInput.h"
#include "GUI\GUI.h"
#include"Events/ArrivalEvent.h"
#include"Events/CancellationEvent.h"
#include"Events/PromotionEvent.h"
#include<iostream>
using namespace std;
void testPQ()
{
	PriorityQueue<Order> pq;
	//int x;
	Order O(1, TYPE_VIP, A_REG);
	O.set_wieght(100);
	Order O2(2, TYPE_VIP, A_REG);
	O2.set_wieght(200);
	Order O3(3, TYPE_VIP, A_REG);
	O3.set_wieght(150);
	pq.enqueue(O);
	pq.enqueue(O3);
	pq.enqueue(O2);
	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;

	Order pord(4, TYPE_VIP, A_REG);
	while (!pq.isEmpty()) {
		pq.dequeue(pord);
		cout << pord.get_wight() << "         ";
	}
	cout << endl;
	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;
}

int main()
{
	
	// here you should creat instance of inputfile and read data from it 
	Restaurant* pRest = new Restaurant;
	pRest->RunSimulation();
	//pRest->RunSimulation(); no Need to be excuted in phase 1
	
	delete pRest;
	
	//testPQ(); 

	system("pause");
	
	return 0;
}
 