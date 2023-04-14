/*
** EPITECH PROJECT, 2022
** error
** File description:
** error
*/
#include <string.h>
#include <string>
#include "raylib.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

class error : public std::exception
{
    public:
        error();
        ~error() noexcept{};
    private:
        std::string _str;
};