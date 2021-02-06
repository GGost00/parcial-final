#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "canon.h"

#define v_limit 720

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private: // variables
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    Canon *defencivo, *ofencivo;

    std::list<Disparo*> Visualizacion;

public: // variables

private: // methods
    void Dibujar_Disparos(std::vector<Disparo *> Disparos);
    void Mostrar_Disparos(std::vector<Disparo *> Dosparos);
    void Anadir_Disparo(Disparo* Disparo);

    void Limpiar_scene();
    void Limpiar_Lcd();

public: // methods
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Caso1_clicked();
    void on_Caso2_clicked();
    void on_Caso3_clicked();
    void on_Caso4_clicked();
    void on_Caso5_clicked();

    void on_YC1_slider_sliderMoved(int posicion);
    void on_XC2_slider_sliderMoved(int posicion);
    void on_YC2_slider_sliderMoved(int posicion);
};
#endif // MAINWINDOW_H
