/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** main.cpp
*/

#include "init.hpp"

int errors(int ac, char **av)
{
    if (ac > 1) 
        return (84);
    return 0;
}

int main(int ac, char **av)
{
    if (errors(ac, av) == 84) 
        return (84);
    else {
        init ma;
        ma.open_window();
        ma.display();
        ma.close_window(); 
        }
    return 0;
}