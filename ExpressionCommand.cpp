//
// Created by maor on 29/01/2020.
//

#include "ExpressionCommand.h"

#include <utility>
/**
 *
 * @return the command execution value.
 */
double ExpressionCommand::calculate() {
    command->execute(lexer);
    return 0;
}

/**
 * @param command the command
 * @param words the array of orders.
 */
ExpressionCommand::ExpressionCommand(Command *command, vector<string> cur_lex) : command(
        command), lexer(std::move(cur_lex)){}