#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editor_defines.h"
#include "editor_ajustes.h"

#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <QSize>
#include <QString>
#include <yaml-cpp/yaml.h>
#include <fstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow),
                                          escenario(new EscenarioGrafico())
{
    this->ui->setupUi(this);
    this->ui->graphicsView->setScene(this->escenario);

    //dibujamos grilla
    for (int i = 0; i < WINDOWS_SIZE_W; i += CELL_SIZE_W)
    {
        this->escenario->addLine(i, 0, i, WINDOWS_SIZE_H, QPen(Qt::gray));
    }
    for (int i = 0; i < WINDOWS_SIZE_H; i += CELL_SIZE_H)
    {
        this->escenario->addLine(0, i, WINDOWS_SIZE_W, i, QPen(Qt::gray));
    }

    //seteamos spinbox
    //QSize size = this->ui->graphicsView->size();
    QSize size(WINDOWS_SIZE_W, WINDOWS_SIZE_H);
    this->escenario->setSceneRect(0, 0, size.width(), size.height());

    this->ui->spinBoxX->setMinimum(INT_MIN);
    this->ui->spinBoxX->setMaximum(INT_MAX);
    this->ui->spinBoxY->setMinimum(INT_MIN);
    this->ui->spinBoxY->setMaximum(INT_MAX);
    this->escenario->setSpinBox(this->ui->spinBoxX, this->ui->spinBoxY);
}

MainWindow::~MainWindow()
{
    delete this->escenario;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    //TODO
}

void MainWindow::on_actionFondo_triggered()
{
    QSize size(WINDOWS_SIZE_W, WINDOWS_SIZE_H);
    QString path = QFileDialog::getOpenFileName(this, "Abrir");
    if (path.isEmpty())
    {
        return;
    }
    this->escenario->setFondoEscenario(path.toStdString(), size);
}

void MainWindow::on_actionGuardar_Escenario_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Guardar");
    if (path.isEmpty())
    {
        return;
    }

    YAML::Node nodo;
    this->escenario->guardar(nodo);
    std::ofstream salida((path.toStdString()).c_str());
    salida << nodo;
    salida.close();
}

void MainWindow::on_actionAbrir_Escenario_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, "Abrir");
    if (path.isEmpty())
    {
        return;
    }
    try
    {
        YAML::Node nodo = YAML::LoadFile((path.toStdString()).c_str());
        this->escenario->abrir(nodo);
    }
    catch (YAML::Exception &e)
    {
        QMessageBox::critical(this, "Error al abrir",
                              "Puede que el archivo este vacio o corrupto");
    }
}

void MainWindow::on_actionNuevo_Escenario_triggered()
{
    delete this->escenario;
    this->escenario = new EscenarioGrafico();
    this->ui->graphicsView->setScene(this->escenario);

    //dibujamos grilla
    for (int i = 0; i < WINDOWS_SIZE_W; i += CELL_SIZE_W)
    {
        this->escenario->addLine(i, 0, i, WINDOWS_SIZE_H, QPen(Qt::gray));
    }
    for (int i = 0; i < WINDOWS_SIZE_H; i += CELL_SIZE_H)
    {
        this->escenario->addLine(0, i, WINDOWS_SIZE_W, i, QPen(Qt::gray));
    }

    //seteamos spinbox
    QSize size(WINDOWS_SIZE_W, WINDOWS_SIZE_H);
    this->escenario->setSceneRect(0, 0, size.width(), size.height());

    this->ui->spinBoxX->setMinimum(INT_MIN);
    this->ui->spinBoxX->setMaximum(INT_MAX);
    this->ui->spinBoxY->setMinimum(INT_MIN);
    this->ui->spinBoxY->setMaximum(INT_MAX);
    this->escenario->setSpinBox(this->ui->spinBoxX, this->ui->spinBoxY);
}
void MainWindow::on_actionPastel_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_PASTEL);
}

void MainWindow::on_actionPersonaje_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_CHELL);
}

void MainWindow::on_actionBloque_de_Roca_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_BLOQUE_ROCA);
}

void MainWindow::on_actionBloque_de_Metal_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_BLOQUE_METAL);
}

void MainWindow::on_actionBoton_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_BOTON);
}

void MainWindow::on_actionReceptor_Original_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_RECEPTOR);
}

void MainWindow::on_actionAcido_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_ACIDO);
}

void MainWindow::on_actionCompuerta_Regular_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_COMPUERTA_REG);
}

void MainWindow::on_actionCompuerta_AND_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_COMPUERTA_AND);
}

void MainWindow::on_actionCompuerta_OR_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_COMPUERTA_OR);
}

void MainWindow::on_actionRoca_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_ROCA);
}

void MainWindow::on_actionBarrera_Horizontal_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_BARRERA_HORIZONTAL);
}

void MainWindow::on_actionBarrera_Vertical_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_BARRERA_VERTICAL);
}

void MainWindow::on_actionBloqueOriginal_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_DIAGONAL_0);
}

void MainWindow::on_actionBloqueRotado_90_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_DIAGONAL_90);
}

void MainWindow::on_actionBloqueRotado_180_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_DIAGONAL_180);
}

void MainWindow::on_actionBloqueRotado_270_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_DIAGONAL_270);
}

void MainWindow::on_actionEmisorOriginal_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_EMISOR_0);
}

void MainWindow::on_actionEmisor_Rotado_90_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_EMISOR_90);
}

void MainWindow::on_actionEmisor_Rotado_180_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_EMISOR_180);
}

void MainWindow::on_actionEmisor_Rotado_270_triggered()
{
    this->escenario->setIdClassACrear(IDCLASS_EMISOR_270);
}

void MainWindow::on_actionBloque_de_Metal_en_Diagonal_triggered()
{
}

void MainWindow::on_actionEmisor_de_Energia_triggered()
{
}

void MainWindow::on_actionReceptor_de_Energia_triggered()
{
}

void MainWindow::on_actionAjustes_y_configuracion_triggered()
{
    Ajustes ajustes;
    ajustes.setModal(true);
    ajustes.exec();
}
