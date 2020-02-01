/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** main.cpp
*/

#include "Core/Core.hpp"

int main(int const ac, char const *const *av, char const *const *env)
{
    try {
        Core core;
        core.start();
    } catch (...) {
        return 84;
    }
    return 0;
}
