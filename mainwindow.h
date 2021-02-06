#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Caso1_clicked();

    void on_Caso2_clicked();

    void on_Caso5_clicked();

    void on_Caso3_clicked();

    void on_Caso4_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
