//
// Created by nelrum on 18/9/19.
//

#include "Window.hpp"
#include "../../Core/Core.hpp"

Window::Window(int width, int height, Core *newCore, QWidget *parent) : QMainWindow(parent), _width(width), _height(height)
{
    Q_INIT_RESOURCE(QTres);
    _core = newCore;
    _eventcall = new Eventcall(_list, _statusIcon, _core);
    this->resize(_width, _height);
    this->show();
    this->setWindowTitle(QApplication::translate("title", "Babel"));
    this->setWindowIcon(QIcon(":/icon.png"));
}

void Window::createLoginResources()
{
    _userLine = new LineEdit(this, "", QPoint(_width / 2, (_height / 2) - 50));
    _userLabel = new Label(this, "Username", QPoint(_userLine->pos().x() - 100, _userLine->pos().y()));
    _passLine = new LineEdit(this, "", QPoint(_width / 2, _height / 2));
    _passLabel = new Label(this, "Password", QPoint(_passLine->pos().x() - 100, _passLine->pos().y()));
    _confirmButton = new PushButton(this, "Log In", QPoint(_passLine->pos().x(), _passLine->pos().y() + 50));
}

void Window::closeLoginResources()
{
    _userLine->close();
    _userLabel->close();
    _passLine->close();
    _passLabel->close();
    _confirmButton->hide();

}

void Window::setLogin()
{
    createLoginResources();
    _passLine->setEchoMode(LineEdit::Password);
    QObject::connect(_confirmButton, &QPushButton::clicked, this, &Window::checkLogin);

}

void Window::checkLogin()
{
    if (_userLine->text().isEmpty() || _passLine->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", " Write in the correct box!");
    } else {
        std::shared_ptr<UDPclient> client = _eventcall->_UDPclient;
        int udpPort = client->getPort();
        QObject::disconnect(_confirmButton, &PushButton::clicked, this, &Window::checkLogin);
        closeLoginResources();
        _username = _userLine->text().toStdString();
        _core->logIn(_userLine->text().toStdString(), _passLine->text().toStdString(), udpPort);
    }
}


void Window::createMainResources()
{
    Label *_userTag = new Label(this, "Welcome " + _username, QPoint(30, 0));
    _userTag->resize(_width, _userTag->size().height());

    _statusIcon = new Label(this, "", QPoint(0, 0));
    QPixmap px = QIcon(":/Online.png").pixmap(QSize(25, 25));
    _statusIcon->setPixmap(px);
    _eventcall->setStatusIcon(_statusIcon);
    _callButton = new PushButton(this, QIcon(":/te.png"), QSize(50, 50), QPoint(800, 600));
    _callButton->resize(60, 60);
    QObject::connect(_callButton, &PushButton::clicked, _eventcall, &Eventcall::checkPicCall);

    _endButton = new PushButton(this, QIcon(":/de.png"), QSize(50, 50), QPoint(450, 600));
    _endButton->resize(60, 60);
    QObject::connect(_endButton, &PushButton::clicked, _eventcall, &Eventcall::checkCloseCall);

    _list = new List(this, QPoint(50, 100));
}

void Window::fetchFriends(const std::vector<UserFriends> &friends)
{
    _list->resize(300, 400);
    for (const auto &fren: friends) {
        _list->addContact(fren.username);
    }
    QObject::connect(_list, &QListWidget::currentItemChanged, this, &Window::getSelectedContact);
}

void Window::createStatusBox()
{
    _statusBox = new ComboBox(this, QPoint(150, 520));
    _statusBox->resize(200, _statusBox->size().height());
    _statusBox->addItem("Online");
    _statusBox->addItem("Offline");
    QObject::connect(_statusBox, &QComboBox::currentTextChanged, this, &Window::addChangeStatusEventCatch);
}

