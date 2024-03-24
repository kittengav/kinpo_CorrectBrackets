#pragma once
#include <vector>
#include "Token.h"

using namespace std;

class Validator
{
private:
	//������� ������ ������ �������
	vector<Token> tokens;

	//������� ��������
	int counter = 0;

	//������ ��� �������, ��������� �� ���������� ��������
	string buffer = "";

	vector<string> errors;

public:
	Validator(vector<Token> tokens);
	
	void next(char symbol);

	string get_errors();

	void end();
};


