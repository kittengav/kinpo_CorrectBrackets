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
	vector<char> buffer;

public:
	Validator(vector<Token> tokens);
	
	void next(char symbol);
};


