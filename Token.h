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

	//
	bool is_open = false;

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

	//
	int validate(string buffer, int position, vector<int> other_tokens);

	//
	void open(int position);

	//
	void close(int position, vector<int> other_tokens);

	//
	bool is_opened();

	int last_opened();
};

