#ifndef WORLDSERVERCLASS_H
#define WORLDSERVERCLASS_H

#include <QTcpServer>

#include"MainWindow.h"
class MainWindow;

class WorldServerClass : public QTcpServer
{
public:
    Q_OBJECT
    public:
        WorldServerClass(MainWindow *helloserver,QObject *parent=0);
        MainWindow *hellowindow;

    private slots:
        void readyRead();
        void disconnected();

    protected:
        void incomingConnection(int socketfd);

    private:
        QSet<QTcpSocket*> clients;
};

#endif // WORLDSERVERCLASS_H
