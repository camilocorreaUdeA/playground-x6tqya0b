#include "test_exe.h"
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void Message(string channel, string msg) {
    stringstream ss(msg);
    string line;
    while (getline(ss, line, '\n')) {
        cout << "TECHIO> message --channel \"" << channel << "\" \"" << line << "\"" << endl;
    }
}

void Success(bool success) {
    cout << "TECHIO> success " << (success ? "true" : "false") << endl;
}


void AssertEquals(int expected, int found, string message) {
    if(expected != found) {
        ostringstream error;
        error << message << " Expected: " << expected << ", Found: " << found  << endl;
        throw logic_error(error.str());
    }
}

int main() {
    try {
        int n1 = 8;
        AssertEquals(40320, TestClass::factorial(n1), "Running TestClass::factorial(8)...");

        int n2 = 0;
        AssertEquals(1, TestClass::factorial(n2), "Running TestClass::factorial(0)...");
        Success(true);
	
    } catch (const exception& e)  {
        Success(false);
        Message("Oops!", e.what());
        Message("Hint", "Did you properly coded the factorial math function?");
    }

  return 0;
}