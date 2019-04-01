#ifndef VSDT_LAB_WORK_6_INCLUDE_TASK_3_H
#define VSDT_LAB_WORK_6_INCLUDE_TASK_3_H

#include <QObject>
#include <QVariant>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

class Task3: public QObject
{
Q_OBJECT

    Q_PROPERTY(uint width
                   READ width
                   WRITE setWidth
                   NOTIFY
                   matrixSizeChanged)

    Q_PROPERTY(uint height
                   READ height
                   WRITE setHeight
                   NOTIFY
                   matrixSizeChanged)

    Q_PROPERTY(QVariant matrix
                   READ matrix
                   NOTIFY
                   matrixChanged)

    Q_PROPERTY(QVector<int> resultVector
                   READ resultVector
                   NOTIFY
                   resultVectorChanged)

public:
    Task3(QObject *parent = nullptr);

    uint width();
    uint height();
    QVariant matrix();
    QVector<int> resultVector();

    void setWidth(const uint &);
    void setHeight(const uint &);

signals:
    void matrixSizeChanged();
    void matrixChanged();
    void resultVectorChanged();

private:
    uint width_, height_;
    QVector<QVector<int>> matrix_;
    QVector<int> resultVector_;

    static QVariantList qVariantFromMatrix(const QVector<QVector<int>> &);

private slots:
    void initMatrix();
    void calculateResultVector();
};
#endif
