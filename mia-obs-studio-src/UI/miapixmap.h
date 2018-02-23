#pragma once
#include <QPixmap>
class CPixmap : public QPixmap
{
public:
    CPixmap(const QString &path);
    static QString format(const QString &path);
};