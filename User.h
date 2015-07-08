#ifndef USER_H
#define USER_H

#include<QString>
#include<QSqlQuery>

class User{

public:
    QString getUsername() const;
    void setUsername(const QString &value);

    QString getPassword() const;
    void setPassword(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getFamily() const;
    void setFamily(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getNationalCode() const;
    void setNationalCode(const QString &value);

    bool getAdmin() const;
    void setAdmin(bool value);

    int getId() const;
    void setId(int value);

    static User createUserBySqlQuery(QSqlQuery *res);

    QString getPersonelCode() const;
    void setPersonelCode(const QString &value);

    User();

private :
    int id;
    QString username;
    QString password;
    QString name;
    QString family;
    QString email;
    QString nationalCode;
    QString personelCode;
    bool admin;

};

#endif
