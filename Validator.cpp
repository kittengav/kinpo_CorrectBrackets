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
	this->counter++; //�������������� ������� �������

	this->buffer += symbol;

	try {
		map<int, string> opened_tokens = {};
		//�������� ���������� � �������� ���������� �������� ������� ������	
		for (auto token : this->tokens) {
			if (token.is_opened()) {
				opened_tokens[token.last_opened()] = token.close_symbol;
			}
		}

		//��� ������� ������
		for (auto token : this->tokens) {
			//���� ����� ����������� ��� ������/������ � �� ������
			if (token.ignore_flag == true && token.is_opened()) {
				cout << "here2\n";
				//�������� ����� validate
				token.validate(this->buffer, this->counter, opened_tokens);
				//������� �� ������
				return;
			}
		}

		//�������������� ������ �������� �����������
		vector<int> results = {};

		//�������� ����� validate ��� ������� ������ � ���������� � results
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
			this->errors.push_back(BaseException(this->counter, token.close_symbol, string("���������� �����")).get_message());
		}
	}
}

