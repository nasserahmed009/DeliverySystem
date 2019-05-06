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
	PriorityQueue<Order*, less_ptrs<Order*> >pq;
	//int x;
	Order* O = new Order(1, TYPE_VIP, A_REG,1);
	O->set_wieght(100);
	Order* O2 = new Order(2, TYPE_VIP, A_REG,0);
	O2->set_wieght(200);
	Order *O3 = new Order(3, TYPE_VIP, A_REG,1);
	O3->set_wieght(150);
	pq.enqueue(O3);
	pq.enqueue(O2);
	pq.enqueue(O);
	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;

	Order* pord = new Order(4, TYPE_VIP, A_REG,0);
	while (!pq.isEmpty()) {
		pq.dequeue(pord);
		cout << pord->get_wight() << "         ";
	}
	cout << endl;
	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;
}

void testMotorcyclePQ()
{
	PriorityQueue<Motorcycle*, greater_moto_ptrs<Motorcycle*>> PQ;
	Motorcycle* moto1 = new Motorcycle;
	moto1->set_speed(500);
	moto1->set_broken(1);
	Motorcycle* moto2 = new Motorcycle;
	moto2->set_speed(400);
	moto2->set_broken(0);
	Motorcycle* moto3 = new Motorcycle;
	moto3->set_speed(300);
	moto3->set_broken(0);
	Motorcycle* moto4 = new Motorcycle;
	moto4->set_speed(300);
	moto4->set_broken(1);
	PQ.enqueue(moto1);
	PQ.enqueue(moto2);
	PQ.enqueue(moto3);
	PQ.enqueue(moto4);

}

int main()
{
	
	// here you should creat instance of inputfile and read data from it 
	Restaurant* pRest = new Restaurant;
	pRest->RunSimulation();
	//pRest->RunSimulation(); no Need to be excuted in phase 1
	
	delete pRest;
	
	//testPQ(); 

	//system("pause");

	
	return 0;
}
 