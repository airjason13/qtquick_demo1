#include "control.h"
#include <QDebug>
#include <QCoreApplication>
#include <QtCore/QtCore>
control::control(QObject *parent) : QObject(parent)
{

}

void control::initialize(QObject *qObj)
{
    this->viewItem = qObj;
    QObject::connect( viewItem, SIGNAL( qmlSetName(QString)), this, SLOT( setName(QString)) );
    QObject::connect( this, SIGNAL( updateName(QString)), viewItem, SIGNAL( qmlUpdateName(QString)) );
}

void control::setName(QString name)
{
    qDebug()<<"C++ : "<<name;
    //QProcess p;
    QObject::connect(&cp, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finished(int,QProcess::ExitStatus)));
    QObject::connect(&cp, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    QObject::connect(&cp, SIGNAL(started()), this, SLOT(started()));

    //cp.start("/bin/ls");
    cp.start("/usr/bin/gst-play-1.0 /home/jason/tftpboot/bestie.mp4");
    emit updateName("Modified Jason");
}

void control::finished(int exitCode, QProcess::ExitStatus exitStatus)
{
  qDebug() << "Finished: " << exitCode;
  //qApp->exit();
}

void control::readyReadStandardOutput()
{
  qDebug() << "readyOut";
  QProcess *p = (QProcess *)sender();
  QByteArray buf = p->readAllStandardOutput();

  qDebug() << buf;
}


void control::readyReadStandardError()
{
  qDebug() << "ReadyError";
}

void control::started()
{
  qDebug() << "Proc Started";

}
