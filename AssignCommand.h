
#ifndef FLIGHTSIM_PROJECT_ASSIGNCOMMAND_H
#define FLIGHTSIM_PROJECT_ASSIGNCOMMAND_H

#include "Command.h"
#include "Shuntingyard.h"
#include "BindingTable.h"
#include "DataWriterClient.h"

class AssignCommand : public Command {
    int &index;
public:
    explicit AssignCommand(int &index);

    void execute(const vector<string> &line) override;
};

#endif //FLIGHTSIM_PROJECT_ASSIGNCOMMAND_H
