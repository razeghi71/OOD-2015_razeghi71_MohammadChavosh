#ifndef USERCATALOG_H
#define USERCATALOG_H

#include <QString>
#include "User.h"
#include "DB.h"

class UserCatalog{
public :
    static User LoggedInUser;
    bool login(QString username,QString password);
    User getUserById(int id);
    void registerUser(User user);
    static UserCatalog* getInstance();
    static User getLoggedInUser();


private :
    UserCatalog();
    void initLoggedInUser(QSqlQuery* res);
};

#endif
