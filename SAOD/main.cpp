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
		cout << "Ошибка ввода. Повторите: ";
	}
	return a;
}

void Add()
{
	int number;
	cout << "Введите номер учебного здания: ";
	number = failure();
	if (inst->Add(number)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void AddA()
{
	int number, number1, parts;
	cout << "Введите номер учебного здания : ";
	number = failure();
	cout << "Введите номер аудитории: ";
	number1 = failure();
	cout << "Введите количество мест: ";
	parts = failure();
	if(inst->AddA(number, number1, parts)) cout << "Добавление успешно!\n";
	else cout << "Добавление не успешно!\n";
}
void Del()
{
	if (inst->Del()) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void DelA()
{
	int number;
	cout << "Введите номер здания, в котором требуется удалить аудиторию: ";
	number = failure();
	if (inst->DelA(number)) cout << "Удаление успешно!\n";
	else cout << "Удаление не успешно!\n";
}
void Find()
{
	int number;
	cout << "Введите номер учебного здания: ";
	number = failure();
	if (inst->Find(number)) cout << "Учебное здание найдено!\n";
	else cout << "Учебное здание не найдено";
}
void FindA()
{
	int number, number1;
	cout << "Введите номер учебного здания: ";
	number = failure();
	cout << "Введите номер аудитории: ";
	cin >> number1;
	if (inst->FindA(number, number1)) cout << "В заданном здании есть аудитория с таким номером!\n";
	else cout << "В заданном здании нет аудитории с таким номером!\n";

}
void Show()
{
	{
		cout << "\n----------------------------------------------------\n";
		cout << "|              Институт '" << inst->GetName() << "'";
		cout << "\n----------------------------------------------------";
		cout << "\n|     Номер     |" << "      Номер          Кол-во        ";
		cout << "\n|  уч. здания   |" << "     аудитории        мест         \n";
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
		cout << "\n Выберите действие:\n";
		cout << " 1. Добавить учебное здание\n";
		cout << " 2. Добавить аудиторию\n";
		cout << " 3. Удалить учебное здание\n";
		cout << " 4. Удалить аудиторию\n";
		cout << " 5. Найти учебное здание\n";
		cout << " 6. Найти аудиторию\n";
		cout << " 7. Переименовать институт\n";
		cout << " 8. Удалить институт и создать пустой\n";
		cout << " 9. Загрузить институт из файла\n";
		cout << " 10. Выгрузить институт в файл\n";
		cout << " 0. Выход\n";
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
			cout << "Введите название института: ";
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
			if (file.InputData(inst)) cout << "Загрузка успешна!";
			else
			{
				cout << "Ошибка!";
				delete(inst);
				inst = new Institute();
			}
		}
		else if (n == 10)
		{
			if (inst != NULL)
			{
				if (file.OutputData(inst)) cout << "Выгрузка успешна!";
				else cout << "Ошибка";
			}
			else cout << "Ошибка!";
		}
		else if (n == 0) {
			delete(inst);
			break;
		}
	}
}
