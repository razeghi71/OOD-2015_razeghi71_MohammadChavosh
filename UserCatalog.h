#ifndef USERCATALOG_H
#define USERCATALOG_H

#include <QString>
#include "User.h"
#include "DB.h"

class UserCatalog{
public :
    bool login(QString username,QString password);
    User get(int id);
    User get(QString username);
    User getByEmail(QString email);
    void add(User user);
    QVector<User> all();
    void remove(User user);

    static UserCatalog* getInstance();
    static User getLoggedInUser();


private :
    static User LoggedInUser;
    UserCatalog();
    void initLoggedInUser(QSqlQuery* res);
};

#endif
