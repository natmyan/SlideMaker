#ifndef ACTION_TAKER_HPP
#define ACTION_TAKER_HPP

#include "../CmdLineInterface/CommandFactory.hpp"

class ActionTaker {
    public:
        void execute (CommandType parsedCmd);
};

#endif // ACTION_TAKER_HPP