//#include "Drawing.h"
#include "Rest\Restaurant.h"
#include "Generic_DS\PriorityQueue.h"
#include "Rest\Restaurant.h"
#include "GUI\GUI.h"
#include"Events/ArrivalEvent.h"
#include"Events/CancellationEvent.h"
#include"Events/PromotionEvent.h"
#include<iostream>
#include <fstream>
#include<string>
#include<sstream>
using namespace std;

bool ReadInput(string);
int speeds[3], NumberInRegionA[3], NumberInRegionB[3], NumberInRegionC[3], NumberInRegionD[3], AutoPromotionLimit, NumberOfEvents;

int main()
{
	Restaurant RestaurantA, RestaurantB, RestaurantC, RestaurantD;
	ReadInput("input");
	Restaurant* pRest = new Restaurant;
	pRest->RunSimulation();

	delete pRest;
	return 0;
}


bool ReadInput(string fileName) {
	ifstream infile;
	infile.open(fileName + ".txt");
	int j;
	string token, word[10];
	stringstream line_ss;
	int lineNumber = 1;
	if (infile.is_open()) {
		while (!infile.eof()) {
			string line;
			getline(infile, line);
			stringstream line_ss(line);
			j = 0;
			switch (lineNumber) {
			case(1): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				speeds[0] = stoi(word[0]);
				speeds[1] = stoi(word[1]);
				speeds[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(2): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				//this should add motor cycles to the chosen data structure immediately but i assign the number to a variable until we implement the DS for motorcycles 
				NumberInRegionA[0] = stoi(word[0]);
				NumberInRegionA[1] = stoi(word[1]);
				NumberInRegionA[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(3): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				//this should add motor cycles to the chosen data structure immediately but i assign the number to a variable until we implement the DS for motorcycles 
				NumberInRegionB[0] = stoi(word[0]);
				NumberInRegionB[1] = stoi(word[1]);
				NumberInRegionB[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(4): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				//this should add motor cycles to the chosen data structure immediately but i assign the number to a variable until we implement the DS for motorcycles 
				NumberInRegionC[0] = stoi(word[0]);
				NumberInRegionC[1] = stoi(word[1]);
				NumberInRegionC[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(5): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				//this should add motor cycles to the chosen data structure immediately but i assign the number to a variable until we implement the DS for motorcycles 
				NumberInRegionD[0] = stoi(word[0]);
				NumberInRegionD[1] = stoi(word[1]);
				NumberInRegionD[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;

			case(6): {
				line_ss >> AutoPromotionLimit;
				lineNumber++;
			}
					 break;
			case(7): {
				line_ss >> NumberOfEvents;
				lineNumber++;
			}
					 break;
			default: {
				int i = 0;
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
					if (token == "R")
						i = 1; //Arrival Event
					else if (token == "X")
						i = 2; //Cancellation Event
					else if (token == "P")
						i = 3; //promotion Event
				}
				switch (i) {
				case(1): {
					int time = stoi(word[1]);
					ORD_TYPE type;
					if (word[2] == "N")
						type = TYPE_NRM;
					else if (word[2] == "F")
						type = TYPE_FROZ;
					else
						type = TYPE_VIP;

					int ID = stoi(word[3]);
					int dist = stoi(word[4]);
					double money = stod(word[5]);
					REGION reg;
					if (word[6] == "A")
						reg = A_REG;
					else if (word[6] == "B")
						reg = B_REG;
					else if (word[6] == "C")
						reg = C_REG;
					else
						reg = D_REG;
					//ArrivalEvent A1(time, type, ID, dist, money, reg);
				}
						 break;
				case(2): {
					int time = stoi(word[1]);
					int id = stoi(word[2]);
					//CancellationEvent C1(time, id);
				}
						 break;
				case(3): {
					int time = stoi(word[1]);
					int ID = stoi(word[2]);
					double money = stod(word[3]);
					//PromotionEvent p1(time, ID, money);
				}
						 break;
				}
			}
			}
		}
	}
	else {
		cout << "File not found";
		return false;
	}
	infile.close();
	cout << "File loaded successfully";
	return true;
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