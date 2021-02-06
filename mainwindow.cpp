#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_Caso1_clicked()
{


canond=new canonD(ui->valordistancia->value(),ui->valoralturacd->value());
scene->addItem(canond);
canono=new canonO(ui->valordistancia->value(),ui->valoralturaco->value());
scene->addItem(canono);
//scene->removeItem(canond);
//scene->removeItem(canono);

}

void MainWindow::on_Caso2_clicked()
{
    canond=new canonD(ui->valordistancia->value(),ui->valoralturacd->value());
    scene->addItem(canond);
    canono=new canonO(ui->valordistancia->value(),ui->valoralturaco->value());
    scene->addItem(canono);

}

void MainWindow::on_Caso3_clicked()
{
    canond=new canonD(ui->valordistancia->value(),ui->valoralturacd->value());
    scene->addItem(canond);
    canono=new canonO(ui->valordistancia->value(),ui->valoralturaco->value());
    scene->addItem(canono);
}

void MainWindow::on_Caso4_clicked()
{
    canond=new canonD(ui->valordistancia->value(),ui->valoralturacd->value());
    scene->addItem(canond);
    canono=new canonO(ui->valordistancia->value(),ui->valoralturaco->value());
    scene->addItem(canono);
}

void MainWindow::on_Caso5_clicked()
{
    canond=new canonD(ui->valordistancia->value(),ui->valoralturacd->value());
    scene->addItem(canond);
    canono=new canonO(ui->valordistancia->value(),ui->valoralturaco->value());
    scene->addItem(canono);
}


