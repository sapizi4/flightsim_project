#include "SleepCommand.h"
#include "Shuntingyard.h"


void SleepCommand::execute(const vector<string> &cur_lex) {
    Shuntingyard shuntingyard;
    ++index;
    this_thread::sleep_for(std::chrono::milliseconds(
            (int)shuntingyard.algorithm(shuntingyard.extract_string(cur_lex[index]))));
    ++index;
}

SleepCommand::SleepCommand(int &index):index(index) {

}