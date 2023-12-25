#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include "VariantWrapper.hpp"
#include "Exception.hpp"

#include <string>
#include <unordered_map>
#include <vector>

using ID = int;
using Key = std::string;
using Value = VariantWrapper<std::string, int, double>;
using Map = std::unordered_map<Key, Value>;
using CommandInfo = std::pair<std::string, Map>;

using Point = std::pair<double, double>;
using BoundingBox = std::pair<Point, Point>;

struct CommandTemplate {
    std::string commandName;
    std::vector<std::vector<Key> > mandatoryKeys;
    std::vector<std::vector<Key> > optionalKeys;
};

namespace defs {
    struct NotANumberException : public Exception { using Exception::Exception; };
    struct NotAnIntException : public Exception { using Exception::Exception; };

    std::string toStr(Value val);
    double toDouble (Value val);
    int toInt (Value val);
}

#endif // DEFINITIONS_HPP