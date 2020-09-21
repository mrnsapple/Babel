//
// Created by nelrum on 21/9/19.
//

#include "List.hpp"

List::List(QWidget *parent, QPoint pos)
    : QListWidget(parent)
{
    this->move(pos);
    this->show();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

void List::addContact(const std::string& contactName)
{
    this->addItem(new QListWidgetItem(QString::fromStdString(contactName), this));
// STATUS display
    this->item(this->count() - 1)->setIcon(QIcon("../client/assets/Online.png"));
}
