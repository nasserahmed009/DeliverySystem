#include "ReadInput.h"

ReadInput::ReadInput() :NormalSpeed(0), FrozenSpeed(0), VipSpeed(0), AutoPromotionLimit(0), NumberOfEvents(0)
{
	for (int i = 0; i < 3; i++) {
		motorCyclesInA[i] = 0;
		motorCyclesInB[i] = 0;
		motorCyclesInC[i] = 0;
		motorCyclesInD[i] = 0;
	}
}

bool ReadInput::read(string fileName,Restaurant* R) {
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
				NormalSpeed = stoi(word[0]);
				FrozenSpeed = stoi(word[1]);
				VipSpeed = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(2): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				// first element represents normal motorcycles, second is frozen and third is Vip
				motorCyclesInA[0] = stoi(word[0]);
				motorCyclesInA[1] = stoi(word[1]);
				motorCyclesInA[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(3): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				motorCyclesInB[0] = stoi(word[0]);
				motorCyclesInB[1] = stoi(word[1]);
				motorCyclesInB[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(4): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				motorCyclesInC[0] = stoi(word[0]);
				motorCyclesInC[1] = stoi(word[1]);
				motorCyclesInC[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(5): {
				while (getline(line_ss, token, ' ')) {
					word[j] = token;
					j++;
				}
				motorCyclesInD[0] = stoi(word[0]);
				motorCyclesInD[1] = stoi(word[1]);
				motorCyclesInD[2] = stoi(word[2]);
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
					ArrivalEvent* A=new ArrivalEvent(time, type, ID, dist, money, reg);
					R->AddEvent(A);
				}
						 break;
				case(2): {
					int time = stoi(word[1]);
					int id = stoi(word[2]);
					CancellationEvent* C=new CancellationEvent(time, id);
					R->AddEvent(C);
				}
				break;
				case(3): {
					int time = stoi(word[1]);
					int ID = stoi(word[2]);
					double money = stod(word[3]);
					PromotionEvent *P=new PromotionEvent(time, ID, money);
					R->AddEvent(P);
				}	
				break;
				}
			}
			}
		}
	}
	else {
		cout << "\nFile not found";
		return false;
	}
	// BY MOHY here i called the fuction creat motor cycle from restaurnat to creat them after read their data. (it will not affect any thing in your work shoma XD)
	int x[3];
	x[0] = NormalSpeed; 
	x[1] = FrozenSpeed; 
	x[2] = VipSpeed;
	R->creat_motor_cycles(x, motorCyclesInA, motorCyclesInB, motorCyclesInC , motorCyclesInD);
	infile.close();
	cout << "\nFile loaded successfully\n";
	return true;
}

int ReadInput::getNormalSpeed()
{
	return NormalSpeed;
}

int ReadInput::getFrozenSpeed()
{
	return FrozenSpeed;
}

int ReadInput::getVipSpeed()
{
	return VipSpeed;
}

int ReadInput::getAutoPromotionLimit()
{
	return AutoPromotionLimit;
}

int ReadInput::getNumberOfEvents()
{
	return NumberOfEvents;
}

int ReadInput::getMotorCyclesInRegion(ORD_TYPE O, REGION R)
{
	switch (O) {
		case(TYPE_NRM) :
			if (R == A_REG) {
				return motorCyclesInA[0];
			}
			else if (R == B_REG) {
				return motorCyclesInB[0];
			}
			else if (R == C_REG) {
				return motorCyclesInC[0];
			}
			else {
				return motorCyclesInD[0];
			}
			break;
		case(TYPE_FROZ):
			if (R == A_REG) {
				return motorCyclesInA[1];
			}
			else if (R == B_REG) {
				return motorCyclesInB[1];
			}
			else if (R == C_REG) {
				return motorCyclesInC[1];
			}
			else {
				return motorCyclesInD[1];
			}
			break;
		case(TYPE_VIP):
			if (R == A_REG) {
				return motorCyclesInA[2];
			}
			else if (R == B_REG) {
				return motorCyclesInB[2];
			}
			else if (R == C_REG) {
				return motorCyclesInC[2];
			}
			else {
				return motorCyclesInD[2];
			}
			break;
	}
	return -1;
}



ReadInput::~ReadInput()
{
}
