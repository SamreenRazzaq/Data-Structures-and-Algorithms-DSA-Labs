#include<iostream>  
#include<stack>  
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Conversion
bool IsOperator(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}
bool IsOperand(char c){
	if (c >= '0' && c <= '9')   // Define the character in between 0 to 9. If not, it returns False. 
		return true;
	return false;
}
int precedence(char op)
{
	if (op == '+' || op == '-')                   /* it defines the lowest precedence */
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')                                // exponent operator has the highest precedence 
		return 3;
	return 0;
}
bool eqlOrhigher(char op1, char op2){
		int p1 = precedence(op1);
		int p2 = precedence(op2);
		if (p1 == p2)
		{
			if (op1 == '^')
				return false;
			return true;
		}
		return  (p1 > p2 ? true : false);
	}
string convert(string infix){
		stack <char> S;
		string postfix = "    ";
		char ch;
		S.push('(');
		infix += ')';
		bool flag = false;
		for (int i = 0; i < infix.length(); i++)
		{
			ch = infix[i];
			char dh = infix[i + 1];
			if (ch == ' ')
				continue;
			else if (ch == '(') 
				S.push(ch);
			else if (IsOperand(ch)) {
				postfix += ch;
				if (dh == '(' || dh == ')' || dh == '+' || dh == '*' || dh == '-' || dh == '/' || dh == '^')
					postfix += ' ';
			}else if (IsOperator(ch)){
				while (!S.empty() && eqlOrhigher(S.top(), ch))
				{
					postfix += ' ';
					postfix += S.top();
					postfix += ' ';
					S.pop();
				}
				S.push(ch);
			}
			else if (ch == ')')
			{
				while (!S.empty() && S.top() != '(')
				{
					postfix += ' ';
					postfix += S.top();
					
					postfix += ' ';
					S.pop();
				}
				S.pop();
			}
		}
		istringstream ss(postfix);
		string word;
		string result;
		while (ss >> word) {
			result += word;
			result += " ";
		}

		return result;
	}

// Evaluation
double long eval(double long op1, double long op2, string op) {
		if (op == "/") {
			return op2 / op1;
		}
		else if (op == "*") {
			return op2 * op1;
		}
		else if (op == "+") {
			return op2 + op1;
		}
		else if (op == "-") {
			return op2 - op1;
		}
		else if (op == "^") {
			double long a = 1;
			for (int i = 0; i < op1; i++)
				a *= op2;
			
			return a;
		}else {
			return 0.0;
		}
}
void evalPostfix(string L) {
	istringstream ss(L);
	string word;
	stack<double long> s;
	double long val;
	while (ss >> word)
	{
		string ch = word;
		try {
			if(word != "(" || word != ")" || word != " + " || word != " * " || word != " - " || word != " / " || word != " ^ ") {;
				double long v = std::stold(word);
				s.push(v);
			}
		}
		catch (...) {
			cout << endl;
			double long op1 = s.top();
			s.pop();
			double long op2 = s.top();
			s.pop();
			val = eval(op1, op2, ch);
			s.push(val);
		}
	}
	cout << "Expression evaluates to " << val;
}


// Main function
int main(){
		string infix_expression, postfix_expression;
		int ch;
		do{
			cout << "----------------------------------------------------------" << endl;
			cout << "Enter an infix expression: ";
			cin >> infix_expression;
			cout << "----------------------------------------------------------" << endl;
			postfix_expression = convert(infix_expression);
			cout << endl;
			cout << "Your Infix expression is: " << infix_expression<<endl ;
			cout << endl;
			cout << "Postfix expression is: " << postfix_expression;
			cout << endl;
			evalPostfix(postfix_expression);
			cout << endl;
			cout << "----------------------------------------------------------" << endl;
			cout << ">>>Do you want to enter infix expression (1/ 0)?"<<endl;
			cout << "----------------------------------------------------------" << endl;
			cin >> ch;   
		} while (ch == 1);
		return 0;
	}