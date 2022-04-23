#ifndef QEMUCORE_H
#define QEMUCORE_H

#include "app.h"

#include <QObject>
#include <QSharedPointer>
#include <QVector>

class QemuCore : public QObject
{
    Q_OBJECT
public:
    explicit QemuCore(QObject *parent = nullptr);
    QVector<QSharedPointer<App>> apps();
    // show_console = use non-w version of app
    QVector<QSharedPointer<App>> systemApps(bool show_console = true);
    QStringList systems();
    QSharedPointer<App> systemByName(const QString &name, bool show_console = true);
private:
    QVector<QSharedPointer<App>> m_apps;
    QVector<QSharedPointer<App>> m_system_apps;
    QVector<QSharedPointer<App>> m_system_apps_w;

signals:

};

#endif // QEMUCORE_H
