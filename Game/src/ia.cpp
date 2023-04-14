/*
** EPITECH PROJECT, 2022
** init.cpp
** File description:
** init
*/

#include "init.hpp"

void init::ia(std::vector<std::string> map)
{
    std::string str;
    char c;

    if (my_ia(map) == 1) return;
    if (!if_collision(map, pos1_x + 1.0, pos1_y)) str.push_back('r');
    if (!if_collision(map, pos1_x - 1.0, pos1_y)) str.push_back('l');
    if (!if_collision(map, pos1_x, pos1_y - 1.0)) str.push_back('u');
    if (!if_collision(map, pos1_x, pos1_y + 1.0)) str.push_back('d');
    c = str[std::rand() % str.size()];
    if (c == 'r') {
        pos1_a = 180.0f;
        pos1_x += 1.0;}
    if (c == 'l') {
        pos1_a = 0.0f;
        pos1_x -= 1.0;}
    if (c == 'u') {
        pos1_a = 270.0f;
        pos1_y -= 1.0;}
    if (c == 'd') {
        pos1_a = 90.0f;
        pos1_y += 1.0;}
}

void init::ia2(std::vector<std::string> map)
{
    std::string str;
    char c;

    if (my_ia2(map) == 1) return;
    if (!if_collision(map, pos2_x + 1.0, pos2_y)) str.push_back('r');
    if (!if_collision(map, pos2_x - 1.0, pos2_y)) str.push_back('l');
    if (!if_collision(map, pos2_x, pos2_y - 1.0)) str.push_back('u');
    if (!if_collision(map, pos2_x, pos2_y + 1.0)) str.push_back('d');
    c = str[std::rand() % str.size()];
    if (c == 'r') {
        pos2_a = 180.0f;
        pos2_x += 1.0;}
    if (c == 'l') {
        pos2_a = 0.0f;
        pos2_x -= 1.0;}
    if (c == 'u') {
        pos2_a = 270.0f;
        pos2_y -= 1.0;}
    if (c == 'd') {
        pos2_a = 90.0f;
        pos2_y += 1.0;}
}

int init::my_ia(std::vector<std::string> map)
{
    if (pos1_a == 180.0f && !if_collision(map, pos1_x + 1.0, pos1_y)) {
        pos1_x += 1.0;
        return 1; }
    if (pos1_a == 0.0f && !if_collision(map, pos1_x - 1.0, pos1_y)) {
        pos1_x -= 1.0;
        return 1; }
    if (pos1_a == 270.0f && !if_collision(map, pos1_x, pos1_y - 1.0)) {
        pos1_y -= 1.0; 
        return 1; }
    if (pos1_a == 90.0f && !if_collision(map, pos1_x, pos1_y + 1.0)) {
        pos1_y += 1.0;
        return 1; }
    return 0;
}

int init::my_ia2(std::vector<std::string> map)
{
    if (pos2_a == 180.0f && !if_collision(map, pos2_x + 1.0, pos2_y)) {
        pos2_x += 1.0;
        return 1; }
    if (pos2_a == 0.0f && !if_collision(map, pos2_x - 1.0, pos2_y)) {
        pos2_x -= 1.0;
        return 1; }
    if (pos2_a == 270.0f && !if_collision(map, pos2_x, pos2_y - 1.0)) {
        pos2_y -= 1.0; 
        return 1; }
    if (pos2_a == 90.0f && !if_collision(map, pos2_x, pos2_y + 1.0)) {
        pos2_y += 1.0;
        return 1; }
    return 0;
}