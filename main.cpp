
#include <iostream>
#include <strings.h>
#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "MapDB.h"
#include "list"
#include "Lexer.h"
#include "ConnectCommand.h"
#include "Parser.h"
#include "OpenServerCommand.h"
#include <stack>
using namespace std;

/**
 * Initialization of private static vars of the project:
 * (these singletons dont have a cpp file so i do it here)
 */
BindingTable *BindingTable::s_instance = 0; // singleton
SymbolTable *SymbolTable::s_instance = 0; // singleton
PathsTable *PathsTable::s_instance = 0; // singleton

int main(int argc, char **argv) {
    int index =0;
    Lexer lexer;
    vector<string>cur_lex = lexer.split_from_file(argv[1]);
    Parser parser(cur_lex,index);
    //parser.createFunction(words);
    parser.run(cur_lex);
    close(DataReaderServer::getSocketFD());
    close(DataWriterClient::getSocketFD());
    return 0;
}