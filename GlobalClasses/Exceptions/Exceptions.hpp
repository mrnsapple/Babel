/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Exceptions
*/

#ifndef BABEL_EXCEPTIONS_HPP
#define BABEL_EXCEPTIONS_HPP

#include <string>
#include <exception>

class Exception : public std::exception {
public:
    Exception(std::string const &message, std::string const &component = "Unknwon") noexcept;
    std::string const &getContext() const;
    char const *what() const noexcept override;

private:
    std::string _message;
    std::string _context;
};

class DatabaseError : public Exception {
public:
    DatabaseError(std::string const &message, std::string const &context = "Unknown");
};


class GeneralException : public Exception {
public:
    GeneralException(std::string const &message, std::string const &context = "Unknown");
};

class VoiceException : public Exception {
public:
    VoiceException(std::string const &message, std::string const &context = "Unknown");
};


#endif //BABEL_EXCEPTIONS_HPP
