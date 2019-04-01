//
// Created by nikital on 4/1/19.
//

#ifndef VSDT_LAB_WORK_6_TASK4_H
#define VSDT_LAB_WORK_6_TASK4_H

#include <QObject>
#include <QVector>
#include <QDebug>

#include <QtMath>

class Task4: public QObject
{
Q_OBJECT
    Q_PROPERTY(QVector<qreal> resultVector
                   READ resultVector
                   NOTIFY
                   resultVectorChanged)

public:
    const static qreal SOURCE_ARRAY[8];
    const static qreal A;

    Task4(QObject *parent = nullptr);

    QVector<qreal> resultVector();

signals:
    void resultVectorChanged();
};

#endif //VSDT_LAB_WORK_6_TASK4_H
