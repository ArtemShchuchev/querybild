#pragma once

#include <string>
#include <vector>
#include <unordered_map>

struct Quere
{
    std::string table;
    std::vector<std::string> column;
    std::unordered_map<std::string, std::string> where;
};