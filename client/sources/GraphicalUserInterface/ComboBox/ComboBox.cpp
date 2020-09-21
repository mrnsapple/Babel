//
// Created by nelrum on 23/9/19.
//

#include "ComboBox.hpp"

ComboBox::ComboBox(QWidget *parent, QPoint pos)
    : QComboBox(parent)
{
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}
