#include<iostream>  
#include<stack>  

using namespace std;
// defines the Boolean function for operator, operand, equalOrhigher precedence and the string conversion function.  
bool IsOperator(char);
bool IsOperand(char);
bool eqlOrhigher(char, char);
string convert(string);
// define the IsOperator() function to validate whether any symbol is operator.  
/* If the symbol is operator, it returns true, otherwise false. */
bool IsOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

// IsOperand() function is used to validate whether the character is operand.  
bool IsOperand(char c)
{
	if (c >= 'A' && c <= 'Z')  /* Define the character in between A to Z. If not, it returns False.*/
		return true;
	if (c >= 'a' && c <= 'z')  // Define the character in between a to z. If not, it returns False. */  
		return true;
	if (c >= '0' && c <= '9')   // Define the character in between 0 to 9. If not, it returns False. */  
		return true;
	return false;
}
// here, precedence() function is used to define the precedence to the operator.  
int precedence(char op)
{
	if (op == '+' || op == '-')                   /* it defines the lowest precedence */
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')                                  //exponent operator has the highest precedence
		return 3;
	return 0;
}
/* The eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. */
bool eqlOrhigher(char op1, char op2)
{
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

/* string convert() function is used to convert the infix expression to the postfix expression of the Stack */
string convert(string infix)
{
		stack <char> S;
		string postfix = "";
		char ch;

		S.push('(');
		infix += ')';

		for (int i = 0; i < infix.length(); i++)
		{
			ch = infix[i];

			if (ch == ' ')
				continue;
			else if (ch == '(')
				S.push(ch);
			else if (IsOperand(ch))
				postfix += ch;
			else if (IsOperator(ch))
			{
				while (!S.empty() && eqlOrhigher(S.top(), ch))
				{
					postfix += S.top();
					S.pop();
				}
				S.push(ch);
			}
			else if (ch == ')')
			{
				while (!S.empty() && S.top() != '(')
				{
					postfix += S.top();
					S.pop();
				}
				S.pop();
			}
		}
		return postfix;
	
}
char expr[50];
int SIZE = sizeof(expr) / sizeof(expr[0]);
//int SIZE = 10;
int top = -1;
void PUSH(char element) {
	if (top == SIZE - 1) {
		cout << "Stack is full" << endl;

	}
	top++;
	expr[top] = element;
}
int POP() {
	if (top == -1) {
		//cout << "Stack is empty" << endl;
		return 0;

	}
	int returnValue = expr[top];
	top--;
	return returnValue;
}
int postFix(char* exp) {
	for (int i = 0; i < SIZE; i++)
	{
		if (exp[i] == ')')
		{
			return POP();
		}
		else if (isdigit(exp[i]))
		{
			PUSH(exp[i] - '0');
		}
		else
		{
			int num1 = POP();
			int num2 = POP();
			switch (exp[i])
			{
			case'+':
				PUSH(num2 + num1);
				break;
			case'-':
				PUSH(num2 - num1);
				break;
			case'*':
				PUSH(num2 * num1);
				break;
			case'/':
				PUSH(num2 / num1);
				break;
			}
		}
	}
	return POP();
}
void display() {
	for (int i = 0; i < SIZE; i++) {
		cout << expr[i] << " ";
	}
	cout << endl;
}

int main()
{
	
	
	string infix_expression, postfix_expression;
	char ex[50];
	int ch;
	int input;
	do
	{
		system("CLS");
	cout << "---------------------------------------------------------" << endl;
	cout << "            INFIX-POSTFIX CALCULATOR               " << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "\t\t\t ===================" << endl;
	cout << "\t\t\t 1)INFIX TO POSTFIX " << endl;
	cout << "\t\t\t 2)POSTFIX EVALUATION" << endl;
	cout << "\t\t\t 3)EXIT" << endl;
	cout << "\t\t\t ===================" << endl;
	cout << endl;
	cout << "Enter your Choice here: " << endl;
	cin >> input;
	switch (input)
	{
	case 1:
			system("CLS");
			cout << "Enter an infix expression: ";
			cin >> infix_expression;
			postfix_expression = convert(infix_expression);
			cout << "\n Your Infix expression is: " << infix_expression << endl;
			cout << "\n Postfix expression is: " << postfix_expression << endl;
			cout << "______________________________" << endl;
			cout << endl;
			cout << endl;
			break;
	case 2:
		system("CLS");
		cout << "Enter PostFix Expression Again: ";
		cin >> ex;
		cout << "Value is: " << postFix(ex) << endl;
		cout << "______________________________" << endl;
		break;

	case 3:
		system("CLS");
		exit(0);
		break;
	}
	cout << "\n \t Do you want to continue!!! (1/ 0)?";
	cin >> ch;
	} while (ch == 1);
	return 0;
}
