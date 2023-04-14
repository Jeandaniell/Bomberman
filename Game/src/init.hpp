/*
** EPITECH PROJECT, 2022
** init.hpp
** File description:
** init.hpp
*/

#include <string.h>
#include <string>
#include "raylib.h"
#include "error.hpp"
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

class init {
    public:
    init(void);
    ~init();
    bool is_valid(void);
    bool valid;
    void open_window(void);
    void close_window(void);
    void myLoop(Sound sound);
    void display(void);
    void display_map(std::vector<std::string> map);
    void collision_player1(std::vector<std::string> map);
    void collision_player2(std::vector<std::string> map);
    bool if_collision(std::vector<std::string> map, float x, float y);
    void myloadFont(void);
    void myInitTexture(void);
    void myCam(void);
    void buttons(void);
    void myLoadModel(void);
    void myLoadSongs(void);
    void myHelp(void);
    void GoRight_one(void);
    void GoRight_two(void);
    void opening(void);
    void menu(void);
    void myGame(void);
    void mySets(void);
    void ia(std::vector<std::string> map);
    void ia2(std::vector<std::string> map);
    int my_ia(std::vector<std::string> map);
    int my_ia2(std::vector<std::string> map);
    void check_str(std::string str);
    void gameOver(void);
    std::string my_str(std::vector<std::string> map);
    std::vector<std::string> map_generator(std::size_t li, std::size_t co);
    int ma, fa, pl, index, anim_plus1, anim_plus2;
    ModelAnimation *anims;
    ModelAnimation *anims1;
    ModelAnimation *anim_enemy1, *anim_enemy2, *anim_bomb;
    Camera camera;
    Model model, model1, model2, model_perso1, model_perso2;
    Model model_enemy1, model_enemy2, model_bomb;
    Sound music, sound, sound_click, sound_game, sound_over, sound_help;
    Rectangle butt1, butt2, butt3, butt4, butt5, butt_r_menu, butt_r_game, butt_r_quit;
    Rectangle butt_go_back, butt_go_right, butt_go_right_one, butt_go_left, butt_go_left_one;
    Image img, sprite, sprite_scene, bck_img, img_block, img_bloc, img_blc, img_pause;
    Image img_perso1, img_mouse, img_perso2, img_score;
    Image img_how1, img_how2, img_how3, img_sets;
    Image img_enemy1, img_enemy2, img_bomb, img_over;
    Font font1, font2, font3, font4, font5, font6;
    Texture2D texture, text_act, text_scene, bck_sprite, text_block, text_bloc, text_blc;
    Texture2D text_perso1, text_mouse, text_perso2, text_score, text_pause;
    Texture2D text_how1, text_how2, text_how3, text_sets;
    Texture2D text_enemy1, text_enemy2, text_bomb, text_over;
    Texture2D initImg(Image img, char const *str, int a, int b);
    std::string title, butt_play, butt_quit, butt_help, butt_opts, butt_skip;
    std::string cinematic, s_menu, s_game, s_quit;
    std::string go_back, go_right, go_left, str_time;
    std::vector<std::string> map;
    Vector2 pos;
    private:
    int animFrameCounter;
    int animFrameCounter1;
    int animFrame_enemy1;
    int animFrame_enemy2;
    int animFrame_bomb;
    int int_pause, v, r1, r2, q, int_seconds, int_minutes, dcr, my_null;
    int screenWidth;
    int screenHeight, bo, m, n;
    float pos1_x, pos1_y, pos2_x, pos2_y, pos1_a, pos2_a;
    float s1, s2, a1, a2, a3, y1, y2, y3, scr, x_bomb, y_bomb;
};
