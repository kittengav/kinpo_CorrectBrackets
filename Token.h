#pragma once
#include <string>
#include <vector>

using namespace std;

class Token
{
private:
	//������ � �������� �������� ��������
	vector<int> open_chars = {};

	//������ � �������� �������� ��������
	vector<int> close_chars = {};

public:
	//����, ��������� ������������ ��, ��� ������ ������
	bool ignore_flag = false;

	//������(�) ��������
	string open_symbol;

	//������(�) ��������
	string close_symbol;

	//����������� ������ Token
	Token(string open_symbol, string close_symbol);

	//����������� ������ Token 2
	Token(string open_symbol, string close_symbol, bool ignore_flag);
};

