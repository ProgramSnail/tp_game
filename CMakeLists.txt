cmake_minimum_required(VERSION 3.10)

project(Game)

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(GameSource src/main.cpp)

set(OutApiSource
        src/out_api/draw.cpp
        src/out_api/game_draw.cpp
        src/out_api/init.cpp
        src/out_api/input_controller.cpp
        src/out_api/input.cpp
        src/out_api/menu_draw.cpp)

set(MenuSource 
        src/menu/menu.cpp)

set(GameMainSource
        src/game/game_events.cpp
        src/game/game_map.cpp
        src/game/game_menu.cpp)

set(GameUnitSource
        src/game/unit/module_builder.cpp
        src/game/unit/unit_builder.cpp
        src/game/unit/unit_module.cpp
        src/game/unit/unit.cpp)

set(GameMapEntitiesSource
        src/game/map_entities/cell.cpp
        src/game/map_entities/unit_obj.cpp
        src/game/map_entities/actions/attack_action.cpp)

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