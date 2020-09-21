/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

Exception::Exception(std::string const &message, std::string const &component) noexcept
{
    _message = message;
    _context = component;
}

std::string const& Exception::getContext() const
{
    return _context;
}

char const* Exception::what() const noexcept
{
    return _message.c_str();
}

DatabaseError::DatabaseError(std::string const &message, const std::string &context) : Exception("What: " + message, "From: " + context)
{}


GeneralException::GeneralException(std::string const &message, const std::string &context) : Exception("What: " + message, "From: " + context)
{}

VoiceException::VoiceException(std::string const &message, const std::string &context) : Exception("What: " + message, "From: " + context)
{}