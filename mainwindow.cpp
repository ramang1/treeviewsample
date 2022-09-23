#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customModel = new CustomModel();
    customModel->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    customModel->setRootPath(QDir::rootPath());
    customModel->setResolveSymlinks(true);
    ui->treeView->setModel(customModel);
    for (int i = 1; i < customModel->columnCount(); ++i)
        ui->treeView->hideColumn(i);
}

MainWindow::~MainWindow()
{
    delete ui;
}

