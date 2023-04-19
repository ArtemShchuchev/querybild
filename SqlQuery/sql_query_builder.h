#pragma once

#include <map>
#include <vector>
#include <chrono>
#include <iostream>

struct Event
{
    std::wstring name;
    std::wstring message;
    std::wstring description;
    int level;
    std::wstring action;
    bool isActive;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    uint8_t ttl;
    std::wstring target;
    std::wstring source;
    std::vector<std::wstring> route;
    std::map<std::wstring, std::wstring> meta;
};


class EventBuilder
{
public:
    explicit EventBuilder(const std::wstring& event_name)
    {
        event.name = event_name;
        event.description = L"This is " + event_name;
        event.timestamp = std::chrono::steady_clock::now();
    }

    Event BuildEvent() noexcept
    {
        if (event.source.empty() && !event.route.empty())
        {
            event.source = event.route.front();
        }
        if (event.target.empty() && !event.route.empty())
        {
            event.target = event.route.back();
        }
        return event;
    }
    EventBuilder& AddLevel(int level) noexcept
    {
        event.level = level;
        return *this;
    }
    EventBuilder& AddMeta(const std::wstring& key, const std::wstring& value)
    {
        event.meta[key] = value;
        return *this;
    }
    EventBuilder& AddRoutePoint(const std::wstring& point)
    {
        event.route.push_back(point);
        return *this;
    }
private:
    Event event;
};

void SendEvent(const Event& e)
{
    std::wcout << L"Sending event " << e.name << L" to " << e.target << L" from " << e.source << std::endl;
    std::wcout << L"route is: \n";
    for (const auto& point : e.route)
    {
        std::wcout << point << L"->";
    }
}

class SqlSelectQueryBuilder
{
};

