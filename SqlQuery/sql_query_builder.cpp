#include "sql_query_builder.h"

std::string SqlSelectQueryBuilder::BuildQuery() noexcept
{
    std::string answ("SELECT");
    if (quere.column.empty()) answ += " *";
    else
    {
        for (size_t i(0); i != quere.column.size(); ++i)
        {
            if (i) answ += ',';
            answ += ' ' + quere.column[i];
        }
        quere.column.clear();
    }
    if (!quere.table.empty())
    {
        answ += " FROM " + quere.table;
        quere.table.clear();

        if (!quere.where.empty())
        {
            answ += " WHERE ";
            for (auto it = quere.where.begin(); it != quere.where.end(); ++it)
            {
                if (it != quere.where.begin()) answ += " AND ";
                answ += it->first + '=' + it->second;
            }
            quere.where.clear();
        }
    }

    return answ + ';';
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& col) noexcept
{
    quere.column.push_back(col);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const std::vector<std::string>& col) noexcept
{
    for (const auto& column : col) quere.column.push_back(column);
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& tab) noexcept
{
    quere.table = tab;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& key, const std::string& value) noexcept
{
    quere.where[key] = value;
    return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::unordered_map<std::string, std::string>& kv) noexcept
{
    for (const auto& [key, value] : kv)
    {
        quere.where[key] = value;
    }
    return *this;
}
