#include <cassert> // для assert()
#include "SecondaryFunction.h"
#include "sql_query_builder.h"

int main(int argc, char** argv)
{
	printHeader(L"Домашнее задание к занятию «Порождающие шаблоны»");
    
    SqlSelectQueryBuilder query_builder;

    std::wcout << L"Задача 1: ";
    query_builder.AddFrom("students");
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    std::string answer = query_builder.BuildQuery();
    assert(answer == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    std::wcout << L"выполнена!\n";
    std::wcout << utf2wide(answer) << '\n';

    ////////////////////////////////
    
    std::wcout << L"Задача 2: ";
    query_builder.AddFrom("students");
    query_builder.AddColumns({ "name", "phone" });
    query_builder.AddWhere({ { "id", "42" }, { "name", "John" } });

    answer = query_builder.BuildQuery();
    assert(answer == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
    std::wcout << L"выполнена!\n";
    std::wcout << utf2wide(answer) << '\n';
	
	std::wcout << "\n";
	return 0;
}
