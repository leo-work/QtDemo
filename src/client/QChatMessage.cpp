#include "QChatMessage.h"
#include <QFontMetrics>
#include <QPaintEvent>
#include <QDateTime>
#include <QPainter>
#include <QMovie>
#include <QLabel>
#include <QDebug>

QChatMessage::QChatMessage(QWidget *parent) : QWidget(parent)
{
    QFont te_font = this->font();
    te_font.setFamily("MicrosoftYaHei");
    te_font.setPointSize(16);
//    te_font.setWordSpacing(0);
//    te_font.setLetterSpacing(QFont::PercentageSpacing,0);
//    te_font.setLetterSpacing(QFont::PercentageSpacing, 100);          //300%,100为默认  //设置字间距%
    te_font.setLetterSpacing(QFont::AbsoluteSpacing, 0);             //设置字间距为3像素 //设置字间距像素值
    this->setFont(te_font);
}


void QChatMessage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QRectF rectangle(10.0, 20.0, 80.0, 60.0); //矩形
    int startAngle = 30 * 16;     //起始角度
    int spanAngle = -60 * 16;   //跨越度数
    QPainter painter(this);
    painter.drawArc(rectangle, startAngle, spanAngle);
    painter.drawRect(rectangle);
    //https://blog.csdn.net/qq_40194498/article/details/79650641
    //qDebug()<<"paintEvent";
}
