//
// Created by nikital on 4/1/19.
//

#include <task4.h>

#include "task4.h"

const qreal Task4::SOURCE_ARRAY[8] =  {3.9, 2.5, 3.6, 6.2, 5.0, 3.3, 2.7, 4.6};
const qreal Task4::A = 0.82;

Task4::Task4(QObject *parent)
    : QObject(parent)
{

}
QVector<qreal> Task4::resultVector()
{
    QVector<qreal> result;
    for (const auto &sourceArrayItem : SOURCE_ARRAY) {
        qreal temp = qCos((3*A + sourceArrayItem)/4)/qPow(qSin(3 * sourceArrayItem + qExp(4*A)), 3);
        result << temp;
    }
    return result;
}
