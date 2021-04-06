#include <vector>
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

        const EventId& getEventId() const {
            return id; 
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
        
        static size_t lastId;
        
        size_t id;

        EventId eventId;
    public:
        EventHandler(std::function<void(const EventData&)> handler,
            const EventId& eventId) : handler(handler), eventId(eventId) {
            id = lastId;
            ++lastId;
        }
            
        void handleEvent(const Event& event) {
            handler(event.getData());
        }
        
        size_t getId() const {
            return id;
        }
        
        const EventId& getEventId() const {
            return eventId;
        }
    };

    class EventCenter {
    private:
        std::map<EventId, std::vector<EventHandler>> handlers;
    public:
        void addEventHandler(const EventHandler& handler) {
            handlers[handler.getEventId()].push_back(handler);
        }

        void removeEventHandler(const EventHandler& handler) {
            std::vector<EventHandler>& v = handlers[handler.getEventId()];
            size_t id = handler.getId();
            for (size_t i = 0; i < v.size(); ++i) {
                if (v[i].getId() == id) {
                    if (i + 1 != v.size()) {
                        std::swap(v[i], v.back());
                    }
                    v.pop_back();
                }
            }
        }

        void invokeEvent(const Event& event) {
            for (auto& handler : handlers[event.getEventId()]) { // is it really work ??
                handler.handleEvent(event);
            }
        }
    };
}
