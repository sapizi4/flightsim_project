
#include <stack>
#include <iostream>
#include "Shuntingyard.h"
#include "DataReaderServer.h"

using namespace std;

Shuntingyard::Shuntingyard() {

}

unsigned int Shuntingyard::precedence(char op) {
    switch(op) {
        case '-': case '+':
            return 1;
        case '*': case '/':
            return 2;
        default:
            return 0;
    }
}

bool Shuntingyard::isDigit(char c){ //checks if the char is a digit
    if(((c >= 48) && (c <= 57)) || (c == '.')){
        return true;
    }else {
        return false;
    }
}

bool Shuntingyard::isOperator(char c){ //checks if the char is an operator
    if((c == '+') || (c == '-') || (c == '/') || (c == '*')) {
        return true;
    }else {
        return false;
    }
}




double Shuntingyard:: algorithm(string exp){
    string output = "";
    vector<string>nums;
    vector<string>str_vec;
    stack<string> operators;
    char last= '$';

    //while there is something to read.
    while(!exp.empty()) {
        char c = exp[0];
        exp.erase(0,1); //erase the first character.

        string token;
        token +=c;
        if(isDigit(c)) {//the character is a digit.
            output.append(token); //add the digit to the queue.
        }
        else if(c == '(') { //the character is a (
            operators.push(token);
            if((!last == '$')){//there was something before the (
                nums.push_back(output);
            }
        } else if(c == ')') { //the character is a )
            nums.push_back(output);
            string lastop = operators.top();
            char lastoperator = lastop[0];
            while(lastoperator != '('){
                operators.pop();
                output.append(lastop);
                lastop = operators.top(); //go to the next operator in the stack.
                lastoperator = lastop[0];
            }
            if(lastoperator == '('){
                operators.pop();
            }

        }  else if(isOperator(c)){ //the character c is an operator.
            if(c == '-'){//check if an operator or negative.
                if((last == '$') || (isOperator(last)) || (last == '(')){
                    output.append(token); //push the negative into the queue
                }
            }else {
                if (operators.empty()) {
                    operators.push(token);
                    nums.push_back(output);
                    output="";
                } else {
                    while ((!operators.empty()) && (isOperator(operators.top()[0]))) { //while we have an operator in the stack, check precedence.
                        if ((precedence(operators.top()[0])) >
                            (precedence(c))) { //there is an operator in the stack with precedence.
                            string op;
                            op += operators.top()[0];
                            nums.push_back(output);
                            output="";
                            output.append(op); //push to the queue.
                            nums.push_back(op); //push the operator to the queue.
                            output="";
                            operators.pop(); //pop the operator.
                        } else {
                            break;
                        }
                    }
                    operators.push(token); //push the new operator to the stack.
                }
            }
        }
        last = c;//remember the last char.
    }
    //there is nothing else in the string.
    while(!operators.empty()) {//while the stack is not empty.
        if(operators.top() == "(" || operators.top() == ")")
            throw invalid_argument("invalid_arg");
        else {
            nums.push_back(output);
            output="";
            for(auto str:nums){
                str_vec.push_back(str);
            }
            str_vec.push_back(operators.top());
            operators.pop();
        }
    }
    return string_to_exp(str_vec)->calculate();//the new expression

}

Shuntingyard::~Shuntingyard() {

}

string Shuntingyard::extract_string(const string &str) {
    const char *pExp = str.c_str();
    string newExp;
    string var;
    while (*pExp) {
        if (*pExp == '(' || *pExp == ')' || isDigit(*pExp) || isOperator(*pExp) || *pExp == ' ') {
            newExp += *pExp;
            ++pExp;
        } else {
            while (!(*pExp == '(' || *pExp == ')' || isOperator(*pExp) || *pExp == ' ') && *pExp) {
                var += *pExp;
                ++pExp;
            }
            globalMutex.lock();
            var = to_string(SymbolTable::instance()->getValue(var));
            var.erase ( var.find_last_not_of('0') + 1, std::string::npos ); // erase trailing zeros
            if(var.find('.') == var.length() - 1) var = var.substr(0, var.length() - 1);
            if (newExp.length() > 0 && newExp[newExp.length() - 1] == '-' && var[0] == '-')
                var = var.substr(1, var.length() - 1);
            newExp += var;
            globalMutex.unlock();
            var = "";
        }
    }
    return newExp;
}

Expression *Shuntingyard::string_to_exp(vector<string> shunt_vec) {
    char oper;
    stack<Expression *> stack;
    Expression *newExp;
    for (auto str :shunt_vec) {
        if (!isOperator(str[0]) || (isOperator(str[0]) && str.size() != 1)) {
            newExp = new Number(stof(str));
            stack.push(newExp);

        } else {
            Expression *right = stack.top();
            stack.pop();
            Expression *left = stack.top();
            stack.pop();
            switch (str[0]) {
                case '+':
                    newExp = new Plus(left, right);
                    stack.push(newExp);
                    break;
                case '-':
                    newExp = new Minus(left, right);
                    stack.push(newExp);
                    break;
                case '/':
                    newExp = new Div(left, right);
                    stack.push(newExp);
                    break;
                case '*':
                    newExp = new Mul(left, right);
                    stack.push(newExp);
                    break;
            }

        }
    }
    Expression *result = stack.top();
    return result;
}

bool Shuntingyard::check_if_neg(const string &exp) {
    bool check = false;
    const char *c = exp.c_str();
    // if there is no '-' in the number
    if(c[0]!= '-') return false;
    // while the end of the number
    while(*c!= '\0' ){
        // check if the sign '-' shows once.
        if(*c == '-' && !check) check = true;
        else
            // if there is more things in the string, return false.
        if(isOperator(*c) && check) return false;
        c++;
    }
    return true;
}
