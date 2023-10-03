#ifndef COMMAND_EXECUTOR_HPP
#define COMMAND_EXECUTOR_HPP

#include "Parser4.hpp"
#include "CommandValidator.hpp"

using ID = int;

class CommandExecutor {
    public:
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~CommandExecutor() = default;

    protected:
        // static std::vector<std::tuple<ID, std::variant<bool, std::map<std::string, ArgumentType> > > > itemStorage_;
        static std::vector<std::tuple<ID, std::map<std::string, ArgumentType> > > itemStorage_;
        static int id_;
};

#endif // COMMAND_EXECUTOR_HPP