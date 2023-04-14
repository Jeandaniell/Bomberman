/*
** EPITECH PROJECT, 2022
** init.cpp
** File description:
** init
*/

#include "init.hpp"

bool init::if_collision(std::vector<std::string> map, float x, float y)
{
    std::size_t li = 0, co = 0;
    float w = (-10 * 14), h = (-10 * 14);
    for (; li < map.size(); li++,h += 14) {
        w = (-10 * 14);
        for (co = 0; co < map[li].size(); co++) {
            if ((x <= w + 7 && x >= w - 7) && (y <= h + 7 && y >= h - 7) && map[li][co] != '#' && map[li][co] != 'c')
                return false;
            w += 14;
        }
    }
    return (true);
}

void init::collision_player1(std::vector<std::string> map)
{
    anim_plus1 = 1;

    if (IsKeyDown(KEY_RIGHT)) {
        anim_plus1 = 0;
        a3 = 180.0f;
        if (!if_collision(map, a1 + 1.0, a2))
            a1 += 1.0;
    }
    if (IsKeyDown(KEY_LEFT)) {
        anim_plus1 = 0;
        a3 = 0.0f;
        if (!if_collision(map, a1 - 1.0, a2))
            a1 -= 1.0;
    }
    if (IsKeyDown(KEY_UP)) {
        anim_plus1 = 0;
        a3 = 270.0f;
        if (!if_collision(map, a1, a2 - 1.0))
            a2 -= 1.0;
    }
    if (IsKeyDown(KEY_DOWN)) {
        anim_plus1 = 0;
        a3 = 90.0f;
        if (!if_collision(map, a1, a2 + 1.0))
            a2 += 1.0;
    }
}

void init::collision_player2(std::vector<std::string> map)
{
    anim_plus2 = 1;

    if (IsKeyDown(KEY_D)) {
        anim_plus2 = 0;
        y3 = 180.0f;
        if (!if_collision(map, y1 + 1.0, y2))
            y1 += 1.0;
    }
    if (IsKeyDown(KEY_A)) {
        anim_plus2 = 0;
        y3 = 0.0f;
        if (!if_collision(map, y1 - 1.0, y2))
            y1 -= 1.0;
    }
    if (IsKeyDown(KEY_W)) {
        anim_plus2 = 0;
        y3 = 270.0f;
        if (!if_collision(map, y1, y2 - 1.0))
            y2 -= 1.0;
    }
    if (IsKeyDown(KEY_S)) {
        anim_plus2 = 0;
        y3 = 90.0f;
        if (!if_collision(map, y1, y2 + 1.0))
            y2 += 1.0;
    }
}