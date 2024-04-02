#include "Application.h"
#include "Token.h"
#include "Validator.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

Application::Application(string file_name)
{
	//������� ������ �������
	vector<Token> tokens = {Token(string("("), string(")")), 
							Token(string("{"), string("}")), 
							Token(string("["), string("]")), 
							Token(string("//"), string("\n"), true), 
							Token(string("/*"), string("*/"), true),
							Token(string("\""), string("\""), true),
							Token(string("\'"), string("\'"), true)
							};

	//������� ���������, ������� ������������ ������
	Validator validator = Validator(tokens);

	char symbol; //��������� ���������� ��� �������� ������� �������
	ifstream fin; //��� ������ �� �����
	fin.open(file_name); //�������� �����
	//���� ���� �� ����������
	do 
	{
		//�������� ������� ������ � symbol
		//fin >> symbol;
		symbol = fin.get();
		//cout << symbol;
		//�������� ��� � validator
		validator.next(symbol);
	} while (!fin.eof());
	cout << "here\n";
	validator.end();

	string errors = validator.get_errors();
	//if (errors != string("")){
		cout << errors;
		return;
	//}
	cout << "success";
	return;
}
