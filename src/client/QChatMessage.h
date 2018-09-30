#ifndef QCHATMESSAGE_H
#define QCHATMESSAGE_H

#include <QWidget>

class QPaintEvent;
class QPainter;
class QLabel;
class QMovie;

class QChatMessage : public QWidget
{
    Q_OBJECT
public:
    explicit QChatMessage(QWidget *parent = nullptr);

    enum User_Type{
        User_System,//系统
        User_Time,  //时间
        User_Me_IM,    //自己
        User_Me_ZIP,    //自己
        User_She_IM,   //用户
        User_She_ZIP,   //
    };

    inline User_Type userType() {return m_userType;}
protected:
    void paintEvent(QPaintEvent *event);
private:
    User_Type m_userType = User_System;
};

#endif // QCHATMESSAGE_H
