#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class tcpServer; }
QT_END_NAMESPACE

class tcpServer : public QWidget
{
    Q_OBJECT

public:
    tcpServer(QWidget *parent = nullptr);
    ~tcpServer();

private:
    Ui::tcpServer *ui;
};
#endif // TCPSERVER_H
