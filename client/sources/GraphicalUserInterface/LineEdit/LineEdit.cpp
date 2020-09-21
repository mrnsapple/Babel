//
// Created by nelrum on 19/9/19.
//

#include "LineEdit.hpp"

LineEdit::LineEdit(QWidget *parent, std::string key, QPoint pos)
    : QLineEdit(parent)
{
    this->setText(QString::fromStdString(key));
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}