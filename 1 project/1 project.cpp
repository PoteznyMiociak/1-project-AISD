#include "Stos.h" // Include your stack implementation
#include "List.h"
#include <iostream>
using namespace std;

bool is_number(char token) {
    return (token >= '0' && token <= '9');
}

int get_priority(char token) {
    if (token == 'N')
        return 4;
    else if (token == 'I')
        return 3;
    else if (token == '*' || token == '/')
        return 2;
    else if (token == '+' || token == '-')
        return 1;
    else
        return 0;
}

void infix_to_postfix(char* postfix) {
    stos stack;
    int postfix_index = 0;
    int i = 0;
    char a;
    cin >> a;
    while (a != '.') {
        if (is_number(a)) {
            postfix[postfix_index++] = a;
            cin >> a;
            while (is_number(a))
            {
                postfix[postfix_index++] = a;
                cin >> a;
            }
            if (a != '.')
                postfix[postfix_index++] = ' ';
            else
                break;
        }
        if (a == '(') {
            stack.dodawanie(a);
        }
        if (a == ')') {
            if (stack.empty()) {
                cout << "Error: Mismatched parentheses" << endl;
                return;
            }
            while (stack.topValue() != '(') {
                postfix[postfix_index++] = stack.topValue();
                stack.usuwanie();
            }
            stack.usuwanie(); // Remove the '(' from the stack
        }
        if (a != '(' && a != ')' && is_number(a) == false){
            int priority = get_priority(a);
            while (!stack.empty() && stack.topValue() != '(' && get_priority(stack.topValue()) >= priority) {
                postfix[postfix_index++] = stack.topValue();
                stack.usuwanie();
            }
            stack.dodawanie(a);
        }
        cin >> a;
    }

    while (!stack.empty()) {
        postfix[postfix_index++] = stack.topValue();
        stack.usuwanie();
    }

    postfix[postfix_index] = '\0'; // Null-terminate the postfix expression
}


int main() {
    const int max_expression_length = 150;;
    char postfix[max_expression_length];
    int number;
    cin >> number;
    for (int i=0;i<number;i++)
    {
        infix_to_postfix(postfix);
        cout << "Postfix Expression: " << postfix << endl;
    }

    return 0;
}
