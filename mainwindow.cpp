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
distancia= ui->valordistancia->value();
Hco =ui->valoralturaco->value();
Hcd = ui->valoralturacd->value();
bala = new disparo(distancia,Hco,Hcd);
bala->DisparoOfensivo(1,3);
//scene->addItem(bala);

}

void MainWindow::on_Caso2_clicked()
{

}

void MainWindow::on_Caso3_clicked()
{

}

void MainWindow::on_Caso4_clicked()
{

}

void MainWindow::on_Caso5_clicked()
{

}


