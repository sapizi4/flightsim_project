
#include "LoopCommand.h"
#include "SymbolTable.h"

void LoopCommand::execute(const vector<string> &cur_lex) {
    first_iteration = true;
    int firstIndex= index;
    int startprogram;
    while(conditionParser.checkCondition(cur_lex)) {
        startprogram = index;
        if (first_iteration) {
            commands_in_loop(cur_lex, index);
            index = startprogram;
            first_iteration = false;
        }
        for (auto const &command:commands) command->calculate();
        index = firstIndex;
    }
}

void LoopCommand::commands_in_loop(const vector<string> cur_lex, int &index) {
    commands.clear();
    //until while didnt ends
    while (cur_lex[index] != "}") {
        if(cur_lex[index] == "{") {
            index++;
        }
        else if (cur_lex[index] == "var") {
            commands.push_back(command_map["var"]);
            if (cur_lex[index + 3] == " bind") index += 5;
            else index += 4;
        }
        else if (this->command_map.find(cur_lex[index]) == command_map.end()) {
            commands.push_back(command_map["assign"]);
            index += 3;
        } else if (cur_lex[index] == "if") {
            commands.push_back(command_map["if"]);
            while(cur_lex[index]!= "}") index++;
            index++;
        }
        else if (cur_lex[index] == "while") {
            commands.push_back(command_map["while"]);
            while(cur_lex[index]!= "}") index++;
            index++;
        }
        else if  (this->command_map.find(cur_lex[index]) != command_map.end()) {
            commands.push_back(command_map[cur_lex[index]]);
            index += 2;
        }
    }

}

LoopCommand::LoopCommand(map<string,Expression*>&command_map,int &index) : command_map(command_map),
                                                                           index(index),conditionParser(this->index) {


}