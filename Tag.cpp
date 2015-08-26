#include "Tag.h"

int Tag::getId() const
{
    return id;
}

void Tag::setId(int value)
{
    id = value;
}

QString Tag::getText() const
{
    return text;
}

void Tag::setText(const QString &value)
{
    text = value;
}


Tag::Tag()
{
    id = 0;
}

Tag::Tag(QString text)
{
    this->text = text;
}
