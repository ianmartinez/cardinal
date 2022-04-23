#ifndef SHELL_H
#define SHELL_H

#include <QString>

/***
 * OS-Specific details about the shell.
 */

enum class ShellOS {
    Windows,
    MacOS,
    Linux,
    Unix
};

#ifdef Q_OS_WINDOWS
constexpr ShellOS SHELL_OS = ShellOS::Windows;
constexpr const char *SHELL_NAME = "cmd.exe";
#elif Q_OS_DARWIN
constexpr ShellOS SHELL_OS = ShellOS::MacOS;
constexpr const char *SHELL_NAME = "zsh";
#elif Q_OS_LINUX
const ShellOS SHELL_OS = ShellOS::Linux;
static constexpr const char *SHELL_NAME = "sh";
#else
const ShellOS SHELL_OS = ShellOS::Unix;
static constexpr const char *SHELL_NAME = "sh";
#endif

#ifdef Q_OS_UNIX
const bool SHELL_IS_UNIX = true;
static constexpr const char *COMMAND_ARG = "-c";
static constexpr const char *SHELL_LOOKUP_APP = "which";
static constexpr const char *SHELL_NEW_LINE = "\\\n";
static constexpr const char *OS_NEW_LINE = "\n";
#else
const bool SHELL_IS_UNIX = false;
constexpr const char *COMMAND_ARG = "/c";
constexpr const char *SHELL_LOOKUP_APP = "where";
static constexpr const char *SHELL_NEW_LINE = "^\r\n";
static constexpr const char *OS_NEW_LINE = "\r\n";
#endif

QString localOSPath(QString path);

#endif // SHELL_H
