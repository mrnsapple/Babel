//
// Created by nelrum on 19/9/19.
//

#ifndef BABEL_PUSHBUTTON_HPP
#define BABEL_PUSHBUTTON_HPP

#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QObject>

class PushButton : public QPushButton {
    Q_OBJECT
public:
    PushButton(QWidget *parent, std::string key, QPoint pos);
    PushButton(QWidget *parent, QIcon icon, QSize iconSize, QPoint pos);
    virtual ~PushButton(){}
};


#endif //BABEL_PUSHBUTTON_HPP
