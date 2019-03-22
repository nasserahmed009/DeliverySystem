//#include "Drawing.h"
#include "Rest\Restaurant.h"
#include "Generic_DS\PriorityQueue.h"
#include "GUI\GUI.h"
#include <iostream>
void testPQ();
using namespace std;
int main()
{
	
	Restaurant* pRest = new Restaurant;
	testPQ();
	//pRest->RunSimulation();
	
	delete pRest;
	
	return 0;
}


void testPQ()
{
	PriorityQueue<int> pq;
	int x;

	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;

	pq.enqueue(1);
	pq.enqueue(0);
	pq.enqueue(5);
	pq.enqueue(3);
	pq.enqueue(2);
	pq.dequeue(x);
	pq.enqueue(-1);
	pq.dequeue(x);
	pq.dequeue(x);
	pq.dequeue(x);
	pq.dequeue(x);
	pq.dequeue(x);

	if (pq.isEmpty()) cout << "empty" << endl;
	else cout << "not empty" << endl;

	pq.dequeue(x);


}