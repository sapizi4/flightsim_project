//
// Created by maor on 29/01/2020.
//

#include "ConditionParser.h"
#include "Lexer.h"
#include "Shuntingyard.h"

/**
 * @param line the words
 */
void ConditionParser::execute(const vector<string> &cur_lex) {

}

ConditionParser::ConditionParser(int &index):index(index) {
}

/**
 * @param oper the string.
 * @return 1 if the string is operator, 0 otherwise.
 */
bool ConditionParser::isOperator(const string &oper) {
    return (oper == ">" || oper == ">=" || oper == "==" || oper == "!=" ||
            oper == "<" || oper == "<=");
}

bool ConditionParser::checkCondition(const vector<string>&cur_lex) {
    ++index;
    Shuntingyard shuntingyard;
    double left = Shuntingyard::algorithm(Shuntingyard::extract_string(cur_lex[index]));
    ++index;
    string oper = cur_lex[index];
    if(cur_lex[index+1][0]=='='){
        oper+='=';
    }
    if(!isOperator(oper)){
        perror("this is not an operator");
        exit(1);
    }
    ++index;
    double  right = Shuntingyard::algorithm(Shuntingyard::extract_string(cur_lex[index]));
    ++index;
    if(oper==">"){
        return isBigger(left,right);
    }else if(oper=="<"){
        return isBigger(right,left);
    }else if(oper==">="){
        return isBigger(left,right)||isEqual(left,right);
    }else if(oper=="<="){
        return isBigger(right,left)||isEqual(left,right);
    }else if(oper=="=="){
        return isEqual(left,right);
    }else if(oper=="!="){
        return !isEqual(left,right);
    }
    return false;
}

bool ConditionParser::isBigger(double left, double right) {
    return left>right;
}

bool ConditionParser::isEqual(double left, double right) {
    return left == right;
}