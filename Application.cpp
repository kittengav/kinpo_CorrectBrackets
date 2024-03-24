#include "Application.h"
#include "Token.h"
#include "Validator.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Application::Application(string file_name)
{
	//создаем вектор Токенов
	vector<Token> tokens = {Token(string("("), string(")")), 
							Token(string("{"), string("}")), 
							Token(string("["), string("]")), 
							Token(string("//"), string("\n")), 
							Token(string("/*"), string("*/"))
							};

	//создаем валидатор, передав конструктуру токены
	Validator validator = Validator(tokens);

	char symbol; //объявляем переменную для хранения каждого символа
	ifstream fin; //для чтения из файла
	fin.open(file_name); //открытие файла
	//пока файл не закончился
	while (!fin.eof())
	{
		//записать текущий символ в symbol
		fin >> symbol;
		//передаем его в validator
		validator.next(symbol);
	}

	validator.end();

	string errors = validator.get_errors();
	if (errors != string("")){
		cout << errors;
		return;
	}
	cout << "success";
	return;
}
