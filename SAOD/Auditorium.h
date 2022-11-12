#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
class Auditorium {
private:
	struct au {
		int number;
		int numberOfSeats;
	}a;
	Auditorium* next;
public:
	Auditorium() {
		a.number = 0;
		a.numberOfSeats;
		this->next = nullptr;
	}
	Auditorium(int number, int numberOfSeats, Auditorium* next) {
		a.number = number;
		a.numberOfSeats = numberOfSeats;
		this->next = next;
	}
	~Auditorium() {
		next = nullptr;
	}
	void SetNumber(int number) { a.number = number; }
	void SetNumberOfSeats(int numberOfSeats) { a.numberOfSeats = numberOfSeats; }
	void SetNext(Auditorium* next) { this->next = next; }
	int GetNumber() { return a.number; }
	int GetNumberOfSeats() { return a.numberOfSeats; }
	Auditorium* GetNext() { return this->next; }
};