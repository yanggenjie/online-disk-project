#include "tcpClient.h"
#include "ui_tcpClient.h"

tcpClient::tcpClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpClient)
{
    ui->setupUi(this);
}

tcpClient::~tcpClient()
{
    delete ui;
}

