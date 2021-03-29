#include <set>
#include <functional>
#include <string>
#include <map>

#pragma once

namespace events {
    class EventId {
    private:
        std::string name = "";

        int nameHash = std::hash<std::string>{}("");

    public:
        EventId() = default;

        EventId(std::string name) : name(name) {
            nameHash = std::hash<std::string>{}(name);
        }

        bool operator==(const EventId& eId) const {
            return nameHash == eId.nameHash && name == eId.name;
        }

        bool operator!=(const EventId& eId) const {
            return !operator==(eId);
        }
    };

    class EventData { // may be changed
    private:
        using T = int;

        std::map<std::string, T> data;

    public:
        EventData() {}

        void setField(const std::string& key, const T& value) {
            data[key] = value;
        }

        const T& getField(const std::string& key) {
            return data[key];
        }
    };

    class Event {
    private:
        EventId id;

        EventData data;

    public:
        Event(const EventId& id, const EventData& data) :
            id(id), data(data) {}

        bool isId(const EventId& eId) const {
            return id == eId; 
        }

        EventData& getData() {
            return data;
        }

        const EventData& getData() const {
            return data;
        }
    };

    class EventHandler {
    private:
        std::function<void(const EventData&)> handler;

        EventId eventId;
    public:
        EventHandler(std::function<void(const EventData&)> handler,
            const EventId& eventId) : handler(handler), eventId(eventId) {}
            
        bool handleEvent(const Event& event) {
            if (event.isId(eventId)) {
                handler(event.getData());
                return true;
            }
            return false;
        }
    };

    class EventCenter {
    private:
        std::set<EventHandler> handlers;
    public:
        void addEventHandler(const EventHandler& handler) {
            handlers.insert(handler);
        }

        void removeEventHandler(const EventHandler& handler) {
            handlers.erase(handler);
        }

        void invokeEvent(const Event& event) {
            for (auto handler : handlers) {
                handler.handleEvent(event);
            }
        }
    };
}