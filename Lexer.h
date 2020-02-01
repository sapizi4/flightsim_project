//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_LEXER_H
#define FLIGHTSIM_LEXER_H

#define SPECIAL_OPERATOR {"+","-","*","/", "\"","<",">","<=",">=","=="}

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#define SEPARATOR " "
#define ASSERTSEPAR "="



using namespace std;

class Lexer{
    string toCut;
    vector<string> cur_lex;

public:
    Lexer()= default;
    static bool isOperator(string & c);
    static vector<string>split_from_file(const string& fileName);
    vector<string>split_from_command_line();
    //vector<string>fromStringToExp(vector<string> commands);
    vector<string> get_lexer();

    static vector<string> fromStringToExp(const vector<string> &commands);
};

#endif //FLIGHTSIM_LEXER_H
