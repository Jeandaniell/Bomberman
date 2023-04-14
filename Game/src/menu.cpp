/*
** EPITECH PROJECT, 2022
** map
** File description:
** map
*/

#include "init.hpp"

void init::menu(void)
{
    index = 66;
    StopSound(music);
    myLoop(sound);
    DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    DrawTexture(text_act, 700, 100, WHITE);
    DrawTextEx(font4, title.c_str(), {330,20}, 70, 2, YELLOW);
    if (CheckCollisionPointRec(pos, butt1)) {
        DrawTextEx(font2, butt_play.c_str(), {50, 150}, 50, 2, BLACK);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            fa = 2;
        }
    } else
        DrawTextEx(font2, butt_play.c_str(), {50, 150}, 45, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt2)) {
        DrawTextEx(font2, butt_help.c_str(), {100, 250}, 50, 2, BLACK);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            v = 1;
        }
    }
    else
        DrawTextEx(font2, butt_help.c_str(), {100, 250}, 45, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt3)) {
        DrawTextEx(font2, butt_opts.c_str(), {150, 350}, 50, 2, BLACK);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            q = 1;
        }
    }
    else
        DrawTextEx(font2, butt_opts.c_str(), {150, 350}, 45, 2, WHITE);
    if (CheckCollisionPointRec(pos, butt4)) {
        DrawTextEx(font2, butt_quit.c_str(), {250, 450}, 50, 2, BLACK);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            ma = 1;
        }
    } else
        DrawTextEx(font2, butt_quit.c_str(), {250, 450}, 45, 2, WHITE);
    if (ma == 1) {
        CloseWindow();
        exit (0);
    }
    if (v == 1) myHelp();
    if (q == 1) mySets();
}

void init::myGame(void)
{
    StopSound(sound);
    myLoop(sound_game);
    DrawTexture(bck_sprite, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    DrawTexture(text_score, -120, 50, WHITE);
    DrawTextEx(font6, std::to_string(scr).c_str(), {85, 110}, 25, 2, WHITE);
    DrawTextEx(font6, str_time.c_str(), {800, 5}, 45, 2, WHITE);
    DrawTextEx(font6, std::to_string(my_null).c_str(), {895, 5}, 45, 2, WHITE);
    DrawTextEx(font6, std::to_string(int_minutes).c_str(), {910, 5}, 45, 2, WHITE);
    DrawTextEx(font6, std::to_string(int_seconds).c_str(), {950, 5}, 45, 2, WHITE);
    BeginMode3D(camera);
    display_map(map);
    DrawModelEx(model_perso1, { a1, 13.0, a2 }, { 0.0f, 1.0f, 0.0f }, a3, { 10.0f, 10.0f, 10.0f }, WHITE);
    if (IsKeyDown(KEY_B)) {
        bo = 1;
        x_bomb = a1 + 5;
        y_bomb = a2;
    }
    if (bo == 1) DrawModel(model_bomb, { x_bomb , 13.0f, y_bomb }, 16.1f, WHITE);
    DrawModelEx(model_perso2, { y1, 13.0, y2 }, { 0.0f, 1.0f, 0.0f }, y3, { 10.0f, 10.0f, 10.0f }, WHITE);
    DrawModelEx(model_enemy1, { pos1_x, 13.0, pos1_y}, { 0.0f, 1.0f, 0.0f }, pos1_a, { 10.0f, 10.0f, 10.0f }, WHITE);
    DrawModelEx(model_enemy2, { pos2_x, 13.0, pos2_y}, { 0.0f, 1.0f, 0.0f }, pos2_a, { 10.0f, 10.0f, 10.0f }, WHITE);
    collision_player1(map);
    collision_player2(map);
    EndMode3D();
    if (IsKeyDown(KEY_SPACE)) int_pause = 1;
    if (int_pause == 1) {
        DrawTexture(text_pause, 200, 80, WHITE);
        if (CheckCollisionPointRec(pos, butt_r_game)) {
            DrawTextEx(font6, s_game.c_str(), {450, 200}, 50, 2, YELLOW);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                PlaySound(sound_click);
                int_pause = 0;
            }
        }
        else
            DrawTextEx(font6, s_game.c_str(), {450, 200}, 50, 2, WHITE);
        if (CheckCollisionPointRec(pos, butt_r_menu)) {
            DrawTextEx(font6, s_menu.c_str(), {460, 280}, 50, 2, YELLOW);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                PlaySound(sound_click);
                StopSound(sound_game);
                int_pause = 0;
                fa = 1;
                scr = 0;
                dcr = 50;
                int_seconds = 60;
                int_minutes = 0;
                a1 = -126.0;
                a2 = 112.0;
                a3 = 180.0f;
                y1 = 112.0;
                y2 = 112.0;
                y3 = 0.0f;
            }
        }
        else
            DrawTextEx(font6, s_menu.c_str(), {460, 280}, 50, 2, WHITE);
        if (CheckCollisionPointRec(pos, butt_r_quit)) {
            DrawTextEx(font6, s_quit.c_str(), {465, 370}, 50, 2, YELLOW);
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                PlaySound(sound_click);
                CloseWindow();
                exit (0); }
        }
        else
            DrawTextEx(font6, s_quit.c_str(), {465, 370}, 50, 2, WHITE);
        if (IsKeyDown(KEY_LEFT_SHIFT)) int_pause = 0;
    }
    else {
        scr += 0.005;
        dcr--;
        if (dcr <= 0) {
            int_seconds -= 1;
            dcr = 50;
        }
        if (int_seconds <= 0) {
            int_minutes -= 1;
            int_seconds = 60;
        }
        if (int_minutes <= -1) m = 1;
        if (m == 1) {
            StopSound(sound_game);
            myLoop(sound_over);
            gameOver(); }
        UpdateModelAnimation(model_perso1, anims[anim_plus1], animFrameCounter);
        UpdateModelAnimation(model_perso2, anims1[anim_plus2], animFrameCounter1);
        UpdateModelAnimation(model_enemy1, anim_enemy1[1], animFrame_enemy1);
        UpdateModelAnimation(model_enemy2, anim_enemy2[1], animFrame_enemy2); 
        ia(map);
        ia2(map);
        }
}

void init::mySets(void)
{
    DrawTexture(text_sets, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
    if (CheckCollisionPointRec(pos, butt_go_back)) {
        DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, YELLOW);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(sound_click);
            q = 0; }
    }
    else DrawTextEx(font6, go_back.c_str(), {25, 530}, 50, 2, WHITE);
}

void init::gameOver(void)
{
    DrawTexture(text_over, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);
        if (IsKeyDown(KEY_R)) 
        {
            StopSound(sound_over);
            fa = 2;
            m = 0;
            dcr = 50;
            int_seconds = 60;
            int_minutes = 0;
            a1 = -126.0;
            a2 = 112.0;
            a3 = 180.0f;
            y1 = 112.0;
            y2 = 112.0;
            y3 = 0.0f;
        }
        if (IsKeyDown(KEY_K)) {
            StopSound(sound_over);
            fa = 1;
            int_pause = 0;
            scr = 0;
            m = 0;
            dcr = 50;
            int_seconds = 60;
            int_minutes = 0;
            a1 = -126.0;
            a2 = 112.0;
            a3 = 180.0f;
            y1 = 112.0;
            y2 = 112.0;
            y3 = 0.0f;
        }
}
