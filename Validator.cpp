#include "Validator.h"

Validator::Validator(vector<Token> tokens)
{
	this->tokens = tokens;
}

void Validator::next(char symbol)
{
	this->counter++; //инкрементируем счетчик символа

	this->buffer += symbol;

	//для каждого токена
	for (auto token : this->tokens) {
		if (token.ignore_flag == true && token.is_opened()) {
			token.validate(this->buffer, this->counter);
			return;
		}
	}

	vector<int> results = {};

	//для каждого токена
	for (auto token : this->tokens) {
		//
		results.push_back(token.validate(this->buffer, this->counter));
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

	{[ }]
}

