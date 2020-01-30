#include <mutex>
#include "AssignCommand.h"
#include "DataReaderServer.h"
#include "SymbolTable.h"


AssignCommand::AssignCommand( int &index) : index(index){}

void AssignCommand::execute(const vector<string> &cur_lex) {
    mutex globalMutex;
    Shuntingyard shuntingyard;
    string key = cur_lex[index];
    if(key=="{"){
        key = cur_lex[index+1];
        index++;
    }
    index += 2; // skip key and '='
    double val = Shuntingyard::algorithm(Shuntingyard::extract_string(cur_lex[index]));
    globalMutex.lock();
    SymbolTable::instance()->setValue(key,val);
    if (BindingTable::instance()->getValue(key)[0] == '/'){
        const string msg = "set " + BindingTable::instance()->getValue(key) +
                           " " + to_string(val) + "\r\n";
        globalMutex.unlock();
        DataWriterClient::setMessage(msg);
    } else {
        SymbolTable::instance()->setValue(BindingTable::instance()->getValue(key), val);
        globalMutex.unlock();
    }
    ++index;
}
