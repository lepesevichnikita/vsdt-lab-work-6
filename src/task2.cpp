#include "task2.h"

Task2::Task2(QObject *parent)
  : QObject(parent), minLightness_(0), maxLightness_(254)
{
  QObject::connect(this, SIGNAL(imageNameChanged()), this, SLOT(reloadImage()));
  QObject::connect(this, SIGNAL(lightnessChanged()), this, SLOT(recalculateImage()));
}

QUrl Task2::imageName()
{
  return imageName_;
}

uchar Task2::maxLightness()
{
  return maxLightness_;
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

void Task2::setMaxLightness(const uchar &maxLightness)
{
  if (maxLightness == maxLightness_)
    return;
  maxLightness_ = maxLightness;
  emit lightnessChanged();
}

void Task2::setMinLightness(const uchar &minLightness)
{
  if (minLightness == minLightness_)
    return;
  minLightness_ = minLightness;
  emit lightnessChanged();
}

uchar Task2::minLightness()
{
  return minLightness_;
}

void Task2::recalculateImage() {
  for(uint i = 0; i < image_.width(); i++)
    for(uint j = 0; j < image_.height(); j++) {
      QColor pixel = image_.pixelColor(i, j);
      int lightness = pixel.lightness();
      if (lightness > maxLightness_) lightness = 255;
      if (lightness < minLightness_) lightness = 0;
      pixel.setHsl(pixel.hslHue(), pixel.hslSaturation(), lightness, pixel.alpha());
      image_.setPixelColor(i, j, pixel);
    }
  emit imageAsBase64Changed();
}
