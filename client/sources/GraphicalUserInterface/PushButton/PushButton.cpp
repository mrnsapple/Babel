//
// Created by nelrum on 19/9/19.
//

#include "PushButton.hpp"

PushButton::PushButton(QWidget *parent, std::string key, QPoint pos)
    : QPushButton(parent)
{
    this->setText(QString::fromStdString(key));
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

PushButton::PushButton(QWidget *parent, QIcon icon, QSize iconSize, QPoint pos)
    : QPushButton(parent)
{
    this->setIcon(icon);
    this->setIconSize(iconSize);
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}
