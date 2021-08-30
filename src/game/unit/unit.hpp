#include <vector>
#include "../game_map.hpp"
#include "../game_events.hpp"
#include "unit_module.hpp"
#include "../map_entities/unit_obj.hpp"

#pragma once

namespace unit {
    class UnitFactory;

    class Unit {
    private:
        friend class UnitFactory;

        int basicStrength;
        int strength;
        int shield;
        int speed;
        int player;
        int cellType;

        map::UnitObj unitObj;
        
        map::GameMap* gameMap = nullptr;

        events::EventCenter* eventCenter = nullptr;

        void setCellType(int newCellType) {
            cellType = newCellType;
            unitObj.setCellType(cellType);
        }
    public:
        Unit() = default;

        Unit(map::GameMap* gameMap, events::EventCenter* eventCenter);

        void step();

        void damage(int damage, int power);

        bool isDestroyed() {
            return strength <= 0;
        }

        void setPlayer(int newPlayer) {
            player = newPlayer;
            unitObj.setPlayer(player);
        }
    };

    class UnitFactory {
    private:
        Unit unit;
    public:
        UnitFactory() = default;

        UnitFactory& setBasicStrength(int basicStrength) {
            unit.basicStrength = basicStrength;
            unit.strength = basicStrength;
            return *this;
        }

        UnitFactory& setShield(int shield) {
            unit.shield = shield;
            return *this;
        }

        UnitFactory& setSpeed(int speed) {
            unit.speed = speed;
            return *this;
        }

        UnitFactory& setCellType(int cellType) {
            unit.setCellType(cellType);
            return *this;
        }

        UnitFactory& setEventCenter(events::EventCenter* eventCenter) {
            unit.eventCenter = eventCenter;
            return *this;
        }

        UnitFactory& setGameMap(map::GameMap* gameMap) {
            unit.gameMap = gameMap;
            return *this;
        }

        Unit build(int player) {
            Unit cp = unit;
            cp.setPlayer(player);
            return cp;
        }
    };
}
