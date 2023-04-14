/*
** EPITECH PROJECT, 2022
** init.cpp
** File description:
** init
*/

#include "init.hpp"

void init::myInitTexture(void)
{
    text_mouse = initImg(img_mouse, "ressources/sprites/mouse.png", 50, 50);
    texture = initImg(img, "ressources/sprites/bckgrnd.png", 998, 598);
    text_act = initImg(sprite, "ressources/sprites/act1.png", 450, 400);
    text_scene = initImg(sprite_scene, cinematic.c_str(), 1600, GetScreenHeight());
    bck_sprite = initImg(bck_img, "ressources/sprites/png1.png", GetScreenWidth(), GetScreenHeight());
    text_block = initImg(img_block, "ressources/sprites/bloc.png", 20, 20);
    text_bloc = initImg(img_bloc, "ressources/sprites/grasses.png", 20, 20);
    text_blc = initImg(img_blc, "ressources/sprites/wall.png", 20, 20);
    text_perso1 = initImg(img_perso1, "ressources/sprites/cyan.png", 0, 0);
    text_perso2 = initImg(img_perso2, "ressources/sprites/yellow.png", 0, 0);
    text_enemy1 = initImg(img_enemy1, "ressources/sprites/red.png", 0, 0);
    text_enemy2 = initImg(img_enemy2, "ressources/sprites/red.png", 0, 0);
    text_score = initImg(img_score, "ressources/sprites/score.png", 450, 250);
    text_pause = initImg(img_pause, "ressources/sprites/pause.png", 600, 400);
    text_how1 = initImg(img_how1, "ressources/sprites/how1.png", GetScreenWidth(), GetScreenHeight());
    text_how2 = initImg(img_how2, "ressources/sprites/how2.png", GetScreenWidth(), GetScreenHeight());
    text_how3 = initImg(img_how3, "ressources/sprites/how3.png", GetScreenWidth(), GetScreenHeight());
    text_sets = initImg(img_sets, "ressources/sprites/sets.png", GetScreenWidth(), GetScreenHeight());
    text_bomb = initImg(img_bomb, "ressources/sprites/bomb_normal.png", 0, 0);
    text_over = initImg(img_over, "ressources/sprites/over1.png", GetScreenWidth(), GetScreenHeight());
}

Texture2D init::initImg(Image img, char const *str, int a, int b)
{
    Texture2D texture;

    img = LoadImage(str);
    if (a != 0 && b != 0) ImageResize(&img, a, b);
    return texture = LoadTextureFromImage(img);
}

void init::myLoadModel(void)
{
    model = LoadModel("ressources/sprites/obj.obj");
    model1 = LoadModel("ressources/sprites/obj.obj");
    model2 = LoadModel("ressources/sprites/obj.obj");
    model_perso1 = LoadModel("ressources/sprites/player.iqm");
    model_perso2 = LoadModel("ressources/sprites/player.iqm");
    model_enemy1 = LoadModel("ressources/sprites/player.iqm");
    model_enemy2 = LoadModel("ressources/sprites/player.iqm");
    model_bomb = LoadModel("ressources/sprites/bomb.obj");
}

void init::myLoadSongs(void)
{
    music = LoadSound("ressources/songs/song.wav");
    sound = LoadSound("ressources/songs/menu.wav");
    sound_click = LoadSound("ressources/songs/click2.wav");
    sound_game = LoadSound("ressources/songs/game2.wav");
    sound_over = LoadSound("ressources/songs/over.wav");
    sound_help = LoadSound("ressources/songs/help.wav");
}

void init::myloadFont(void)
{
    font1 = LoadFont("ressources/fonts/font1.ttf");
    font2 = LoadFont("ressources/fonts/dura.ttf");
    font3 = LoadFont("ressources/fonts/font3.TTF");
    font4 = LoadFont("ressources/fonts/Blox2.ttf");
    font5 = LoadFont("ressources/fonts/font5.ttf");
    font6 = LoadFont("ressources/fonts/open1.ttf");
}

void init::myCam(void)
{
    camera = { 0 };
    camera.position = { 0.0f, 300.0f, 150.0f };
    camera.target = { 0.0f, 0.0f, 2.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 50.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

void init::myLoop(Sound sound)
{
    if (IsSoundPlaying(sound) == false)
        PlaySound(sound);
}