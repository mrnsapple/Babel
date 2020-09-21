//
// Created by nelrum on 23/9/19.
//

#ifndef BABEL_COMBOBOX_HPP
#define BABEL_COMBOBOX_HPP

#include <QApplication>
#include <QComboBox>
#include <QWidget>
#include <QObject>

class ComboBox : public QComboBox {
    Q_OBJECT
public:
    ComboBox(QWidget *parent, QPoint pos);
    virtual ~ComboBox(){}

private:

};


#endif //BABEL_COMBOBOX_HPP
