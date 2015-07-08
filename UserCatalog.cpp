#include "UserCatalog.h"
#include <QDebug>

User UserCatalog::LoggedInUser;

bool UserCatalog::login(QString username, QString password)
{
        DB *db = DB::getInstance();
        QString query = QString("SELECT * from `User` where `username`='%1' AND `password`='%2'").arg(username,password);
        QSqlQuery *res = db->executeQuery(query);

        if (res->next())
        {
            User user = User::createUserBySqlQuery(res);
            this->LoggedInUser = user;
            return true;
        }
        return false;
}

User UserCatalog::getUserById(int id)
{
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `User` where `id`='%1'").arg(QString::number(id));
    QSqlQuery *res = db->executeQuery(query);

    if (res->next())
    {
        return User::createUserBySqlQuery(res);
    }
    return User();
}

void UserCatalog::registerUser(User user)
{
    DB *db = DB::getInstance();
    QString query = QString("INSERT INTO `User` VALUES (NULL,'%1','%2','%3','%4','%5','0','%6','%7'); ").
            arg(user.getUsername(),
                user.getPassword(),
                user.getName(),
                user.getFamily(),
                user.getEmail(),
                user.getNationalCode(),
                user.getPersonelCode()
                );

    QSqlQuery *res = db->executeQuery(query);
}


UserCatalog* UserCatalog::getInstance()
{
    static UserCatalog *cat;
    return cat;
}

User UserCatalog::getLoggedInUser()
{
    return LoggedInUser;
}




