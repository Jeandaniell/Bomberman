/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "init.hpp"

std::vector<std::string> init::map_generator(std::size_t li, std::size_t co)
{
    std::vector<std::string> vec;
    vec.assign(li, "");
    std::size_t m = 0;
    std::size_t i = 0;

    std::srand(time(NULL));
    for (m = 0; m < li; m++)
        vec[m].assign(co, '*');
    for (m = 0; m < li; m += 2) {
        for (i = 0; i < vec[m].size(); i++) {
            int ma = std::rand() % 3;
            if (ma == 0)
                vec[m][i] = '#';
            if (ma == 1)
                vec[m][i] = '*';
            if (ma == 2)
                vec[m][i] = 'c';
        }
    }
    for (i = 0; i < co; i++) {
        vec[0][i] = '#';
        vec[li - 1][i] = '#';
    }
    for (m = 0; m < li; m++) {
        vec[m][0] = '#';
        vec[m][co - 1] = '#';
    }
    for (std::size_t x = 1; x < co - 1; x++) {
        vec[1][x] = '*';
        vec[18][x] = '*';
    }
    bool ok = false;
    int ex = 0;
    int ey = 0;
    pos1_x = -140;
    pos1_y = -140;
    while (!ok) {
        ex = std::rand() % co;
        ey = std::rand() % li;
        for (size_t e = ey; (e < vec.size() && ok == false); e++) {
            for (size_t f = ex; (f < vec[e].size() && ok == false); f++) {
                if (vec[e][f] == '*') {
                    for (size_t g = 0; g < e; g++) pos1_y += 14;
                    for (size_t g = 0; g < f; g++) pos1_x += 14;
                    ok = true;
                }
            }
        }
    }
    ok = false;
    pos2_x = -140;
    pos2_y = -140;
    while (!ok) {
        ex = std::rand() % co;
        ey = std::rand() % li;
        for (size_t e = ey; (e < vec.size() && ok == false); e++) {
            for (size_t f = ex; (f < vec[e].size() && ok == false); f++) {
                if (vec[e][f] == '*') {
                    for (size_t g = 0; g < e; g++) pos2_y += 14;
                    for (size_t g = 0; g < f; g++) pos2_x += 14;
                    ok = true;
                }
            }
        }
    }
    return (vec);
}

void init::display_map(std::vector<std::string> map)
{
    std::size_t li = 0, co = 0;
    float b1 = 0, b2 = 0;

    for (b2 = (-10 * 14); li < map.size(); li++, b2+= 14) {
        for (b1 = (-10 * 14), co = 0; co < map[li].size(); co++, b1+= 14) {
            if (map[li][co] == '#')
                DrawModel(model1, { b1, 10.0f, b2 }, 0.1f, WHITE);
            if (map[li][co] == '*')
                DrawModel(model, { b1, 1.0f, b2 }, 0.1f, WHITE);
            if (map[li][co] == 'c')
                DrawModel(model2, { b1, 10.0f, b2 }, 0.1f, WHITE);
        }
    }
}