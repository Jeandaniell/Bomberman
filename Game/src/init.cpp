/*
** EPITECH PROJECT, 2022
** init.cpp
** File description:
** init
*/

#include "init.hpp"

init::init(void)
{
    valid = false;
    screenWidth = 1000;
    screenHeight = 600;
    m = 0;
    n = 0;
    ma = 0;
    fa = 0;
    pl = 1;
    s1 = 0;
    s2 = 0;
    a1 = -126.0;
    a2 = 112.0;
    a3 = 180.0f;
    y1 = 112.0;
    y2 = 112.0;
    y3 = 0.0f;
    pos1_a = 100.0f;
    pos2_a = 0.0f;
    index = 1;
    scr = 0;
    bo = 0;
    anim_plus1 = 1;
    anim_plus2 = 1;
    int_pause = 0;
    animFrameCounter = 0;
    animFrameCounter1 = 0;
    animFrame_enemy1 = 0;
    animFrame_enemy2 = 0;
    x_bomb = 0;
    y_bomb = 0;
    pos1_x = -140.0 + 14;
    pos1_y = -140.0 + 14;
    pos2_x = 140.0 - 28;
    pos2_y = -140.0 + 14;
    v = 0;
    r1 = 0;
    r2 = 0;
    q = 0;
    int_seconds = 60;
    int_minutes = 0;
    dcr = 50;
    my_null = 0;
    cinematic = "ressources/cinematique/img" + std::to_string(index) + ".png";
    map = map_generator(20, 20);
}

void init::open_window(void)
{
    InitWindow(screenWidth, screenHeight, "Bomberman");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    InitAudioDevice();
    SetTargetFPS(60);
}

void init::display(void)
{
    HideCursor();
    unsigned int animsCount = 0;
    unsigned int animsCount1 = 0;
    unsigned int animsCount_enemy1 = 0;
    unsigned int animsCount_enemy2 = 0;
    auto start = std::chrono::system_clock::now();
    myCam();
    buttons();
    myLoadSongs();
    myloadFont();
    myLoadModel();
    anims = LoadModelAnimations("ressources/sprites/player.iqm", &animsCount);
    anims1 = LoadModelAnimations("ressources/sprites/player.iqm", &animsCount1);
    anim_enemy1 = LoadModelAnimations("ressources/sprites/player.iqm", &animsCount_enemy1);
    anim_enemy2 = LoadModelAnimations("ressources/sprites/player.iqm", &animsCount_enemy2);
    myInitTexture();
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = text_bloc;
    model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = text_block;
    model2.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = text_blc;
    model_bomb.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = text_bomb;
    SetMaterialTexture(&model_perso1.materials[0], MATERIAL_MAP_DIFFUSE, text_perso1);
    SetMaterialTexture(&model_perso2.materials[0], MATERIAL_MAP_DIFFUSE, text_perso2);
    SetMaterialTexture(&model_enemy1.materials[0], MATERIAL_MAP_DIFFUSE, text_enemy1);
    SetMaterialTexture(&model_enemy2.materials[0], MATERIAL_MAP_DIFFUSE, text_enemy2);
    PlaySound(music);
    while (!WindowShouldClose()) {
        SetWindowState(FLAG_WINDOW_RESIZABLE);
        UpdateCamera(&camera);
        pos = GetMousePosition();
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed = end - start;
        animFrameCounter++;
        animFrameCounter1++;
        animFrame_enemy1++;
        animFrame_enemy2++;
        if (animFrameCounter >= anims[1].frameCount) animFrameCounter = 0;
        if (animFrameCounter1 >= anims1[0].frameCount) animFrameCounter1 = 0;
        if (animFrame_enemy1 >= anim_enemy1[0].frameCount) animFrame_enemy1 = 0;
        if (animFrame_enemy2 >= anim_enemy2[0].frameCount) animFrame_enemy2 = 0;
        BeginDrawing();
        ClearBackground(BLACK);
        if (fa == 2) myGame();
        else if (fa == 1) menu();
        else {
            if (index <= 66 && elapsed.count() > 0.01) {
                index+= 1;
                cinematic = "ressources/cinematique/img" + std::to_string(index) + ".png";
                sprite_scene = LoadImage(cinematic.c_str());
                ImageResize(&sprite_scene, 1200, GetScreenHeight());
                text_scene = LoadTextureFromImage(sprite_scene);
                start = std::chrono::system_clock::now();
            }
            DrawTexture(text_scene, -100, 0, WHITE);
            if (CheckCollisionPointRec(pos, butt5)) {
                DrawTextEx(font5, butt_skip.c_str(), {900, 550}, 35, 2, RED);
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    PlaySound(sound_click);
                    fa = 1;
                }
            } else
                DrawTextEx(font5, butt_skip.c_str(), {900, 550}, 35, 2, YELLOW);
        }
        DrawTexture(text_mouse, pos.x, pos.y, WHITE);
        EndDrawing();
    }
}

void init::close_window(void)
{
    UnloadSound(music);
    UnloadSound(sound);
    UnloadSound(sound_click);
    UnloadSound(sound_game);
    UnloadSound(sound_over);
    UnloadSound(sound_help);
    UnloadTexture(text_scene);
    UnloadTexture(texture);
    UnloadTexture(text_act);
    UnloadTexture(text_mouse);
    UnloadTexture(text_blc);
    UnloadTexture(text_bloc);
    UnloadTexture(text_perso1);
    UnloadTexture(bck_sprite);
    UnloadTexture(text_score);
    UnloadTexture(text_pause);
    UnloadTexture(text_how1);
    UnloadTexture(text_how2);
    UnloadTexture(text_how3);
    UnloadTexture(text_enemy1);
    UnloadTexture(text_enemy2);
    UnloadTexture(text_sets);
    UnloadTexture(text_bomb);
    UnloadTexture(text_over);
    CloseAudioDevice();
    CloseWindow();
}

init::~init(){}