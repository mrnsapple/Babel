//
// Created by nelrum on 19/9/19.
//

#ifndef BABEL_LABEL_HPP
#define BABEL_LABEL_HPP

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QObject>

class Label : public QLabel {
    Q_OBJECT
public:
    Label(QWidget *parent, std::string key, QPoint pos);
    virtual ~Label(){}

};


#endif //BABEL_LABEL_HPP
