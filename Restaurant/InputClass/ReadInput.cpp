#include "ReadInput.h"

ReadInput::ReadInput() :AutoPromotionLimit(0), NumberOfEvents(0)
{
	for (int i = 0; i < 3; i++) {
		motorCyclesInA[i] = 0;
		motorCyclesInB[i] = 0;
		motorCyclesInC[i] = 0;
		motorCyclesInD[i] = 0;
	}
}

/*bool ReadInput::read(Restaurant* R, GUI*& pGUI) {
	ifstream infile;
	string name;
	pGUI->PrintMessage("Enter the name of the input file");
	name=pGUI->GetString();
	infile.open(name + ".txt");
	while (!infile.is_open()) {
		pGUI->PrintMessage("File not found, please write a valid input file name");
		name=pGUI->GetString();
		infile.open(name + ".txt");
	}
	int j;
	string word[10];
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
				while (getline(line_ss, word[j], ' ')) {
					j++;
				}
				NormalSpeed = stoi(word[0]);
				FrozenSpeed = stoi(word[1]);
				VipSpeed = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(2): {
				while (getline(line_ss, word[j], ' ')) {
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
				while (getline(line_ss, word[j], ' ')) {
					j++;
				}
				motorCyclesInB[0] = stoi(word[0]);
				motorCyclesInB[1] = stoi(word[1]);
				motorCyclesInB[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(4): {
				while (getline(line_ss, word[j], ' ')) {
					j++;
				}
				motorCyclesInC[0] = stoi(word[0]);
				motorCyclesInC[1] = stoi(word[1]);
				motorCyclesInC[2] = stoi(word[2]);
				lineNumber++;
			}
					 break;
			case(5): {
				while (getline(line_ss, word[j], ' ')) {
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
				while (getline(line_ss, word[j], ' ')) {
					if (word[j] == "R")
						i = 1; //Arrival Event
					else if (word[j] == "X")
						i = 2; //Cancellation Event
					else if (word[j]== "P")
						i = 3; //promotion Event
					j++;
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
	// BY MOHY here i called the fuction creat motor cycle from restaurnat to creat them after read their data. (it will not affect any thing in your work shoma XD)
	int x[3];
	x[0] = NormalSpeed; 
	x[1] = FrozenSpeed; 
	x[2] = VipSpeed;
	R->creat_motor_cycles(x, motorCyclesInA, motorCyclesInB, motorCyclesInC , motorCyclesInD);
	R->set_auto_promo(AutoPromotionLimit);
	infile.close();
	return true;
}*/

