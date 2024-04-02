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
							Token(string("//"), string("\n"), true), 
							Token(string("/*"), string("*/"), true),
							Token(string("\""), string("\""), true),
							Token(string("\'"), string("\'"), true)
							};

	//создаем валидатор, передав конструктуру токены
	Validator validator = Validator(tokens);

	char symbol; //объявляем переменную для хранения каждого символа
	ifstream fin; //для чтения из файла
	fin.open(file_name); //открытие файла
	//пока файл не закончился
	do 
	{
		//записать текущий символ в symbol
		//fin >> symbol;
		symbol = fin.get();
		//cout << symbol;
		//передаем его в validator
		validator.next(symbol);
	} while (!fin.eof());
	cout << "here\n";
	validator.end();

	string errors = validator.get_errors();
	//if (errors != string("")){
		cout << errors;
		return;
	//}
	cout << "success";
	return;
}
