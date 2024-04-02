#include "Token.h"
#include "exceptions.h"
#include <map>
#include <iostream>

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


int Token::validate(string buffer, int position, map<int, string> other_tokens)
{
	cout << "validatein " << this->open_symbol << endl;

	if (this->open_symbol == this->close_symbol && buffer == this->open_symbol) {
		if (this->is_opened() ) {
			this->close(position, other_tokens);
			return 2;
		}
		this->open(position);
		return 2;
	}
	else if (this->open_symbol != this->close_symbol) {
		if (buffer == this->open_symbol) {
			this->open(position);
		}
		if (buffer == this->close_symbol) {
			if (this->is_opened()) {
				this->close(position, other_tokens);
				return 2;
			}
			else if (this->close_symbol != "\n") {
				throw BaseException(position, this->open_symbol);
			}
		}
	}
	if (buffer == this->open_symbol.substr(0, buffer.size())) {
		return 1;
	}

	if (buffer == this->close_symbol.substr(0, buffer.size())) {
		return 1;
	}
	return 0;


	if (!this->is_opened() && buffer == this->close_symbol) {
		if (this->close_symbol != "\n") {
			throw BaseException(position, this->open_symbol);
		}
		return 0;
	}
	if (buffer == this->open_symbol && this->open_symbol == this->close_symbol) {
		if (this->is_opened()) {
			this->close(position, other_tokens);
			return 2;
		}
		else {
			this->open(position);
			return 2;
		}
	}
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
	cout << "open " << this-> open_symbol << ": " << position << endl;
	this->open_count++;
	this->is_open = true;
	this->open_chars.push_back(position);
}

void Token::close(int position, map<int, string> other_tokens)
{
	cout << "close " << this->close_symbol << ": " << position << endl;
	for (auto const& iter : other_tokens)
	{
		if (this->last_opened() < iter.first) {
			throw BaseException(position, iter.second);
		}
	}
	if (this->open_count > 0) {
		throw BaseException(position, string(""));
	}
	this->perform_close(position);
}

bool Token::is_opened()
{
	return this->is_open;
}

int Token::last_opened()
{
	return this->open_chars[this->open_count - 1];
}

void Token::perform_close(int position)
{
	this->open_count--;
	this->is_open = false;
	this->close_chars.push_back(position);
}


