/*
**
** GLOBAL GAME JAM
**
*/

#ifndef USING_HPP
    #define USING_HPP

    #include <iostream>
    #include <memory>
    #include <string>

template <typename T>
using u_ptr = std::unique_ptr<T>;
template <typename T>
using s_ptr = std::shared_ptr<T>;
using suint = short unsigned int;
using id = short unsigned int;

#endif /* USING_HPP */
