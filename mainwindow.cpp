#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, 1900, 720);

    ofencivo = new Canon(0.05, "o");
    defencivo = new Canon(0.025, "d");

    ofencivo->setPosx(0);
    ofencivo->setPosy(0);
    defencivo->setPosx(100);
    defencivo->setPosy( 0);

    ofencivo->setRadio_Impacto_Enemigo(defencivo->getImpactos_Multiples());
    defencivo->setRadio_Impacto_Enemigo(ofencivo->getImpactos_Multiples());

    ofencivo->setDistancia(defencivo);
    defencivo->setDistancia(ofencivo);

    scene->addItem(ofencivo);
    scene->addItem(defencivo);
}

MainWindow::~MainWindow() {
    delete ofencivo;
    delete defencivo;
    delete scene;

    delete ui;
}

void MainWindow::Dibujar_Disparos(std::vector<Disparo *> Disparos) {

    float dt;

    for(auto k = Disparos.begin(); k != Disparos.end(); k++){

        dt = (*k)->getF_time()/10;

        for(int w = 1; w < 11; w++){
            Visualizacion.push_back(new Disparo((*k)->getX_i(), (*k)->getY_i(), (*k)->getX(), (*k)->getY(), (*k)->getVx(), (*k)->getVy(), (*k)->getAngle(), dt*w, (*k)->getRadio_Impacto(), (*k)->getTipo()));
        }
    }

    for(auto k = Visualizacion.begin(); k != Visualizacion.end(); k++){
        (*k)->set_Posicion_Final();
        scene->addItem(*k);
    }
}
void MainWindow::Anadir_Disparo(Disparo *disparo) {
    float dt;

    dt = disparo->getF_time()/10;

    for(int w = 1; w < 11; w++)
        Visualizacion.push_back(new Disparo(disparo->getX_i(), disparo->getY_i(), disparo->getX(), disparo->getY(), disparo->getVx(), disparo->getVy(), disparo->getAngle(), dt*w, disparo->getRadio_Impacto(), disparo->getTipo()));

    for(auto k = Visualizacion.begin(); k != Visualizacion.end(); k++){
        (*k)->set_Posicion_Final();
        //scene->addItem(*k);
    }
}
void MainWindow::Mostrar_Disparos(std::vector<Disparo *> Disparos) {

    if(Disparos.size() == 3){

        Disparo *primer = Disparos[0], *segundo = Disparos[1], *tercero = Disparos[2];

        ui->angle_lcd1->display(primer->getAngle());
        ui->velocity_lcd1->display(primer->getV0());
        ui->posx_lcd1->display(primer->getX());
        ui->posy_lcd1->display(primer->getY());
        ui->time_lcd1->display(primer->getF_time());

        ui->angle_lcd2->display(segundo->getAngle());
        ui->velocity_lcd2->display(segundo->getV0());
        ui->posx_lcd2->display(segundo->getX());
        ui->posy_lcd2->display(segundo->getY());
        ui->time_lcd2->display(segundo->getF_time());

        ui->angle_lcd3->display(tercero->getAngle());
        ui->velocity_lcd3->display(tercero->getV0());
        ui->posx_lcd3->display(tercero->getX());
        ui->posy_lcd3->display(tercero->getY());
        ui->time_lcd3->display(tercero->getF_time());
    }
    else if(Disparos.size() == 2){

        Disparo *Primero = Disparos[0], *Segundo = Disparos[1];

        ui->angle_lcd1->display(Primero->getAngle());
        ui->velocity_lcd1->display(Primero->getV0());
        ui->posx_lcd1->display(Primero->getX());
        ui->posy_lcd1->display(Primero->getY());
        ui->time_lcd1->display(Primero->getF_time());

        ui->angle_lcd2->display(Segundo->getAngle());
        ui->velocity_lcd2->display(Segundo->getV0());
        ui->posx_lcd2->display(Segundo->getX());
        ui->posy_lcd2->display(Segundo->getY());
        ui->time_lcd2->display(Segundo->getF_time());

        ui->angle_lcd3->display(0);
        ui->velocity_lcd3->display(0);
        ui->posx_lcd3->display(0);
        ui->posy_lcd3->display(0);
        ui->time_lcd3->display(0);
    }
    else if(Disparos.size() == 1){

        Disparo *Primero = Disparos[0];

        ui->angle_lcd1->display(Primero->getAngle());
        ui->velocity_lcd1->display(Primero->getV0());
        ui->posx_lcd1->display(Primero->getX());
        ui->posy_lcd1->display(Primero->getY());
        ui->time_lcd1->display(Primero->getF_time());

        ui->angle_lcd2->display(0);
        ui->velocity_lcd2->display(0);
        ui->posx_lcd2->display(0);
        ui->posy_lcd2->display(0);
        ui->time_lcd2->display(0);

        ui->angle_lcd3->display(0);
        ui->velocity_lcd3->display(0);
        ui->posx_lcd3->display(0);
        ui->posy_lcd3->display(0);
        ui->time_lcd3->display(0);
    }
    else if(Disparos.size() == 0){

        Limpiar_Lcd();
    }
}

