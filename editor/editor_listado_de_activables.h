#ifndef EDITOR_LISTADO_DE_ACTIVABLES_H
#define EDITOR_LISTADO_DE_ACTIVABLES_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QString>
#include <QComboBox>
#include <QMap>
#include "editor_componente_compuerta.h"
#include "editor_item_logica.h"

namespace Ui
{
class ListadoDeActivables;
}

class ListadoDeActivables : public QDialog
{
    Q_OBJECT
private:
    QMap<ComponenteCompuerta *, item_logica_t> *logica;

public:
    explicit ListadoDeActivables(QWidget *parent = 0);
    ~ListadoDeActivables();
    void setLogica(QMap<ComponenteCompuerta *, item_logica_t> *logica_);

private slots:
    void on_cajaBotones_accepted();
    void on_cajaBotones_rejected();

private:
    Ui::ListadoDeActivables *ui;
};

#endif // EDITOR_LISTADO_DE_ACTIVABLES_H