bool ReadInput::modifiedRead(Restaurant* R, GUI*& pGUI)
{
		ifstream infile;
		string name;
		pGUI->PrintMessage("Enter the name of the input file");
		name = pGUI->GetString();
		infile.open(name + ".txt");
		while (!infile.is_open()) {
			pGUI->PrintMessage("File not found, please write a valid input file name");
			name = pGUI->GetString();
			infile.open(name + ".txt");
		}
		int j;
		string word[100];
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
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					// first element represents normal motorcycles, second is frozen and third is Vip
					motorCyclesInA[0] = stoi(word[0]);
					motorCyclesInA[1] = stoi(word[1]);
					motorCyclesInA[2] = stoi(word[2]);
					lineNumber++;
				}
				break;
				case(2): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					motorCyclesInB[0] = stoi(word[0]);
					motorCyclesInB[1] = stoi(word[1]);
					motorCyclesInB[2] = stoi(word[2]);
					lineNumber++;
				}
				break;
				case(3): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					motorCyclesInC[0] = stoi(word[0]);
					motorCyclesInC[1] = stoi(word[1]);
					motorCyclesInC[2] = stoi(word[2]);
					lineNumber++;
				}
				break;
				case(4): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					motorCyclesInD[0] = stoi(word[0]);
					motorCyclesInD[1] = stoi(word[1]);
					motorCyclesInD[2] = stoi(word[2]);
					lineNumber++;
				}
				 break;

				case(5): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					NRMspeedA = new int[motorCyclesInA[0]];
					j = 0;
					for (int i = 0; i < motorCyclesInA[0]; i++) {
						NRMspeedA[i] =stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(6): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					FRZspeedA = new int[motorCyclesInA[1]];
					j = 0;
					for (int i = 0; i < motorCyclesInA[1]; i++) {
						FRZspeedA[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(7): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					VIPspeedA = new int[motorCyclesInA[2]];
					j = 0;
					for (int i = 0; i < motorCyclesInA[2]; i++) {
						VIPspeedA[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(8): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					NRMspeedB = new int[motorCyclesInB[0]];
					j = 0;
					for (int i = 0; i < motorCyclesInB[0]; i++) {
						NRMspeedB[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(9): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					FRZspeedB = new int[motorCyclesInB[1]];
					j = 0;
					for (int i = 0; i < motorCyclesInB[1]; i++) {
						FRZspeedB[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(10): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					VIPspeedB = new int[motorCyclesInB[2]];
					j = 0;
					for (int i = 0; i < motorCyclesInB[2]; i++) {
						VIPspeedB[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(11): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					NRMspeedC = new int[motorCyclesInC[0]];
					j = 0;
					for (int i = 0; i < motorCyclesInC[0]; i++) {
						NRMspeedC[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(12): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					FRZspeedC = new int[motorCyclesInC[1]];
					j = 0;
					for (int i = 0; i < motorCyclesInC[1]; i++) {
						FRZspeedC[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(13): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					VIPspeedC = new int[motorCyclesInC[2]];
					j = 0;
					for (int i = 0; i < motorCyclesInC[2]; i++) {
						VIPspeedC[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(14): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					NRMspeedD = new int[motorCyclesInD[0]];
					j = 0;
					for (int i = 0; i < motorCyclesInD[0]; i++) {
						NRMspeedD[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(15): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					FRZspeedD = new int[motorCyclesInD[1]];
					j = 0;
					for (int i = 0; i < motorCyclesInD[1]; i++) {
						FRZspeedD[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;
				case(16): {
					while (getline(line_ss, word[j], ' ')) {
						j++;
					}
					VIPspeedD = new int[motorCyclesInD[2]];
					j = 0;
					for (int i = 0; i < motorCyclesInD[2]; i++) {
						VIPspeedD[i] = stoi(word[j]);
						j++;
					}
					lineNumber++;
				}
				break;

				case(17): {
					line_ss >> AutoPromotionLimit;
					lineNumber++;
				}
				break;
				case(18): {
					line_ss >> timeToRepair;
					lineNumber++;
				}
				break;
				case(19): {
					line_ss >> NumberOfEvents;
					lineNumber++;
				}
				break;
				default: {
					int i = 0;
					while (getline(line_ss, word[j], ' ')) {
						if (word[j] == "R")
							i = 1; //Arrival Event
						else if (word[j] == "X")
							i = 2; //Cancellation Event
						else if (word[j] == "P")
							i = 3; //promotion Event
						j++;
					}
					switch (i) {
					case(1): {
						int time = stoi(word[1]);
						ORD_TYPE type;
						if (word[2] == "N")
							type = TYPE_NRM;
						else if (word[2] == "F")
							type = TYPE_FROZ;
					//	else if (word[2] == "L")
						//	type = TYPE_FAMILY;
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
						bool crit = stoi(word[7]);
						ArrivalEvent * A = new ArrivalEvent(time, type, ID, dist, money, reg,crit);
						R->AddEvent(A);
					}
							 break;
					case(2): {
						int time = stoi(word[1]);
						int id = stoi(word[2]);
						CancellationEvent* C = new CancellationEvent(time, id);
						R->AddEvent(C);
					}
							 break;
					case(3): {
						int time = stoi(word[1]);
						int ID = stoi(word[2]);
						double money = stod(word[3]);
						PromotionEvent* P = new PromotionEvent(time, ID, money);
						R->AddEvent(P);
					}
							 break;
					}
				}
				}
			}
		}
		R->creat_motor_cycles(motorCyclesInA,motorCyclesInB, motorCyclesInC, motorCyclesInD, NRMspeedA, NRMspeedB, NRMspeedC, NRMspeedD,FRZspeedA,FRZspeedB,FRZspeedC,FRZspeedD,VIPspeedA,VIPspeedB,VIPspeedC,VIPspeedD );
		infile.close();
		return true;
}


int ReadInput::getAutoPromotionLimit()
{
	return AutoPromotionLimit;
}

int ReadInput::getTimeToRepair()
{
	return timeToRepair;
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
	delete  NRMspeedA, NRMspeedB, NRMspeedC, NRMspeedD, FRZspeedA, FRZspeedB, FRZspeedC,FRZspeedD, VIPspeedA,VIPspeedB,VIPspeedC,VIPspeedD ;
}
