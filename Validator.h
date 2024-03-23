#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class Validator
{
private:
	//атрибут класса вектор токенов
	vector<Token> tokens;

	//счетчик символов
	int counter = 0;

	//буффер для токенов, состоящих из нескольких символов
	vector<char> buffer;

public:
	Validator(vector<Token> tokens);
	
	void next(char symbol);
};


