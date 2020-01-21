
#include "DefineVarCommand.h"

#include <utility>
#include <cstring>
#include "SymbolTable.h"
#include "BindingTable.h"
#include "PathsTable.h"
#include "DataReaderServer.h"
#include "Shuntingyard.h"

void DefineVarCommand::execute(const vector<string> &cur_lex) {
    Shuntingyard shuntingyard;
    //skip the word 'var'
    index++;
    string key_word = cur_lex[index];
    index += 2; // skip '='
    if (cur_lex[index].compare("bind")==0||cur_lex[index].compare(" bind")==0) {
        ++index;
        string val = cur_lex[index];
        if (val[1] == '/') { // start of a path
            globalMutex.lock();
            // set value in the table
            val = val.substr(1, val.length() - 2);
            if (PathsTable::instance()->atTable(val)){
                // if the path is in paths table
                BindingTable::instance()->setValue(key_word, val);
                SymbolTable::instance()->setValue(key_word,PathsTable::instance()->getValue(val));
            } else {
                BindingTable::instance()->setValue(key_word, val);
                SymbolTable::instance()->setValue(key_word,0);
            }
            globalMutex.unlock();
        } else {
            globalMutex.lock();
            BindingTable::instance()->setValue(key_word, val);
            SymbolTable::instance()->setValue(key_word,
                                              SymbolTable::instance()->getValue(val));
            BindingTable::instance()->setValue(val, key_word);
            globalMutex.unlock();
        }
    } else {
        string val = cur_lex[index];
        globalMutex.lock();
        //update symbol table
        SymbolTable::instance()->setValue(key_word,shuntingyard.algorithm(shuntingyard.extract_string(val)));
        globalMutex.unlock();
    }
    ++index;
}


DefineVarCommand::DefineVarCommand(int &index):index(index) {
}
