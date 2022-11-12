#pragma once
#include "Building.h"
class Institute {
private:
	struct in {
		string name;
	}i;
	Building* stack_h;
public:
	Institute() {
		i.name = "";
		stack_h = nullptr;
	}
	Institute(string name, Building* stack_h) {
		i.name = name;
		this->stack_h = stack_h;
	}
	~Institute() {
		while (stack_h != nullptr) {
			Building* temp = stack_h;
			stack_h = stack_h->GetNext();
			delete(temp);
		}
	}
	bool isEmpty() { return stack_h == nullptr; }
	bool Add(int number) {
		if (!Find(number)) {
			stack_h = new Building(number,nullptr,stack_h);
			return true;
		}
		return false;
	}
	bool Del() {
		if (!isEmpty()) {
			Building* temp = stack_h;
			stack_h = stack_h->GetNext();
			delete(temp);
			return true;
		}
		return false;
	}
	bool Find(int number) {
		Building* current = stack_h;
		while (current != nullptr) {
			if (current->GetNumber() == number) {
				return true;
			}
			current = current->GetNext();
		}
		return false;
	}
	bool AddA(int number,int number1,int numberOfSeats) {
		Building* current = stack_h;
		while (current != nullptr) {
			if (current->GetNumber() == number) {
				return current->Add(number1, numberOfSeats);
			}
			current = current->GetNext();
		}
		return false;
	}
	bool DelA(int number) {
		Building* current = stack_h;
		while (current != nullptr) {
			if (current->GetNumber() == number) {
				return current->Del();
			}
			current = current->GetNext();
		}
		return false;
	}
	bool FindA(int number, int number1) {
		Building* current = stack_h;
		while (current != nullptr) {
			if (current->GetNumber() == number) {
				return current->Find(number1);
			}
			current = current->GetNext();
		}
		return false;
	}
	string GetName() {
		return i.name;
	}
	void SetName(string name) {
		i.name = name;
	}
	void Show() {
		Building* current = stack_h;
		while (current != nullptr) {
			stringstream ss;
			cout << "----------------------------------------------------\n";
			cout << "|" << setw(8) << current->GetNumber() << setw(8) << "|";
			current->Show();
			cout << "\n";
			current = current->GetNext();
		}
	}
	string getString() 
	{
		string str = "";
		Building* current = stack_h;
		while (current != nullptr)
		{
			stringstream ss;
			ss << current->GetNumber();
			str += ss.str();
			str += current->getString();
			str += '\n';
			current = current->GetNext();
		}
		return str;
	}
	void SetStack(Building* stack_h) { this->stack_h = stack_h; }
	Building* GetStack(){ return this->stack_h; }
};