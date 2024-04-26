

// Include necessary libraries
#include<iostream>
#include<string>
#include<stack>
#include<fstream>

// Use the standard namespace
using namespace std;

// Function prototypes
int OpPriorty(char ch);
string InToPost(string infix);

// Function to determine operator precedence
int OpPriorty(char ch)
{
	if(ch == '+' || ch == '-')
		return 1; // Return 1 for addition or subtraction
	else if(ch == '*' || ch == '/')
		return 2; // Return 2 for multiplication or division
	else if(ch == '^')
		return 3; // Return 3 for exponentiation
	else 
		return 0; // Return 0 for other characters
}

// Function to convert infix expression to postfix
string InToPost(string infix)
{
	string postfix=""; // Initialize postfix string
	stack<char>s; // Initialize stack to hold operators
	int i =0;
	while(i<infix.length()) // Loop through each character in the infix string
	{
		if(isalpha(infix[i]) || isdigit(infix[i])) // If the character is an operand
		{
			postfix +=  infix[i]; // Add it to the postfix string
			i++;
		}
		else if(infix[i] == '(') // If the character is an open parenthesis
		{
			s.push(infix[i]); // Push it onto the stack
			i++;
		}
		else if (infix[i] == ')') // If the character is a close parenthesis
		{
			while(s.top() != '(') // While the top of the stack is not an open parenthesis
			{
				postfix += s.top(); // Add the top of the stack to the postfix string
				s.pop(); // Remove the top of the stack
			}
			s.pop(); // Remove the open parenthesis from the stack
			i++;
		}
		else // If the character is an operator
		{
			while(!s.empty() && OpPriorty(infix[i]) <= OpPriorty(s.top())) // While the stack is not empty and the precedence of the current operator is less than or equal to the precedence of the operator on the top of the stack
			{
				postfix += s.top(); // Add the top of the stack to the postfix string
				s.pop(); // Remove the top of the stack
			}
			s.push(infix[i]); // Push the current operator onto the stack
			i++;
		}
	}
	while(!s.empty()) // While the stack is not empty
	{
		postfix += s.top(); // Add the top of the stack to the postfix string
		s.pop(); // Remove the top of the stack
	}

	return postfix; // Return the postfix string
}

// Main function
int main()
{
	ifstream fin; // Initialize file input stream
	string infix, postfix; // Initialize infix and postfix strings
	fin.open("input.txt"); // Open the input file
	if(!fin) // If the file could not be opened
	{
		cout<<"File opening error!"<<endl; // Print an error message
		return 0; // End the program
	}
	while(!fin.eof()) // While not at the end of the file
	{
		fin>>infix; // Read an infix expression from the file
	    postfix = InToPost(infix); // Convert the infix expression to postfix
		cout<<postfix<<endl; // Print the postfix expression
	}
	system("pause"); // Pause the system to allow the user to see the output
	return 0; // End the program
}
