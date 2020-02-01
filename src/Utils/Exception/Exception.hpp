//
// Created by chaoticks on 01/02/2020.
//

#ifndef GGJ2020_EXCEPTION_HPP
#define GGJ2020_EXCEPTION_HPP

#include <string>

class Exception : public std::exception {
public:
    Exception(std::string const &message,
            std::string const &component = "Unknown");
    Exception(Exception &) = delete;
    Exception &operator=(Exception &) = delete;
    const char *what() const noexcept override;

private:
    std::string _message;
    std::string _component;
};


#endif //GGJ2020_EXCEPTION_HPP
