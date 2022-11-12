#include <windows.h> 
#include <string>
#include <fstream>
#include "Storage.h"
#define _CRT_SECURE_NO_WARNINGS

Institute* inst = NULL;
Storage file("text.txt");

int failure() {
	int a;
	while (!(cin >> a) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "������ �����. ���������: ";
	}
	return a;
}

void Add()
{
	int number;
	cout << "������� ����� �������� ������: ";
	number = failure();
	if (inst->Add(number)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void AddA()
{
	int number, number1, parts;
	cout << "������� ����� �������� ������ : ";
	number = failure();
	cout << "������� ����� ���������: ";
	number1 = failure();
	cout << "������� ���������� ����: ";
	parts = failure();
	if(inst->AddA(number, number1, parts)) cout << "���������� �������!\n";
	else cout << "���������� �� �������!\n";
}
void Del()
{
	if (inst->Del()) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void DelA()
{
	int number;
	cout << "������� ����� ������, � ������� ��������� ������� ���������: ";
	number = failure();
	if (inst->DelA(number)) cout << "�������� �������!\n";
	else cout << "�������� �� �������!\n";
}
void Find()
{
	int number;
	cout << "������� ����� �������� ������: ";
	number = failure();
	if (inst->Find(number)) cout << "������� ������ �������!\n";
	else cout << "������� ������ �� �������";
}
void FindA()
{
	int number, number1;
	cout << "������� ����� �������� ������: ";
	number = failure();
	cout << "������� ����� ���������: ";
	cin >> number1;
	if (inst->FindA(number, number1)) cout << "� �������� ������ ���� ��������� � ����� �������!\n";
	else cout << "� �������� ������ ��� ��������� � ����� �������!\n";

}
void Show()
{
	{
		cout << "\n----------------------------------------------------\n";
		cout << "|              �������� '" << inst->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|     �����     |" << "      �����          ���-��        ";
		cout << "\n|  ��. ������   |" << "     ���������        ����         \n";
		inst->Show();
		cout << "----------------------------------------------------\n";
	}
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	inst = new Institute();
	while (true) {
		Show();
		cout << "\n �������� ��������:\n";
		cout << " 1. �������� ������� ������\n";
		cout << " 2. �������� ���������\n";
		cout << " 3. ������� ������� ������\n";
		cout << " 4. ������� ���������\n";
		cout << " 5. ����� ������� ������\n";
		cout << " 6. ����� ���������\n";
		cout << " 7. ������������� ��������\n";
		cout << " 8. ������� �������� � ������� ������\n";
		cout << " 9. ��������� �������� �� �����\n";
		cout << " 10. ��������� �������� � ����\n";
		cout << " 0. �����\n";
		n = failure();
		if (n == 1)
			Add();
		else if (n == 2)
			AddA();
		else if (n == 3)
			Del();
		else if (n == 4)
			DelA();
		else if (n == 5)
			Find();
		else if (n == 6)
			FindA();
		else if (n == 7)
		{
			string newName;
			cout << "������� �������� ���������: ";
			cin >> newName;
			inst->SetName(newName);
		}
		else if (n == 8)
		{
			delete(inst);
			inst = new Institute();
		}
		else if (n == 9)
		{
			delete(inst);
			inst = new Institute();
			if (file.InputData(inst)) cout << "�������� �������!";
			else
			{
				cout << "������!";
				delete(inst);
				inst = new Institute();
			}
		}
		else if (n == 10)
		{
			if (inst != NULL)
			{
				if (file.OutputData(inst)) cout << "�������� �������!";
				else cout << "������";
			}
			else cout << "������!";
		}
		else if (n == 0) {
			delete(inst);
			break;
		}
	}
}
