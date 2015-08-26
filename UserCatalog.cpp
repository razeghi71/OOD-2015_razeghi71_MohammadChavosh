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

User UserCatalog::get(int id)
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

User UserCatalog::get(QString username)
{
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `User` where `username`='%1'").arg(username);
    QSqlQuery *res = db->executeQuery(query);

    if (res->next())
    {
        return User::createUserBySqlQuery(res);
    }
    return User();
}

User UserCatalog::getByEmail(QString email)
{
    DB *db = DB::getInstance();
    QString query = QString("SELECT * from `User` where `email`='%1'").arg(email);
    QSqlQuery *res = db->executeQuery(query);

    if (res->next())
    {
        return User::createUserBySqlQuery(res);
    }
    return User();

}


void UserCatalog::add(User user)
{
    User check = get(user.getUsername());
    DB *db = DB::getInstance();

    if ( check.getId() == 0 )
    {
        QString query = QString("INSERT INTO `User` VALUES (NULL,'%1','%2','%3','%4','%5','%6','%7','%8'); ").
                arg(user.getUsername(),
                    user.getPassword(),
                    user.getName(),
                    user.getFamily(),
                    user.getEmail(),
                    QString::number(user.getType()),
                    user.getNationalCode(),
                    user.getPersonelCode()
                    );
        qDebug() << query;
       db->executeQuery(query);
    } else {
        QString query = QString("UPDATE `User` SET `password`='%1', "
                                "`name`='%2', "
                                "`family`='%3', "
                                "`email`='%4', "
                                "`national_code`='%5', "
                                "`type`='%6', "
                                "personel_code='%7' "
                                "where `username`='%8'").
                arg(user.getPassword(),
                    user.getName(),
                    user.getFamily(),
                    user.getEmail(),
                    user.getNationalCode(),
                    QString::number(user.getType()),
                    user.getPersonelCode(),
                    user.getUsername()
                    );
        db->executeQuery(query);
    }

}

QVector<User> UserCatalog::all()
{
    QVector<User> users;

    DB *db = DB::getInstance();
    QString query = "SELECT * from `User`";
    QSqlQuery *res = db->executeQuery(query);

    while (res->next())
    {
        users.append(User::createUserBySqlQuery(res));
    }

    return users;
}

void UserCatalog::remove(User user)
{
    DB *db = DB::getInstance();
    QString query = QString("DELETE from `User` where `username`='%1'").arg(user.getUsername());
    db->executeQuery(query);
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




