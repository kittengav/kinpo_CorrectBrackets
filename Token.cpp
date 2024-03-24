#include "Token.h"
#include "exceptions.h"

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


int Token::validate(string buffer, int position, vector<int> other_tokens)
{
	//если содержимое буффера равно символу открытия токена
	if (buffer == this->open_symbol) {
		this->open(position);
		return 2;
	}

	//если буффер является началом символа открытия токена
	if (buffer == this->open_symbol.substr(0, buffer.size())) {
		return 1;
	}

	//если содержимое буффера равно символу закрытия токена
	if (buffer == this->close_symbol) {
		this->close(position, other_tokens);
		return 2;
	}

	//если буффер является началом символа закрытия токена
	if (buffer == this->close_symbol.substr(0, buffer.size())) {
		return 1;
	}

	return 0;
}

void Token::open(int position)
{
	this->is_open = true;
	this->open_chars.push_back(position);
}

void Token::close(int position, vector<int> other_tokens)
{
	for (auto open_pos:other_tokens){
		if (this->last_opened() < open_pos) {
			throw BaseException(position, );
		}
	}
	this->is_open = false;
	this->close_chars.push_back(position);

}

bool Token::is_opened()
{
	return this->is_open;
}

int Token::last_opened()
{
	return this->open_chars[this->open_chars.size() - 1];
}


