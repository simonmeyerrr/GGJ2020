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
