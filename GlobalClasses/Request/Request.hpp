/*
** EPITECH PROJECT, 2019
** Babel
** File description:
** Request
*/

#ifndef BABEL_REQUEST_HPP
#define BABEL_REQUEST_HPP

#include "header.hpp"
#include <unordered_map>
#include <functional>

using boost::any_cast;

class Request {
public:
    static BinaryData constructRequest(const Keyword &, const boost::any &one = nullptr, const boost::any &two = nullptr,
            const boost::any &three = nullptr, const boost::any &four = nullptr, const boost::any &five = nullptr);
};


#endif //BABEL_REQUEST_HPP
