#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class Token
{
private:
	//вектор с номерами символов открытия
	vector<int> open_chars = {};

	//вектор с номерами символов закрытия
	vector<int> close_chars = {};

	//
	bool is_open = false;

	int open_count = 0;

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

	//
	int validate(string buffer, int position, map<int, string> other_tokens);

	//
	void open(int position);

	//
	void close(int position, map<int, string> other_tokens);

	//
	bool is_opened();

	int last_opened();
};

