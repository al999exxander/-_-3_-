#include <iostream>
#include "windows.h"
#include "ExpressionEvaluator.h"
#include "CustomExpressionEvaluator.h"
#include "Subtractor.h"
#include "Multiplier.h"
#include "Employee.h"
#include "Photographer.h"
#include "Designer.h"
using namespace std;




int main()
{


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout<< "Лабораторная работа №3, Мамонтов Влад ИВТ-1, 2курс\nВыберите номер задания или \'0\' для выхода: ";
	int num = 0;
	cin >> num;
	system("cls");
	while (num != 0) {
		switch (num)
		{
		case 1:
			void Task_1();
			Task_1();
			break;
		case 2: void Task_2();
			Task_2();
		}
		cout << "Нажмите кнопку для продолжения" << endl;
		system("pause");
		system("cls");
		cout << "Выберите номер задания (1-3) или \'0\' для выхода: ";
		cin >> num;
	}
	return 0;
}

void Task_1() {

	ExpressionEvaluator* evaluators[3];

	const int custom_expression_len = 5;
	evaluators[0] = new CustomExpressionEvaluator(custom_expression_len);
	double custom_expression_arr[custom_expression_len] = { 5,10,-2.5,-40,-2 };
	evaluators[0]->SetOperands(custom_expression_arr, custom_expression_len);

	const int subtractor_len = 9;
	evaluators[1] = new Subtractor(subtractor_len);
	double subtractor_arr[subtractor_len] = { 120,-12,83.2,-1.5,5,7,2,18.5,76 };
	evaluators[1]->SetOperands(subtractor_arr, subtractor_len);

	const int multiplier_len = 2;
	evaluators[2] = new Multiplier(multiplier_len);
	evaluators[2]->SetOperand(0, -1.5);
	evaluators[2]->SetOperand(1, 80);

	for (int i = 0; i < 3; i++) {
		evaluators[i]->LogToScreen();
		evaluators[i]->LogToFile("Log_Lab3");
		cout << "< Result: " << evaluators[i]->calculate() << " >" <<endl<< endl;
		
	}

	

	for (int i = 0; i < 3; i++) {
		
		IShuffle* shuffle = dynamic_cast<IShuffle*>(evaluators[i]);

		if (shuffle) {
			
			shuffle->shuffle();
			evaluators[i]->LogToScreen();
			cout <<"< Result: " << evaluators[i]->calculate() <<" >" << endl << endl;
		}
	}


	for (int i = 0; i < 3; i++) {
		delete evaluators[i];
	}

}
void Task_2() {

	Employee* employee[4];

	employee[0] = new Photographer("Vlad", "Mamntov", 'm', 2001, 2016, "0713460017", 57);
	employee[1] = new Photographer("Nikita", "Bulichev", 'm', 2001, 2014, "0715541234", 102);
	employee[2] = new Designer("Tanya", "Lev", 'f', 2001, 2017, "0714002346");
	employee[3] = new Designer("Julia", "Suslova", 'f', 2001, 2013, "0714569478");

	string photo[] = { "C#","C++","Phyton","Java" };
	for (int i = 0; i < 4; i++) {
		cout << "--------------------------------Сотрудник №" << i + 1 << "------------------------------------" << endl;
		employee[i]->Imitation();
		cout << "--------------------------------START Process-------------------------------" << endl;
		employee[i]->Process(photo[i]);
		cout << "--------------------------------END Process------------------------------------" << endl << endl;
		cout << "--------------------------------START Print-----------------------------------" << endl;
		employee[i]->PrintStatistics();
		cout << "--------------------------------END Print-------------------------------------" << endl;
		delete employee[i];
	}


}