#include "Validator.h"
#include "exceptions.h"
#include <map>
#include <iostream>

Validator::Validator(vector<Token> tokens)
{
	this->tokens = tokens;
}

void Validator::next(char symbol)
{
	this->counter++; //инкрементируем счетчик символа

	this->buffer += symbol;

	try {
		map<int, string> opened_tokens = {};
		//собираем информацию о позициях последнего открытия каждого токена	
		for (auto token : this->tokens) {
			if (token.is_opened()) {
				opened_tokens[token.last_opened()] = token.close_symbol;
			}
		}

		//для каждого токена
		for (auto token : this->tokens) {
			//если токен комментарий или строка/символ и он открыт
			if (token.ignore_flag == true && token.is_opened()) {
				cout << "here2\n";
				//вызываем метод validate
				token.validate(this->buffer, this->counter, opened_tokens);
				//выходим из метода
				return;
			}
		}

		//инициализируем массив статусов результатов
		vector<int> results = {};

		//вызываем метод validate для каждого токена и записываем в results
		for (auto token : this->tokens) {
			results.push_back(token.validate(this->buffer, this->counter, opened_tokens));
		}
		for (auto r : results) {
			if (r == 2) {
				this->buffer = "";
				return;
			}
			if (r == 1) {
				return;
			}
		}
		this->buffer = "";
	}
	catch (BaseException e) {
		this->errors.push_back(e.get_message());
	}
}

string Validator::get_errors()
{
	string result = "";
	for (auto e : this->errors) {
		result += e + string("\n");
	}
	return result;
}

void Validator::end()
{
	for (auto token : this->tokens) {
		if (token.is_opened()) {
			this->errors.push_back(BaseException(this->counter, token.close_symbol, string("незакрытый токен")).get_message());
		}
	}
}

