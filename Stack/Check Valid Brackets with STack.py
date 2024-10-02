#include <iostream>
#include <algorithm>
#include<map>
using namespace std;

class Stack
{
private:
    int top;
public:

    //Fixed size array
    char stack[10];
    
    // Constructor
    Stack() { top = -1; }

    void push(char newElement)
    {
        if (IsFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            stack[++top] = newElement;
        }
    }

    char pop(){
        if (!IsEmpty()){
            return stack[top--];
        }
        else return '-';
    }

    bool IsEmpty(){
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull(){
        if (top >= 10){
            return true;
        }
        else{
            return false;
        }
    }

    char GetTop(){
        if (!IsEmpty()){return stack[top];}
        else {return '-';}
    }

};

bool IsBalanced(string brackets, Stack stack){

        map<char, char> dictionary;
        dictionary['}'] = '{';
        dictionary[')'] = '(';
        dictionary[']'] = '[';

        for (int i =0 ; i < brackets.length() ; i++){
            char currChar = brackets[i];

            if (currChar == '{' || currChar == '[' || currChar == '(' ){
                stack.push(currChar);
            }
            else if (!stack.IsEmpty() && (stack.GetTop() == dictionary[currChar])){
                stack.pop();
            }
        }

        return stack.IsEmpty();
}

int main(){
    Stack stack;

    string brackets = "{{{()}}}{}(()){}";

    if (!IsBalanced(brackets, stack)){ cout << "Sequence Is Wrong" << endl;}
    else{ cout << "Sequence Is True" << endl;}

    return 0 ;
}
