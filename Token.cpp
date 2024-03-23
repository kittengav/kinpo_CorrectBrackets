#include "Token.h"

Token::Token(string open_symbol, string close_symbol)
{
	this->open_symbol = open_symbol;
	this->close_symbol = close_symbol;
}

Token::Token(string open_symbol, string close_symbol, bool ignore_flag)
{
	this->open_symbol = open_symbol;
	this->close_symbol = close_symbol;
	this->ignore_flag = ignore_flag;
}

int Token::validate(string buffer, int position)
{
	//���� ���������� ������� ����� ������� �������� ������
	if (buffer == this->open_symbol) {
		this->open(position);
		return 2;
	}

	//���� ������ �������� ������� ������� �������� ������
	if (buffer == this->open_symbol.substr(0, buffer.size())) {
		return 1;
	}

	//���� ���������� ������� ����� ������� �������� ������
	if (buffer == this->close_symbol) {
		this->close(position);
		return 2;
	}

	//���� ������ �������� ������� ������� �������� ������
	if (buffer == this->close_symbol.substr(0, buffer.size())) {
		return 1;
	}



	return 0;
}

void Token::open(int position)
{
}

void Token::close(int position)
{
}

bool Token::is_opened()
{
	return this->is_open;
}
