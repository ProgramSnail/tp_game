cmake_minimum_required(VERSION 3.10)

project(Game)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(GameSource main.cpp)

set(OutApiSource
        out_api/draw.cpp
        out_api/game_draw.cpp
        out_api/init.cpp
        out_api/input_controller.cpp
        out_api/input.cpp
        out_api/menu_draw.cpp)

set(MenuSource 
        menu/menu.cpp)

set(GameMainSource
        game/game_events.cpp
        game/game_map.cpp
        game/game_menu.cpp)

set(GameUnitSource
        game/unit/module_builder.cpp
        game/unit/unit_builder.cpp
        game/unit/unit_module.cpp
        game/unit/unit.cpp)

set(GameMapEntitiesSource
        game/map_entities/cell.cpp
        game/map_entities/unit_obj.cpp
        game/map_entities/actions/attack_action.cpp)

add_library(OutApi ${OutApiSource})
add_library(Menu ${MenuSource})
add_library(GameMain ${GameMainSource})
add_library(GameUnit ${GameUnitSource})
add_library(GameMapEntities  ${GameMapEntitiesSource})

set(LIBS
        OutApi
        Menu
        GameMain
        GameUnit
        GameMapEntities)

add_executable(Game ${GameSource})
target_link_libraries(Game ${CURSES_LIBRARIES})
target_link_libraries(Game ${LIBS})