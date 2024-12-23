#ifndef HEADER_H
#define HEADER_H

#include <QString>
#include <QDateTime>

typedef struct _record
{
    QDateTime time;          //时间戳
    int     ID;             // 批次号
    int     rxNumber;       // 序号
    float   Dat1;
    float   Dat2;

}record;


#endif // HEADER_H
