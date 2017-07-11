#include "worldserverclass.h"
#include <QTcpSocket>


WorldServerClass::WorldServerClass(MainWindow *helloserver,QObject *parent):QTcpServer(parent)
{
    hellowindow=helloserver;

}

void WorldServerClass::incomingConnection(int socketfd)
{
    QTcpSocket *client= new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    hellowindow->addmsg("New Client from "+ client->peerAddress().toString() );

    connect(client,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(client,SIGNAL(disconnected()),this,SLOT(disconnected()));
}

void WorldServerClass::readyRead()
{
    QTcpSocket *client= (QTcpSocket*)sender();
    if(client->canReadLine())
    {
        QString line= QString::fromUtf8(client->readLine().trimmed());
        hellowindow->addmsg(line);
    }
}

void WorldServerClass::disconnected()
{
    QTcpSocket *client=(QTcpSocket*)sender();
    qDebug() << "Client Disconnected from "+ client->peerAddress().toString();
    clients.remove(client);
}
