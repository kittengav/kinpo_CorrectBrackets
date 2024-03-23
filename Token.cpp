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
