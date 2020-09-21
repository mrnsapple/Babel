//
// Created by nelrum on 19/9/19.
//

#include "Label.hpp"

Label::Label(QWidget *parent, std::string key, QPoint pos)
    : QLabel(parent)
{
    this->setText(QString::fromStdString(key));
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}
