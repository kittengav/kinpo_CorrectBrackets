#pragma once
#include <string>

using namespace std;

class BaseException {
private:
	int position;
	string expected;
	string message;

public:

	BaseException(int position, string expected) {
		this->position = position;
		this->expected = expected;
	}

	BaseException(int position, string expected, string message) {
		this->position = position;
		this->expected = expected;
		this->message = message;
	}

	string get_message() {
		return this->message + string(". ") + string("Position: ") + to_string(position) + string(", expected: ") + this->expected;
	}
};