void MainWindow::Limpiar_scene() {
    for(auto k = Visualizacion.begin(); k != Visualizacion.end(); ){
        scene->removeItem(*k);
        delete (*k);
        k = Visualizacion.erase(k);
    }

    scene->update();
}
void MainWindow::Limpiar_Lcd() {
    ui->angle_lcd1->display(0);
    ui->velocity_lcd1->display(0);
    ui->posx_lcd1->display(0);
    ui->posy_lcd1->display(0);
    ui->time_lcd1->display(0);

    ui->angle_lcd2->display(0);
    ui->velocity_lcd2->display(0);
    ui->posx_lcd2->display(0);
    ui->posy_lcd2->display(0);
    ui->time_lcd2->display(0);

    ui->angle_lcd3->display(0);
    ui->velocity_lcd3->display(0);
    ui->posx_lcd3->display(0);
    ui->posy_lcd3->display(0);
    ui->time_lcd3->display(0);
}

void MainWindow::on_Caso1_clicked() {

    Limpiar_scene();

    std::vector<Disparo *> Disparos = ofencivo->Generar_Disparos_Ofencivos(defencivo);

    Mostrar_Disparos(Disparos);
    Dibujar_Disparos(Disparos);
}
void MainWindow::on_Caso2_clicked() {

    Limpiar_scene();

    std::vector<Disparo *> Disparos = defencivo->Generar_Disparos_Ofencivos(ofencivo);

    Mostrar_Disparos(Disparos);
    Dibujar_Disparos(Disparos);
}
void MainWindow::on_Caso3_clicked() {

    Limpiar_scene();

    Disparo *s = ofencivo->Generar_Disparos_Ofencivos(defencivo)[0];

    if(defencivo->Impacta (ofencivo, s)){
        Anadir_Disparo(s);

        std::vector<Disparo *> Disparos = defencivo->Generar_Disparos_Defencivos(ofencivo, s, false);

        Mostrar_Disparos(Disparos);
        Dibujar_Disparos(Disparos);
    }
}
void MainWindow::on_Caso4_clicked() {

    Limpiar_scene();

    Disparo *s = ofencivo->Generar_Disparos_Ofencivos(defencivo)[0];

    if(defencivo->Impacta(ofencivo, s)){
        Anadir_Disparo(s);

        std::vector<Disparo *> Disparos = defencivo->Generar_Disparos_Defencivos(ofencivo, s, true);

        Mostrar_Disparos(Disparos);
        Dibujar_Disparos(Disparos);
    }
}
void MainWindow::on_Caso5_clicked() {

    Limpiar_scene();

    Disparo *of = ofencivo->Generar_Disparos_Ofencivos(defencivo)[0];
    Disparo *def = defencivo->Generar_Disparos_Defencivos(ofencivo, of, false)[0];

    std::vector<Disparo *> Disparos = ofencivo->Generar_Contraataque_Ofencivos(defencivo, def, of);

    if(Disparos.size() == 0){

        Limpiar_scene();
        Limpiar_Lcd();
    }
    else{
        Anadir_Disparo(of);
        Anadir_Disparo(def);

        Mostrar_Disparos(Disparos);
        Dibujar_Disparos(Disparos);
    }
}

void MainWindow::on_YC1_slider_sliderMoved(int posicion) {
    ui->YC1_spinBox->setValue(posicion);
    ofencivo->setPosy(ui->YC1_spinBox->value());
    scene->update();
}
void MainWindow::on_XC2_slider_sliderMoved(int posicion) {
    ui->XC2_spinBox->setValue(posicion),
    defencivo->setPosx(ui->XC2_spinBox->value());
    scene->update();
    ofencivo->setDistancia(defencivo);
    defencivo->setDistancia(ofencivo);
}
void MainWindow::on_YC2_slider_sliderMoved(int posicion) {
    ui->YC2_spinBox->setValue(posicion);
    defencivo->setPosy(ui->YC2_spinBox->value());
    scene->update();
}

