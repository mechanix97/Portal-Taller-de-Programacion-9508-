#include "editor_listado_de_activables.h"
#include "ui_editor_listado_de_activables.h"
#include "editor_defines.h"
#include <QCheckBox>

#define TIPO 0
#define NOMBRE 1
#define AGREGADO 2
#define NEGADO 3

ListadoDeActivables::ListadoDeActivables(QWidget *parent) : QDialog(parent),
                                                            ui(new Ui::ListadoDeActivables)
{
    ui->setupUi(this);

    //configuramos las columnas
    QTableWidgetItem *tipo = new QTableWidgetItem("Tipo");
    QTableWidgetItem *nombre = new QTableWidgetItem("Nombre");
    QTableWidgetItem *agregar = new QTableWidgetItem("Agregar a la logica");
    QTableWidgetItem *negar = new QTableWidgetItem("Aplicar NOT");

    this->setMinimumSize(DIALOG_SIZE_W, DIALOG_SIZE_H);
    this->setMaximumSize(DIALOG_SIZE_W, DIALOG_SIZE_H);
    this->ui->listado->setColumnCount(4);
    this->ui->listado->setHorizontalHeaderItem(0, tipo);
    this->ui->listado->setHorizontalHeaderItem(1, nombre);
    this->ui->listado->setHorizontalHeaderItem(2, agregar);
    this->ui->listado->setHorizontalHeaderItem(3, negar);

    this->ui->listado->setColumnWidth(0, this->width() / 4);
    this->ui->listado->setColumnWidth(1, this->width() / 4);
    this->ui->listado->setColumnWidth(2, this->width() / 4);
    this->ui->listado->setColumnWidth(3, this->width() / 4);
}

ListadoDeActivables::~ListadoDeActivables()
{
    delete ui;
}
void ListadoDeActivables::on_cajaBotones_accepted()
{
    QList<ComponenteCompuerta *> componentes = this->logica->keys();
    for (int i = 0; i < componentes.size(); i++)
    {
        QCheckBox *agregar =
            (QCheckBox *)this->ui->listado->cellWidget(i, AGREGADO);
        QCheckBox *negar =
            (QCheckBox *)this->ui->listado->cellWidget(i, NEGADO);
        item_logica_t item = this->logica->value(componentes[i]);
        item.es_parte = agregar->isChecked();
        item.esta_negado = negar->isChecked();
        this->logica->insert(componentes[i], item);
    }
}

void ListadoDeActivables::on_cajaBotones_rejected()
{
    //TODO
}

void ListadoDeActivables::setLogica(
    QMap<ComponenteCompuerta *, item_logica_t> *logica_)
{
    this->logica = logica_;
    QList<ComponenteCompuerta *> componentes = this->logica->keys();

    for (int i = 0; i < componentes.size(); i++)
    {
        QString nombre = componentes[i]->getNombre();
        QString tipo = componentes[i]->getTipoStr();
        item_logica_t item = this->logica->value(componentes[i]);

        QCheckBox *agregar = new QCheckBox(this->ui->listado);
        agregar->setChecked(item.es_parte);
        QCheckBox *negar = new QCheckBox(this->ui->listado);
        negar->setChecked(item.esta_negado);
        QTableWidgetItem *tipoItem = new QTableWidgetItem(tipo);
        QTableWidgetItem *nombreItem = new QTableWidgetItem(nombre);

        this->ui->listado->insertRow(this->ui->listado->rowCount());
        this->ui->listado->setItem(this->ui->listado->rowCount() - 1,
                                   TIPO, tipoItem);
        this->ui->listado->setItem(this->ui->listado->rowCount() - 1,
                                   NOMBRE, nombreItem);
        this->ui->listado->setCellWidget(this->ui->listado->rowCount() - 1,
                                         AGREGADO, agregar);
        this->ui->listado->setCellWidget(this->ui->listado->rowCount() - 1,
                                         NEGADO, negar);
    }
}
