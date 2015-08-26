#ifndef TAG_H
#define TAG_H

#include <QString>

class Tag{
public:
    int getId() const;
    void setId(int value);

    QString getText() const;
    void setText(const QString &value);

    Tag();
    Tag(QString text);

    Tag operator = ( Tag other )
    {
        this->setId(other.getId());
        this->setText(other.getText());
        return other;
    }


private:
    int id;
    QString text;


};

#endif
