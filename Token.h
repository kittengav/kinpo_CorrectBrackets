#pragma once
#include <string>
#include <vector>

using namespace std;

class Token
{
private:
	//вектор с номерами символов открытия
	vector<int> open_chars = {};

	//вектор с номерами символов закрытия
	vector<int> close_chars = {};

public:
	//флаг, говорящий игнорировать то, что внутри токена
	bool ignore_flag = false;

	//символ(ы) открытия
	string open_symbol;

	//символ(ы) закрытия
	string close_symbol;

	//конструктор класса Token
	Token(string open_symbol, string close_symbol);

	//конструктор класса Token 2
	Token(string open_symbol, string close_symbol, bool ignore_flag);
};

