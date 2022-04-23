#include "shell.h"

QString localOSPath(QString path)
{
    return (SHELL_OS == ShellOS::Windows) ? path.replace("/", "\\") : path;
}
