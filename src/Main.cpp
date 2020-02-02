/*
** EPITECH PROJECT, 2019
** GGJ2020
** File description:
** main.cpp
*/

#include <exception>
#include "Core/Core.hpp"

int main(int const ac, char const *const *av, char const *const *env)
{
    try {
        std::srand(time(nullptr));
        Core core;
        core.start();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (...) {
        return 84;
    }
    return 0;
}
