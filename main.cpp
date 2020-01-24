#include <iostream>
#include <strings.h>
#include "Tables/BindTable.h"
#include "Tables/SymbolTable.h"
#include "Tables/PathsTable.h"
#include "list"
#include "Interpeter/Lexer.h"
#include "Commands/ConnectCommand.h"
#include "Interpeter/Parser.h"
#include "Commands/OpenServerCommand.h"
#include <stack>
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "MatrixSearchable.h"
#include "Searcher.h"
#include "MatrixSolver.h"
#include "BestFirstSearch.h"
#include "A_Star.h"
#include "MyParallerServer.h"
#include "Main.h"

#include <iostream>
using namespace std;
using namespace boot;

BindTable *BindTable::s_instance = 0;
SymbolTable *SymbolTable::s_instance = 0;
PathsTable *PathsTable::s_instance = 0;


int main(int argc, char **argv) {
    Main* run = new Main();
    run->main(argc, argv);
    delete (run);
}