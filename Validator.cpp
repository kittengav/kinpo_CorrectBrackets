#include "Validator.h"
#include <map>

Validator::Validator(vector<Token> tokens)
{
	this->tokens = tokens;
}

void Validator::next(char symbol)
{
	this->counter++; //�������������� ������� �������

	this->buffer += symbol;

	//��� ������� ������
	for (auto token : this->tokens) {
		//���� ����� ����������� ��� ������/������ � �� ������
		if (token.ignore_flag == true && token.is_opened()) {
			//�������� ����� validate
			token.validate(this->buffer, this->counter);
			//������� �� ������
			return;
		}
	}

	//�������������� ������ �������� �����������
	vector<int> results = {};

	//�������������� ������ ������� �������� �������
	map<int, string> opened_tokens = {};

	//{[ }]
	
		
	//�������� ���������� � �������� ���������� �������� ������� ������	
	for (auto token : this->tokens) {
		if (token.is_opened()) {
			opened_tokens[token.last_opened()] = token.close_symbol;
		}
	}


	//�������� ����� validate ��� ������� ������ � ���������� � results
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

