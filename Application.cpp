#include "Application.h"
#include "Token.h"
#include "Validator.h"
#include <vector>
#include <string>

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
}
