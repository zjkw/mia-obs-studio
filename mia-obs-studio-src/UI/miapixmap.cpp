#include "miapixmap.h"
#include <QFile>

CPixmap::CPixmap(const QString &path):
    QPixmap(path, format(path).toStdString().c_str())
{

}

QString CPixmap::format(const QString &path)
{
    //BMP格式特征码
    unsigned char BMPHeader[] = { 0x42, 0x4d };
    //JPG,JPEG格式特征码
    unsigned char JPGHeader1[] = { 0xff, 0xd8, 0xff, 0xdb };
    unsigned char JPGHeader2[] = { 0xff, 0xd8, 0xff, 0xe0 };
    unsigned char JPGHeader3[] = { 0xff, 0xd8, 0xff, 0xe1 };
    unsigned char JPGHeader4[] = { 0xff, 0xd8, 0xff, 0xe2 };
    unsigned char JPGHeader5[] = { 0xff, 0xd8, 0xff, 0xe3 };
    unsigned char JPGHeader6[] = { 0xff, 0xd8, 0xff, 0xe8 };
    //GIF格式特征码
    unsigned char GIFHeader1[] = { 0x47, 0x49, 0x46, 0x38, 0x37, 0x61 };
    unsigned char GIFHeader2[] = { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61 };
    //PNG格式特征码
    unsigned char PNGHeader[] = { 0x89, 0x50, 0x4E, 0x47 };

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        return QString();
    }
    QByteArray array;
    array.append(file.read(2));

    if (memcmp(array.data(), BMPHeader, 2) == 0)
    {
        return QString("BMP");
    }
    array.append(file.read(2));
    if ((memcmp(array.data(), JPGHeader1, 4) == 0)
        || (memcmp(array.data(), JPGHeader2, 4) == 0)
        || (memcmp(array.data(), JPGHeader3, 4) == 0)
        || (memcmp(array.data(), JPGHeader4, 4) == 0)
        || (memcmp(array.data(), JPGHeader5, 4) == 0)
        || (memcmp(array.data(), JPGHeader6, 4) == 0)) {
        return QString("JPG");
    }
    else if (memcmp(array.data(), PNGHeader, 4) == 0) {
        return QString("PNG");
    }

    array.append(file.read(2));
    if ((memcmp(array.data(), GIFHeader1, 6) == 0)
        || (memcmp(array.data(), GIFHeader2, 6) == 0)) {
        return QString("GIF");
    }
    return QString("");
}