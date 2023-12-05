#ifndef PARSER_8_HPP
#define PARSER_8_HPP

#include "Command.hpp"

#include <istream>

class Parser8 {
    public:
        CommandInfo constructCommandInfo(std::istream& input, const char& endOfLineToken);
        std::shared_ptr<Command> constructCommand();
    
    private:
        bool isCmdInfoValid();
    
    private:
        CommandInfo cmdInfo_;
};

#endif // PARSER_8_HPP