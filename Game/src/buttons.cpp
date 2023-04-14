/*
** EPITECH PROJECT, 2022
** init.cpp
** File description:
** init
*/

#include "init.hpp"

void init::buttons(void)
{
    butt1 = {50, 150, 70, 50};
    butt2 = {100, 250, 70, 50};
    butt3 = {150, 350, 140, 50};
    butt4 = {250, 450, 70, 50};
    butt5 = {900, 550, 70, 50};
    butt_r_game = {450, 200, 100, 45};
    butt_r_menu = {460, 280, 95, 45};
    butt_r_quit = {465, 370, 60, 45};
    butt_go_back = {25, 530, 60, 45};
    butt_go_right = {950, 540, 20, 40};
    butt_go_right_one = {950, 500, 20, 40};
    butt_go_left = {900, 500, 20, 40};
    butt_go_left_one = {920, 560, 20, 40};
    title = "Bomberman";
    butt_play = "Play";
    butt_help = "Help";
    butt_opts = "Settings";
    butt_quit = "Quit";
    butt_skip = "_Skip_";
    s_menu = "Menu";
    s_game = "Return";
    s_quit = "Quit";
    go_back = "_back_";
    go_right = "->";
    go_left = "<-";
    str_time = "Time :     :";
}

void init::myHelp(void)
{
    StopSound(sound);
    myLoop(sound_help);
    DrawTexture(text_how1, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_back)) {
        DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            StopSound(sound_help);
            v = 0;
        }
    }
    else DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_right)) {
        DrawTextEx(font6, go_right.c_str(), {950, 540}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            r1 = 1;
        }
    }
    else DrawTextEx(font6, go_right.c_str(), {950, 540}, 50, 2, WHITE);
    if (r1 == 1) GoRight_one();
}

void init::GoRight_one(void)
{
    DrawTexture(text_how2, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_back)) {
        DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            v = 0;
        }
    }
    else DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_right_one)) {
        DrawTextEx(font6, go_right.c_str(), {950, 500}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            r2 = 1;
        }
    }
    else DrawTextEx(font6, go_right.c_str(), {950, 500}, 50, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_left)) {
        DrawTextEx(font6, go_left.c_str(), {900, 500}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            r1 = 0; }
    }
    else DrawTextEx(font6, go_left.c_str(), {900, 500}, 50, 2, WHITE);
    if (r2 == 1) GoRight_two();
}

void init::GoRight_two(void)
{
    DrawTexture(text_how3, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_back)) {
        DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            v = 0; }
    }
    else DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_left_one)) {
        DrawTextEx(font6, go_left.c_str(), {920, 560}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            r2 = 0; }
    }
    else DrawTextEx(font6, go_left.c_str(), {920, 560}, 50, 2, WHITE);
}