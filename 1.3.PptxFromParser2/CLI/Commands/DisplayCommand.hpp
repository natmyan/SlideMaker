#ifndef DISPLAY_COMMAND_EXECUTOR_HPP
#define DISPLAY_COMMAND_EXECUTOR_HPP

#include "Command.hpp"

class DisplayCommand : public Command {
    public:
        void execute (CommandType parsedCmd, std::shared_ptr<Document> doc, std::shared_ptr<Director> dir);
};

#endif // DISPLAY_COMMAND_EXECUTOR_HPP