#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "viewcontrol.h"

LoginWindow::LoginWindow(ViewControl *control, QWidget *parent) :
    controller(control),
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QValidator *inputVal = new QIntValidator(1,9999999999,ui->idLineEdit);
    ui->idLineEdit->setValidator(inputVal);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_connectButton_clicked()
{
    // Be careful about truncation if OBJ_ID_TYPE is changed
    OBJ_ID_TYPE rawID = ui->idLineEdit->text().toULongLong();
    controller->requestAuthentication(rawID);
}

