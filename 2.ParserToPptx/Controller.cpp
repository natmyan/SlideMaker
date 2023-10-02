#include "Controller.hpp"

#include <iostream>

void Controller::run() {
    while (true) {
        InputReader inputReader;

        char endOfLineToken = '\n';
        // inputReader.readInputLine(std::cin, endOfLineToken); // yikes

        Parser4 parser;
        auto command = parser.parseCommand(std::cin, endOfLineToken);

        if (std::holds_alternative<CommandType>(command)) {
            CommandType cmd = std::get<CommandType>(command);
            CommandValidator validator;

            if (validator.isCommandValid(cmd)) {
                std::string cmdName = std::get<1>(cmd);
                CommandExecutorFactory execFactory;
                std::unique_ptr<CommandExecutor> executor = execFactory.createCommandExecutor(cmdName);

                if (executor == nullptr) {
                    std::string errorMsg = "wrong_command_2";
                    /// TODO: parser checks for the right command, there should be no need for this
                    Printer printer;
                    printer.printErrorMsg (errorMsg);
                }
                else {
                    executor->execute(cmd);
                }
            }
        }
        else if (std::holds_alternative<std::string>(command)) {
            std::string errorMsg = std::get<std::string>(command);
            Printer printer;
            printer.printErrorMsg (errorMsg);
        }
        
    }
}