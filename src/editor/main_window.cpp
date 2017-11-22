#include "main_window.hpp"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);

    ui->tabWidget->setTabText(0, "Block");
    ui->tabWidget->setTabText(1, "Attribute");
}

MainWindow::~MainWindow()
{
    delete ui;
}
