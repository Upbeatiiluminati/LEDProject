#include "serial.h"
Serial::Serial(QObject *parent) : QObject(parent), m_Author(" ")
{
    port = new QSerialPort;
    devCount=0;
    m_Author.append("Number of available serial ports:" + QString::number(QSerialPortInfo::availablePorts().length())+"\n");
    m_Author.append("\n");
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        m_Author.append("Name:"+info.portName()+"\n");
        if(info.hasVendorIdentifier())
        {
            m_Author.append("Has vendor ID:true\n");
            m_Author.append("Vendor ID:"+QString::number(info.vendorIdentifier())+"\n");

        }
        else
        {
            m_Author.append("Has vendor ID:false\n");
        }

        if(info.hasProductIdentifier())
        {
            m_Author.append("Has product ID:true\n");
            m_Author.append("Product ID:"+QString::number(info.productIdentifier())+"\n");
            m_Author.append("Manufacturer:"+info.manufacturer()+"\n");

        }
        else
        {
            m_Author.append("Has product ID:false\n");
        }
        m_Author.append("\n");
        if(info.vendorIdentifier()==6790&&info.productIdentifier()==29987)
        {
        ardFound =true;
        ardport = devCount;
        }
        devCount++;

    }
    if(ardFound)
    {
        m_Author.append("Arduino is available and connected to "+QSerialPortInfo::availablePorts().at(ardport).portName()+" port\n");
        port->setPortName(QSerialPortInfo::availablePorts().at(ardport).portName());
        port->setBaudRate(QSerialPort::Baud9600);
        port->setParity(QSerialPort::NoParity);
        port->setFlowControl(QSerialPort::NoFlowControl);
        port->setDataBits(QSerialPort::Data8);
        port->setStopBits(QSerialPort::OneStop);
        port->open(QSerialPort::WriteOnly);

    }
}

Serial::~Serial()
{
    port->close();
    delete port;
}

void Serial::change_Color(QString command)
{
    if(port->isWritable()) port->write(command.toUtf8());
}

