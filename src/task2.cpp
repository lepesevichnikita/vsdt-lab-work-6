#include "task2.h"

Task2::Task2(QObject *parent)
  : QObject(parent), minDepth_(0), maxDepth_(254)
{
  QObject::connect(this, SIGNAL(imageNameChanged()), this, SLOT(reloadImage()));
  QObject::connect(this, SIGNAL(depthChanged()), this, SLOT(recalculateImage()));
}

QUrl Task2::imageName()
{
  return imageName_;
}

uchar Task2::maxDepth()
{
  return maxDepth_;
}

QString Task2::imageAsBase64()
{
  QByteArray ba;
  QBuffer buffer(&ba);
  buffer.open(QIODevice::WriteOnly);
  QMimeType type = QMimeDatabase().mimeTypeForFile(imageName_.path(), QMimeDatabase::MatchContent);
  image_.save(&buffer, type.preferredSuffix().toStdString().c_str());
  QString result = "data:" + type.name() + ";base64, " + ba.toBase64().data();
  return result;
}

void Task2::setImageName(const QUrl &imageName)
{
  if (imageName == imageName_)
    return;
  imageName_ = imageName;
  emit imageNameChanged();
  emit imageAsBase64Changed();
}

void Task2::reloadImage()
{
  if (imageName_.path().length() == 0) return;
  bool success = image_.load(imageName_.path());
}

QImage Task2::loadImage(const QString &path)
{
  QImage result(path);
  return QImage();
}

void Task2::setMaxDepth(const uchar &maxDepth)
{
  if (maxDepth == maxDepth_)
    return;
  maxDepth_ = maxDepth;
  emit depthChanged();
}

void Task2::setMinDepth(const uchar &minDepth)
{
  if (minDepth == minDepth_)
    return;
  minDepth_ = minDepth;
  emit depthChanged();
}

uchar Task2::minDepth()
{
  return minDepth_;
}

void Task2::recalculateImage() {
  for(uint i = 0; i < image_.width(); i++)
    for(uint j = 0; j < image_.height(); j++) {
      QColor pixel = image_.pixelColor(i, j);
      int lightness = ((pixel.lightness() > maxDepth_) ? 255 :
          (pixel.lightness() < minDepth_) ? 0 : lightness);
      pixel.setHsl(pixel.hue(), lightness, pixel.saturation(), pixel.alpha());
      image_.setPixelColor(i, j, pixel);
    }
  emit imageAsBase64Changed();
}
