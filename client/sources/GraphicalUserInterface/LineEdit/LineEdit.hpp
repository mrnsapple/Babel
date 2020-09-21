//
// Created by nelrum on 19/9/19.
//

#ifndef BABEL_LINEEDIT_HPP
#define BABEL_LINEEDIT_HPP

#include <QApplication>
#include <QLineEdit>
#include <QWidget>
#include <QObject>

class LineEdit : public QLineEdit {
    Q_OBJECT
public:
    LineEdit(QWidget *parent, std::string key, QPoint pos);
    virtual ~LineEdit(){}
};


#endif //BABEL_LINEEDIT_HPP
