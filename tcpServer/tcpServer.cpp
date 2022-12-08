#include "tcpServer.h"
#include "ui_tcpServer.h"

tcpServer::tcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpServer)
{
    ui->setupUi(this);
}

tcpServer::~tcpServer()
{
    delete ui;
}

