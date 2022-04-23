#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <CardinalLib/app.h>
#include <CardinalLib/qemu_core.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // test code for finding and running apps
    auto qemu = new QemuCore();
    auto x86 = qemu->systemByName("x86_64");

    if(x86 != nullptr)
    {
        x86->run();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