auto Window::createNewContactBox()
{

    Label *addContactLabel = new Label(this, "Add new Contact", QPoint(50, 25));
    addContactLabel->resize(150, addContactLabel->size().height());
    _addContactLine = new LineEdit(this, "", QPoint(50, 50));
    _addContactLine->resize(200, _addContactLine->size().height());
    PushButton *confirmAddContact = new PushButton(this, QIcon(":/tick.png"), QSize(25, 25), QPoint(_addContactLine->size().width() + _addContactLine->pos().x(), 50));
    confirmAddContact->resize(30, confirmAddContact->size().height());
    return confirmAddContact;
}

void Window::setMain()
{

    Label *statusLabel = new Label(this, "Change Status", QPoint(50, 520));
    statusLabel->resize(100, statusLabel->size().height());

    auto confirmAddContact = createNewContactBox();

    QObject::connect(confirmAddContact, &PushButton::clicked, this, &Window::addContactEventCatch);
}

void Window::addChangeStatusEventCatch()
{
    _core->changeStatus(_statusBox->currentText().toStdString());
}

void Window::changeStatus(const std::string &status)
{
    std::cout << _statusBox->currentText().toStdString() << std::endl;
    QString newStatus = QString::fromStdString(":/" + status + ".png");
    _statusIcon->setPixmap(QIcon(newStatus).pixmap(25, 25));
}

void Window::addContactEventCatch()
{
    if (_addContactLine->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please write in the inputline!");
    } else {
        _core->addContact(_addContactLine->text().toStdString());
    }
}

void Window::addContact(const std::string &contactLine)
{
        _list->addContact(contactLine);
        _list->item(_list->count() - 1)->setIcon(QIcon(":/PendingFriendRequest.png"));
        _addContactLine->clear();
}

void Window::startCall(const int &callingPort, const std::string &callingIpAddr, const int &calledPort, const std::string &calledIpAddr)
{
    _eventcall->startCall(callingPort, callingIpAddr, calledPort, calledIpAddr);
}


// void Window::checkPicCall()
// {

// //    HEAVY WIP DANGER
//     _core->callContact(_selectedContact);

// //    TODO send request to call friend and stat client udp
//     if (_selectedContact.empty()) {
//         QMessageBox::warning(this, "Warning", " Select someone first to start a call");
//     } else {
//         std::cout << "Calling " + _selectedContact << std::endl;
//         QString newStatus = QString::fromStdString(":/InCall.png");
//         _statusIcon->setPixmap(QIcon(newStatus).pixmap(25, 25));
//     }
// }

// void Window::checkCloseCall()
// {
//     if (_selectedContact.empty()) {
//         std::cout << "Select someone first" << std::endl;
//     } else {
//         std::cout << "You ended the call with " + _selectedContact << std::endl;
//         QString newStatus = QString::fromStdString(":/Online.png");
//         _statusIcon->setPixmap(QIcon(newStatus).pixmap(25, 25));
//     }
// }

void Window::getSelectedContact()
{
    _selectedContact = _list->currentItem()->text().toStdString();
    _eventcall->setSelectedContact(_selectedContact);
}


void Window::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);
    if (_confirmButton != nullptr) {
        if (event->key() == Qt::Key_Return &&_confirmButton->isVisible()) {
            _confirmButton->click();
        }
    }
}

void Window::friendadded(const std::string &username)
{
    QMessageBox msgBox;
    std::string temp = "Friend request from " + username;
    msgBox.setText(temp.c_str());
    msgBox.setInformativeText("Do you want to accept it ?");
    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret = msgBox.exec();

    switch (ret) {
   case QMessageBox::Yes:
       std::cout << "yes" << std::endl;
       _list->addContact(username);
       _core->treatFriendResponse(AcceptFriend, username);
       break;
   case QMessageBox::No:
       std::cout << "no" << std::endl;
       _core->treatFriendResponse(DenyFriend, username);
       break;
   default:
       std::cout << "no" << std::endl;
       break;
 }
}