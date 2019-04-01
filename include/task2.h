#ifndef VSDT_LAB_WORK_6_INCLUDE_TASK_2_H
#define VSDT_LAB_WORK_6_INCLUDE_TASK_2_H

#include <QObject>
#include <QImage>
#include <QMimeType>
#include <QMimeDatabase>
#include <QUrl>

#include <QBuffer>
#include <QDebug>

class Task2: public QObject
{
Q_OBJECT

    Q_PROPERTY(QUrl imageName
                   READ imageName
                   WRITE setImageName
                   NOTIFY
                   imageNameChanged)

    Q_PROPERTY(QString imageAsBase64
                   READ
                       imageAsBase64
                   NOTIFY
                   imageAsBase64Changed)

    Q_PROPERTY(uchar maxDepth
                   READ
                       maxDepth
                   WRITE
                       setMaxDepth
                   NOTIFY
                   depthChanged)

    Q_PROPERTY(uchar minDepth
                   READ
                       minDepth
                   WRITE
                       setMinDepth
                   NOTIFY
                   depthChanged)
public:
    explicit Task2(QObject *parent = nullptr);

    uchar maxDepth();
    void setMaxDepth(const uchar &);

    uchar minDepth();
    void setMinDepth(const uchar &);

    QString imageAsBase64();

    QUrl imageName();
    void setImageName(const QUrl &);

signals:
    void imageNameChanged();
    void imageAsBase64Changed();
    void depthChanged();

private:
    QUrl imageName_;
    QImage image_;
    uchar maxDepth_, minDepth_;

private slots:
    void reloadImage();
    void recalculateImage();

    static QImage loadImage(const QString &);
};

#endif