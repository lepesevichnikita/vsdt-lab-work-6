#ifndef VSDT_LAB_WORK_6_INCLUDE_TASK_1_H
#define VSDT_LAB_WORK_6_INCLUDE_TASK_1_H

#include <QObject>
#include <QList>
#include <QVariant>
#include <QDebug>

#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

class Task1: public QObject {
  Q_OBJECT
  Q_PROPERTY(int indexOfVectorWithMaxSumOfItems
      READ indexOfVectorWithMaxSumOfItems
      NOTIFY indexOfVectorWithMaxSumOfItemsChanged)

  Q_PROPERTY(qreal productOfNonZeroItems
      READ productOfNonZeroItems
      NOTIFY productOfNonZeroItemsOfResultVectorChanged)

  Q_PROPERTY(QVariant matrix
      READ matrix
      WRITE setMatrix
      NOTIFY matrixChanged)
  public:
    Task1(QObject *parent=nullptr);

    QVariant matrix();
    qreal productOfNonZeroItems();
    int indexOfVectorWithMaxSumOfItems();

  signals:
    void indexOfVectorWithMaxSumOfItemsChanged();
    void productOfNonZeroItemsOfResultVectorChanged();
    void matrixChanged();

  public slots:
    void setMatrix(const QVariant&);

  private:
    static bool sumCompare(const QList<qreal>&, const QList<qreal>&);
    static qreal sumOfVectorItems(const QList<qreal>&);

    static const size_t kWidth;
    static const size_t kHeight;
    
    static QList<QList<qreal>> initMatrix();
    static QList<QList<qreal>> initMatrix(const QVariant&);
    static QVariantList initMatrix(const QList<QList<qreal>>&);
    static inline double calculateItemOfMatrixByPos(const double &i, const double &j) {
      double result = std::pow(std::pow(std::cos(i), 2)/(3.5 - 0.5*j), std::sin(j)) - std::exp(i/j);
      return result;
    }

    QList<QList<qreal>> matrix_;

};

#endif
