#pragma once

#include "quere.h"

class SqlSelectQueryBuilder
{
private:
    Quere quere;

public:
    SqlSelectQueryBuilder() = default;
    std::string BuildQuery() noexcept;
    SqlSelectQueryBuilder& AddColumn(const std::string& col) noexcept;
    SqlSelectQueryBuilder& AddColumns(const std::vector<std::string>& col) noexcept;
    SqlSelectQueryBuilder& AddFrom(const std::string& tab) noexcept;
    SqlSelectQueryBuilder& AddWhere(const std::string& key, const std::string& value) noexcept;
    SqlSelectQueryBuilder& AddWhere(const std::unordered_map<std::string, std::string>& kv) noexcept;
};

