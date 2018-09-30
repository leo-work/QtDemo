#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
 
    ui->setupUi(this);
    this->InitStyle();
    //connect(ui->account_lineEdit, SIGNAL(returnPressed()), this, SLOT(sendLoginRequest()));
    //connect(ui->password_lineEdit, SIGNAL(returnPressed()), this, SLOT(sendLoginRequest()));
   
}


LoginDialog::~LoginDialog()
{
    delete ui;
}

//void LoginDialog::sendLoginRequest(){
//    emit sendLoginRequest(ui->account_lineEdit->text(),ui->password_lineEdit->text());
//}

void LoginDialog::InitStyle()
{

}
