#include "User.h"
#include<QVariant>
#include<QDebug>

QString User::getUsername() const
{
    return username;
}

void User::setUsername(const QString &value)
{
    username = value;
}

QString User::getPassword() const
{
    return password;
}

void User::setPassword(const QString &value)
{
    password = value;
}

QString User::getName() const
{
    return name;
}

void User::setName(const QString &value)
{
    name = value;
}

QString User::getFamily() const
{
    return family;
}

void User::setFamily(const QString &value)
{
    family = value;
}

QString User::getEmail() const
{
    return email;
}

void User::setEmail(const QString &value)
{
    email = value;
}

QString User::getNationalCode() const
{
    return nationalCode;
}

void User::setNationalCode(const QString &value)
{
    nationalCode = value;
}

bool User::getAdmin() const
{
    return admin;
}

void User::setAdmin(bool value)
{
    admin = value;
}

int User::getId() const
{
    return id;
}

void User::setId(int value)
{
    id = value;
}

User User::createUserBySqlQuery(QSqlQuery *res)
{
    int id = res->value("id").toInt();
    QString username = res->value("username").toString();
    QString password = res->value("password").toString();
    QString name = res->value("name").toString();
    QString family = res->value("family").toString();
    QString email = res->value("email").toString();
    QString national_code = res->value("national_code").toString();
    QString personel_code = res->value("personel_code").toString();
    bool admin = res->value("admin").toInt();

    User user;
    user.setId(id);
    user.setUsername(username);
    user.setPassword(password);
    user.setEmail(email);
    user.setNationalCode(national_code);
    user.setPersonelCode(personel_code);
    user.setName(name);
    user.setFamily(family);
    user.setAdmin(admin);

    return user;

}
QString User::getPersonelCode() const
{
    return personelCode;
}

void User::setPersonelCode(const QString &value)
{
    personelCode = value;
}

User::User()
{
    id = 0;
}

