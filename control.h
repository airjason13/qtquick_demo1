#ifndef CONTROL_H
#define CONTROL_H
#include <QObject>
#include <QtCore/QtCore>
class control : public QObject
{
    Q_OBJECT
    public:
        explicit control(QObject *parent = 0);
        void initialize( QObject* qObj );

    signals:
        void updateName( QString name );

    public slots:
        void setName( QString name );
        void finished(int exitCode, QProcess::ExitStatus exitStatus);

        void readyReadStandardError();

        void started();

        void readyReadStandardOutput();

    private:
        QObject* viewItem;
        QProcess cp;
};

#endif // CONTROL_H
