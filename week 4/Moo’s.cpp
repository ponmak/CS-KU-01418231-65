#include<iostream>
#include<stack>
#include<queue>
#include<sstream>
#include <cctype>

using namespace std;

int main(){
    string expression;

    getline(cin, expression);
    stringstream ss(expression);
    string token;

    stack<string> operators;

    while (ss >> token) {
        operators.push(token);
    }

    float result = 0.0;
    float operand1, operand2;
    string op;
    while (!operators.empty()) {
        op = operators.top();
    
        if (op == "+" || op == "-" || op == "*" || op == "/" || op == "(" || op == ")"){

        } else if (isdigit((char&) op)){

        } else {
            cout << "ERROR : Invalid character"
        } 

    }
    

    return 0;
}

