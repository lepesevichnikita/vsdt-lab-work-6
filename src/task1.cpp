#include "task1.h"

const size_t Task1::kWidth = 6;
const size_t Task1::kHeight = 5;

Task1::Task1(QObject *parent)
  : QObject(parent), matrix_(initMatrix())
{
}

qreal Task1::sumOfVectorItems(const QList<qreal> &vector)
{
  auto result = std::accumulate(vector.begin(), vector.end(), 0.0);
  return result;
}

bool Task1::sumCompare(const QList<qreal> &firstVector, const QList<qreal> &secondVector)
{
  qreal first_vectors_sum = sumOfVectorItems(firstVector);
  qreal second_vectors_sum = sumOfVectorItems(secondVector);
  return first_vectors_sum >= second_vectors_sum;
}

int Task1::indexOfVectorWithMaxSumOfItems()
{
  auto iterator = std::max_element(matrix_.begin(), matrix_.end(), sumCompare);
  int result = std::distance(matrix_.begin(), iterator);
  return result;
}

QVariant Task1::matrix()
{
  QVariant result = initMatrix(matrix_);
  return result;
};

void Task1::setMatrix(const QVariant &qmlMatrix)
{
  QList<QList<qreal>> cppMatrix = initMatrix(qmlMatrix);
  if (cppMatrix == matrix_)
    return;
  matrix_ = cppMatrix;
  emit matrixChanged();
  emit indexOfVectorWithMaxSumOfItemsChanged();
  emit productOfNonZeroItemsOfResultVectorChanged();
}

qreal Task1::productOfNonZeroItems()
{
  QList<qreal> vectorWithMaxSumOfItems = matrix_[indexOfVectorWithMaxSumOfItems()];
  QList<qreal> endVector;
  std::copy_if(vectorWithMaxSumOfItems.begin(),
      vectorWithMaxSumOfItems.end(),
      std::back_inserter(endVector),
      [](qreal x)
      { return int(x) != 0; });
  qreal result = std::accumulate(endVector.begin(), endVector.end(), 1, std::multiplies<qreal>());
  return result;
}

QList<QList<qreal>> Task1::initMatrix()
{
  QList<QList<qreal>> result;
  for (size_t i = 0; i < kHeight; i++) {
    QList<qreal> vector;
    for (size_t j = 0; j < kWidth; j++) {
      vector << calculateItemOfMatrixByPos(i+1, j+1);
    }
    result << vector;
  }
  return result;
}

QList<QList<qreal>> Task1::initMatrix(const QVariant &matrix)
{
  QList<QList<qreal>> result;
  for (QVariant i: matrix.toList()) {
    QList<qreal> vector = i.value<QList<qreal>>();
    result << vector;
  }
  return result;
}

QVariantList Task1::initMatrix(const QList<QList<qreal>> &matrix)
{
  QVariantList result;
  for (QList<qreal> vector: matrix) {
    result << QVariant::fromValue(vector);
  }
  return result;
}
