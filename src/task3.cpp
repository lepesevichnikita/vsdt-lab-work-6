//
// Created by nikital on 3/31/19.
//
#include "task3.h"

Task3::Task3(QObject *parent): QObject(parent)
{

    QObject::connect(this, SIGNAL(matrixSizeChanged()), this, SLOT(initMatrix()));
    QObject::connect(this, SIGNAL(matrixSizeChanged()), this, SLOT(calculateResultVector()));
}

uint Task3::width()
{
    return width_;
}

uint Task3::height()
{
    return height_;
}

void Task3::setWidth(const uint &width)
{
    if(width == width_) return;
    width_ = width;
    emit matrixSizeChanged();
}

void Task3::setHeight(const uint &height)
{
    if(height == height_) return;
    height_ = height;
    emit matrixSizeChanged();
}

QVariant Task3::matrix()
{
    QVariant result = qVariantFromMatrix(matrix_);
    return result;
}

void Task3::initMatrix()
{
    QRandomGenerator64 generator;
    generator.securelySeeded();
    matrix_.clear();
    matrix_.resize(height_);
    for (auto &row : matrix_) {
        for (const auto &item : QVector<bool>(width_))
            row.append(generator.bounded(-100, 100));
    }
    emit matrixChanged();
}

QVariantList Task3::qVariantFromMatrix(const QVector<QVector<int>> &matrix) {
    QVariantList result;
    for (QVector<int> row : matrix) {
        result << QVariant::fromValue(row);
    }
    return result;
}

QVector<int> Task3::resultVector()
{
    return resultVector_;
}

void Task3::calculateResultVector() {
    resultVector_ = QVector<int>(width_, 1);
    for (int i = 1; i < height_; i += 2) {
        for (int j = 0; j < width_; ++j) {
            resultVector_[j] *= matrix_[i][j];
        }
    }
    emit resultVectorChanged();
}
