#pragma once
#include "Auditorium.h"
class Building {
private:
	struct bu {
		int number;
	}b;
	Auditorium* stack_h;
	Building* next;
public:
	Building() {
		b.number = 0;
		stack_h = nullptr;
		next = nullptr;
	}
	Building(int number,Auditorium* stack_h,Building* next) {
		b.number = number;
		this->stack_h = stack_h;
		this->next = next;
	}
	~Building() {
		next = nullptr;
		while (stack_h != nullptr) {
			Auditorium* temp = stack_h;
			stack_h = stack_h->GetNext();
			delete(temp);
		}
	}
	bool isEmpty() { return stack_h == nullptr; }
	bool Add(int number, int numberOfSeats) {
		if (!Find(number)) {
			stack_h = new Auditorium(number, numberOfSeats, stack_h);
			return true;
		}
		return false;
	}
	bool Del() {
		if(!isEmpty()){
			Auditorium* temp = stack_h;
			stack_h = stack_h->GetNext();
			delete(temp);
			return true;
		}
		return false;
	}
	bool Find(int number) {
		Auditorium* current = stack_h;
		while (current != nullptr) {
			if (current->GetNumber() == number) {
				return true;
			}
			current = current->GetNext();
		}
		return false;
	}
	void Show() {
		Auditorium* current = stack_h;
		while (current != nullptr) {
			if (current != stack_h) cout << "|" << setw(16) << "|";
			cout << setw(11) << current->GetNumber() << setw(5) << " " << setw(10) << current->GetNumberOfSeats() << setw(6);
			if (current->GetNext() != nullptr) cout << "\n";
			current = current->GetNext();
		}
	}
	string getString()
	{
		string str = "";
		if (!isEmpty())
		{
			Auditorium* current = stack_h;
			while (current != NULL) {
				stringstream ss,ss1;
				str += " ";
				ss << current->GetNumber();
				str += ss.str();
				str += " ";
				ss1 << current->GetNumberOfSeats();
				str += ss1.str();
				current = current->GetNext();
			}
		}
		return str;
	}
	void SetNumber(int number)
	{
		b.number = number;
	}
	int GetNumber()
	{
		return b.number;
	}
	void SetStack(Auditorium* stack_h) { this->stack_h = stack_h; }
	Auditorium* GetStack() { return stack_h; }
	void SetNext(Building* next) { this->next = next; }
	Building* GetNext() { return this->next; }
};