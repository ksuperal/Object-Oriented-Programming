#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

// Define the precedence and associativity of operators
const map<char, pair<int, int>> opPrecedence = {
    {'~', {3, 1}},
    {'&', {2, 0}},
    {'^', {1, 0}},
    {'|', {0, 0}}
};

// Evaluate the given operator on the given operands
int eval(char op, int left, int right) {
    switch (op) {
        case '~': return ~left;
        case '&': return left & right;
        case '^': return left ^ right;
        case '|': return left | right;
        default: throw runtime_error("Invalid operator: " + op);
    }
}

// Convert a string of digits to an integer
int toInt(const string& str) {
    int result = 0;
    for (char c : str) {
        if (c < '0' || c > '1') {
            throw runtime_error("Invalid digit: " + string(1, c));
        }
        result = (result << 1) | (c - '0');
    }
    return result;
}

// Parse and evaluate the given bitwise logical expression
int evalBitwise(const string& expr) {
    stack<int> operands;
    stack<char> operators;
    int i = 0;
    while (i < expr.length()) {
        char c = expr[i];
        if (c == ' ') {
            // Ignore whitespace
        } else if (isdigit(c)) {
            // Parse a binary number
            int j = i;
            while (j < expr.length() && isdigit(expr[j])) {
                j++;
            }
            operands.push(toInt(expr.substr(i, j - i)));
            i = j - 1;
        } else if (c == '~' || c == '&' || c == '^' || c == '|') {
            // Parse an operator
            while (!operators.empty() && opPrecedence.at(c).first <= opPrecedence.at(operators.top()).first &&
                    opPrecedence.at(c).second == 0) {
                // Pop higher-precedence operators
                char op = operators.top();
                operators.pop();
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                operands.push(eval(op, left, right));
            }
            operators.push(c);
        } else {
            throw runtime_error("Invalid character: " + string(1, c));
        }
        i++;
    }
    while (!operators.empty()) {
        // Evaluate remaining operators
        char op = operators.top();
        operators.pop();
        int right = operands.top();
        operands.pop();
        int left = operands.top();
        operands.pop();
        operands.push(eval(op, left, right));
    }
    return operands.top();
}

// Main program
int main() {
    string expr;
    cout << "Enter a bitwise logical expression: ";
    getline(cin, expr);
    try {
        int result = evalBitwise(expr);
        cout << "Result: " << result << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}