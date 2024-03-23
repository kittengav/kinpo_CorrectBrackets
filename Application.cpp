#include "Application.h"
#include "Token.h"
#include "Validator.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Application::Application(string file_name)
{
	//������� ������ �������
	vector<Token> tokens = {Token(string("("), string(")")), 
							Token(string("{"), string("}")), 
							Token(string("["), string("]")), 
							Token(string("//"), string("\n")), 
							Token(string("/*"), string("*/"))
							};

	//������� ���������, ������� ������������ ������
	Validator validator = Validator(tokens);

	char symbol; //��������� ���������� ��� �������� ������� �������
	ifstream fin; //��� ������ �� �����
	fin.open(file_name); //�������� �����
	//���� ���� �� ����������
	while (!fin.eof())
	{
		//�������� ������� ������ � symbol
		fin >> symbol;
		//�������� ��� � validator
		validator.next(symbol);
	}
}
