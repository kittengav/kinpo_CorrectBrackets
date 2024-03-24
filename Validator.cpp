#include "Validator.h"
#include <map>

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
		//если токен комментарий или строка/символ и он открыт
		if (token.ignore_flag == true && token.is_opened()) {
			//вызываем метод validate
			token.validate(this->buffer, this->counter);
			//выходим из метода
			return;
		}
	}

	//инициализируем массив статусов результатов
	vector<int> results = {};

	//инициализируем массив позиций открытых токенов
	map<int, string> opened_tokens = {};

	//{[ }]
	
		
	//собираем информацию о позициях последнего открытия каждого токена	
	for (auto token : this->tokens) {
		if (token.is_opened()) {
			opened_tokens[token.last_opened()] = token.close_symbol;
		}
	}


	//вызвыаем метод validate для каждого токена и записываем в results
	for (auto token : this->tokens) {
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

}

