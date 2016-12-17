#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QQuickItem>
#include <QSerialPort>
#include <QSerialPortInfo>
class Serial : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString Author READ Author WRITE setAuthor NOTIFY AuthorChanged)
    QString m_Author;
    QSerialPort* port;
    int devCount,ardport;
    bool ardFound;

public:
  explicit Serial(QObject *parent = 0);
QString Author() const
{
    return m_Author;
}
   ~Serial();
signals:

void AuthorChanged(QString Author);

public slots:
void setAuthor(QString Author)
{
    if (m_Author == Author)
        return;

    m_Author = Author;
    emit AuthorChanged(Author);
}
void change_Color(QString command);
};

#endif // SERIAL_H
