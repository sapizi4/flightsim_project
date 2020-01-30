#include "BindingTable.h"
#include "SymbolTable.h"
#include "PathsTable.h"
#include "list"
#include "Parser.h"
#include "Main.h"

using namespace std;
using namespace boot;

BindingTable *BindingTable::s_instance = nullptr;
SymbolTable *SymbolTable::s_instance = nullptr;
PathsTable *PathsTable::s_instance = nullptr;

int main(int argc, char *argv[]) {
    Main *run = new Main();
    boot::Main::main(argc, argv);
    delete (run);
    return 0;
}
