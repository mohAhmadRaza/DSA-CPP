#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check precedence of operators
int precedence(char op)
{
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

// Function to check associativity of the operator
bool isRightAssociative(char op)
{
    if (op == '^') return true;
    return false;
}

// Function to reverse the string
string reverseString(string exp)
{
    reverse(exp.begin(), exp.end());
    
    // Swapping '(' with ')' and vice versa after reversing
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
    
    return exp;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(c))
        {
            postfix += c;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (c == '(')
        {
            st.push(c);
        }
        // If the character is a closing parenthesis, pop and output from the stack
        // until an opening parenthesis is found
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        // If the character is an operator
        else if (isOperator(c))
        {
            while (!st.empty() && precedence(st.top()) > precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            // For right associative operators like '^', handle equal precedence
            if (!st.empty() && precedence(st.top()) == precedence(c) && !isRightAssociative(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // Push current operator to stack
        }
    }

    // Pop all the remaining operators from the stack
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to convert infix to prefix expression
string infixToPrefix(string infix)
{
    // Step 1: Reverse the infix expression and swap parentheses
    string reversedInfix = reverseString(infix);

    // Step 2: Convert the reversed infix expression to postfix
    string postfix = infixToPostfix(reversedInfix);

    // Step 3: Reverse the postfix expression to get prefix
    string prefix = reverseString(postfix);

    return prefix;
}

int evaluatePrefix(string prefix)
{
    stack<int> st;
    
    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char c = prefix[i];
        
        // If character is a whitespace, skip it
        if (c == ' ')
            continue;

        // If the character is an operand (number), push it onto the stack
        if (isdigit(c))
        {
            int num = 0, factor = 1;
            
            // Handle multi-digit numbers
            while (i >= 0 && isdigit(prefix[i]))
            {
                num = num + (prefix[i] - '0') * factor;
                factor *= 10;
                i--;
            }
            i++; // Adjust index as we decremented it in the loop
            st.push(num);
        }
        // If the character is an operator, pop two operands, perform the operation, and push the result
        else if (isOperator(c))
        {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();
            
            int result = performOperation(c, operand1, operand2);
            st.push(result);
        }
    }
    
    // The final result will be at the top of the stack
    return st.top();
}

int main()
{
    string infix = "(A+B)*(C-D)";
    cout << "Infix Expression: " << infix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
