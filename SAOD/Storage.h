#pragma once
#include "Institute.h"
#pragma once
#pragma warning(disable:4996)
#include <fstream>
#include <iostream>

using namespace std;

class Storage
{
private:
	string address;
public:
	Storage(string _address) {
		address = _address;
	};

	bool InputData(Institute* _inst) {

		int number,number1,numberOfSeats;
		string _name;
		char buffer[100];
		char* f;

		ifstream file(address);

		if (!file.is_open())
			return false;
		file.getline(buffer, 100); 
		if (buffer != " ")
		{
			_name = buffer;
			_inst->SetName(_name);
		}
		else {
			cout << "Файл пуст\n";
			return false;
		}
		while (!file.eof()) {
			file.getline(buffer, 100); 
			f = strtok(buffer, " "); 
			if (f == NULL) continue; 
			try {
				if (f)
					number = stoi(f);
				else return false;
			}
			catch(exception invalid_argument)
			{
				return false;
			}
			_inst->Add(number); 
			f = strtok(NULL, " "); 
			while (f) { 
				try {
					if (f)
						number1 = stoi(f);
					else return false;
				}
				catch (exception invalid_argument)
				{
					return false;
				}
				f = strtok(NULL, " "); 
				try {
					if (f)
						numberOfSeats = stoi(f);
					else return false;
				}
				catch (exception invalid_argument)
				{
					return false;
				}
				_inst->AddA(number, number1, numberOfSeats);
				f = strtok(NULL, " ");
			}
		}
		file.close();
		return true;
	}

	bool OutputData(Institute* _inst) {
		ofstream file(address);
		if (!file.is_open())
			return false;
		file << _inst->GetName() + '\n' + _inst->getString();
		file.close();
		return true;
	};

	~Storage() { };
};


