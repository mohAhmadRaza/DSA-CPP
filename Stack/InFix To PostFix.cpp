#include<iostream>
#include<stack>
#include<map>
using namespace std;


string ConvertIfixToPostFix(string InfixExpression){
    map<char, int> precedence;
    stack<char> st;
    string PostFixExpression = "";

    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 3;

    for (int i=0 ; i<InfixExpression.length() ; i++){
        char currChar = InfixExpression[i];

        if (currChar != '+' && currChar != '-' && currChar != '*' && currChar != '/' && currChar != '^' ){
            PostFixExpression += currChar;
        }
        else{
            if (!st.empty() && precedence[st.top()] >= precedence[currChar] ){
                while (!st.empty() && precedence[st.top()] >= precedence[currChar])
                {
                    char currOperator = st.top();
                    PostFixExpression += currOperator;
                    st.pop();
                }
                st.push(currChar);
            }
            else if ( currChar == '(' ){
                st.push(currChar);
            }
            else if ( currChar == ')'){
                while (!st.empty() && st.top() != ')'){
                    char currOperator = st.top();
                    PostFixExpression += currOperator;
                    st.pop();
                }
                st.pop();
            }
            else{
                st.push(currChar);
            }

        }
    }

    while (!st.empty()){
        PostFixExpression += st.top();
        st.pop();
    }

    return PostFixExpression;
}

int main(){
    string InFixExpression = "A+B*C+D";
    cout << "iiii" << endl;
    string PostFixExpressin = ConvertIfixToPostFix(InFixExpression);
    cout << "dddd" << endl;
    cout << "Expression Converted : " << PostFixExpressin << endl;

    return 0;
}
