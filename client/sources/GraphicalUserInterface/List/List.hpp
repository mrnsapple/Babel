//
// Created by nelrum on 21/9/19.
//

#ifndef BABEL_LIST_HPP
#define BABEL_LIST_HPP

#include <QApplication>
#include <QListWidget>
#include <QListWidgetItem>
#include <QWidget>
#include <QObject>
#include <iostream>
#include <string>

class List : public QListWidget {
    Q_OBJECT
public:
    List(QWidget *parent, QPoint pos);
    virtual ~List(){}
    void addContact(const std::string& contactName);
};


#endif //BABEL_LIST_HPP
