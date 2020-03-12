#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editor_escenario_grafico.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent (QCloseEvent *event) override;
private slots:
    void on_actionBloque_de_Roca_triggered();
    void on_actionBloque_de_Metal_triggered();
    void on_actionAcido_triggered();
    void on_actionBloque_de_Metal_en_Diagonal_triggered();
    void on_actionBoton_triggered();
    void on_actionRoca_triggered();
    void on_actionEmisor_de_Energia_triggered();
    void on_actionReceptor_de_Energia_triggered();
    void on_actionPersonaje_triggered();
    void on_actionFondo_triggered();
    void on_actionGuardar_Escenario_triggered();
    void on_actionAbrir_Escenario_triggered();
    void on_actionPastel_triggered();
    void on_actionBloqueOriginal_triggered();
    void on_actionBloqueRotado_90_triggered();
    void on_actionBloqueRotado_180_triggered();
    void on_actionBloqueRotado_270_triggered();
    void on_actionEmisorOriginal_triggered();
    void on_actionEmisor_Rotado_90_triggered();
    void on_actionEmisor_Rotado_180_triggered();
    void on_actionEmisor_Rotado_270_triggered();
    void on_actionReceptor_Original_triggered();
    void on_actionCompuerta_Regular_triggered();
    void on_actionCompuerta_AND_triggered();
    void on_actionCompuerta_OR_triggered();
    void on_actionBarrera_Horizontal_triggered();
    void on_actionBarrera_Vertical_triggered();
    void on_actionNuevo_Escenario_triggered();

    void on_actionAjustes_y_configuracion_triggered();

private:
    Ui::MainWindow *ui;
    EscenarioGrafico *escenario;
};

#endif // MAINWINDOW_H
