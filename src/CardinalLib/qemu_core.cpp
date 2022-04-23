#include "qemu_core.h"

QemuCore::QemuCore(QObject *parent) : QObject{parent}
{
    // A list of apps that come with QEMU
    QStringList app_names = {
        "edid", "ga", "img", "io", "nbd",
        "system-aarch64", "system-alpha", "system-arm",
        "system-avr", "system-cris", "system-hppa", "system-i386",
        "system-m68k", "system-microblaze", "system-microblazeel",
        "system-mips", "system-mips64", "system-mips64el",
        "system-mipsel", "system-nios2", "system-or1k", "system-ppc",
        "system-ppc64", "system-riscv32", "system-riscv64", "system-rx",
        "system-s390x", "system-sh4", "system-sh4eb", "system-sparc",
        "system-sparc64", "system-tricore", "system-x86_64", "system-xtensa",
        "system-xtensaeb"
    };

    // Loop through them and find their locations
    for(int i=0; i<app_names.count(); i++)
    {
        QString app_name = QString("qemu-%1").arg(app_names[i]);
        QSharedPointer<App> app = QSharedPointer<App>(new App(app_name));

        if(app->exists())
        {
            if(app_name.contains("-system-"))
            {
                m_system_apps.append(app);

                QString app_w_name = QString("%1w").arg(app_name);
                QSharedPointer<App> app_w = QSharedPointer<App>(new App(app_w_name));

                if(app_w->exists())
                {
                    m_system_apps_w.append(app_w);
                }
            }
            else
            {
                m_apps.append(app);
            }
        }
    }

    m_apps << m_system_apps << m_system_apps_w;
}

QVector<QSharedPointer<App>> QemuCore::apps()
{
    return m_apps;
}

QVector<QSharedPointer<App>> QemuCore::systemApps(bool show_console)
{
    return show_console ? m_system_apps : m_system_apps_w;
}

QStringList QemuCore::systems()
{
    QStringList system_names;

    for(int i=0; i<m_system_apps.count(); i++)
    {
        system_names << m_system_apps[i]->name().replace("qemu-system-", "");
    }

    return system_names;
}

QSharedPointer<App> QemuCore::systemByName(const QString &name, bool show_console)
{
    QVector<QSharedPointer<App>> *system_apps = show_console ? &m_system_apps : &m_system_apps_w;

    for(int i=0; i<system_apps->count(); i++)
    {
        QSharedPointer<App> system_app = system_apps->at(i);
        if(system_app->name().contains(QString("qemu-system-%1").arg(name)))
        {
            return system_app;
        }
    }

    return nullptr;
}
