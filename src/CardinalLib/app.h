#ifndef APP_H
#define APP_H

#include <QObject>
#include <QString>
#include <QProcess>

class App: public QObject
{
    Q_OBJECT
public:
    App(QString name);
    ~App();
    bool exists();
    QString location();
    QString containing_folder();
    QString lookup_error();
    QString name();
    void run(QStringList args = QStringList(), QString working_directory = "");

private:
    QString m_name;
    QString m_app_location;
    QString m_lookup_error;
    QString m_working_dir;
    QProcess *lookup_process;
};
#endif // APP_H
