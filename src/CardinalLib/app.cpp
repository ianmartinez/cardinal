#include "app.h"
#include "shell.h"

#include <QSharedPointer>
#include <QProcess>
#include <QFile>
#include <QDir>

App::App(QString name)
{
    lookup_process = new QProcess();
    m_name = name;
    lookup_process->start(SHELL_NAME, QStringList() << COMMAND_ARG << SHELL_LOOKUP_APP << name);

    if(lookup_process->waitForFinished())
    {
        QString output = lookup_process->readAllStandardOutput();
        QStringList results = output.split(OS_NEW_LINE);
        m_app_location = results.isEmpty() ? "" : results.first();
    }
}

App::~App()
{
    delete lookup_process;
}

bool App::exists()
{
    return QFile::exists(m_app_location);
}

QString App::location()
{
    return m_app_location;
}

QString App::containing_folder()
{

    QFileInfo app_file(m_app_location);

    if(app_file.exists())
    {
        QString app_path = app_file.dir().absolutePath();
        return localOSPath(app_path);
    }

    return "";
}

QString App::lookup_error()
{
    return m_lookup_error;
}

QString App::name()
{
    return m_name;
}

void App::run(QStringList args, QString working_directory)
{
    QProcess *app_process = new QProcess();

     if(!working_directory.isEmpty())
    {
        app_process->setWorkingDirectory(working_directory);
    }

    app_process->start(m_app_location, args);
}
