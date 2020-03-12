#include "editor_escenario_grafico.h"
#include "editor_defines.h"
#include "editor_bloque_de_roca.h"
#include "editor_personaje_chell.h"
#include "editor_bloque_de_metal.h"
#include "editor_boton.h"
#include "editor_receptor.h"
#include "editor_compuerta_and.h"
#include "editor_compuerta_or.h"
#include "editor_compuerta_regular.h"
#include "editor_pastel.h"
#include "editor_acido.h"
#include "editor_roca.h"
#include "editor_barrera_de_energia.h"
#include "editor_bloque_de_metal_diagonal.h"
#include "editor_emisor.h"

#include <QPixmap>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QtMath>
#include <QKeyEvent>
#include <QMessageBox>

EscenarioGrafico::EscenarioGrafico() : spinBoxX(nullptr),
                                       spinBoxY(nullptr),
                                       celdas(QUANTITY_CELLS),
                                       idClassACrear(IDCLASS_NULL),
                                       cantidadChells(0),
                                       cantidadPasteles(0)
{
    for (int i = 0; i < this->celdas.size(); ++i)
    {
        this->celdas[i].setPosicion(i);
    }
}

EscenarioGrafico::~EscenarioGrafico()
{
}

void EscenarioGrafico::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->scenePos().x() < 0 ||
         event->scenePos().x() > WINDOWS_SIZE_W) ||
        (event->scenePos().y() < 0 ||
         event->scenePos().y() > WINDOWS_SIZE_H - 1))
    {
        return;
    }

    if (event->buttons() & Qt::LeftButton)
    {
        QGraphicsScene::mouseMoveEvent(event);
        this->moverItem(event->scenePos());
    }
    else
    {
        this->crearItem(event->scenePos());
    }
    this->spinBoxX->setValue(event->scenePos().x());
    this->spinBoxY->setValue(event->scenePos().y());
}

void EscenarioGrafico::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    this->crearItem(event->scenePos());
    this->spinBoxX->setValue(event->scenePos().x());
    this->spinBoxY->setValue(event->scenePos().y());
}

void EscenarioGrafico::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Backspace && !this->selectedItems().isEmpty())
    {
        QGraphicsItem *qItem = this->selectedItems().front();
        QPointF posicion = qItem->scenePos();
        ItemGrafico *itemGrafico = (this->getCelda(posicion)).liberar();

        if (itemGrafico->getIdClass() == IDCLASS_BOTON ||
            itemGrafico->getIdClass() == IDCLASS_RECEPTOR)
        {
            ComponenteCompuerta *componente;
            componente = (ComponenteCompuerta *)itemGrafico;
            this->componentesCompuerta.removeOne(componente);
            for (int i = 0; i < this->compuertas.size(); i++)
            {
                this->compuertas[i]->eliminar(componente);
            }
        }
        else if (itemGrafico->getIdClass() == IDCLASS_COMPUERTA_REG ||
                 itemGrafico->getIdClass() == IDCLASS_COMPUERTA_OR ||
                 itemGrafico->getIdClass() == IDCLASS_COMPUERTA_AND)
        {
            Compuerta *compuerta = (Compuerta *)itemGrafico;
            this->compuertas.removeOne(compuerta);
        }

        this->removeItem(qItem);
        delete itemGrafico;
    }
    else
    {
        QGraphicsScene::keyPressEvent(event);
    }
}

void EscenarioGrafico::crearItem(const QPointF posicion)
{
    ItemGrafico *item;
    if (this->idClassACrear == IDCLASS_NULL ||
        this->getCelda(posicion).ocupada() ||
        (posicion.x() < 0 || posicion.x() > WINDOWS_SIZE_W) ||
        (posicion.y() < 0 || posicion.y() > WINDOWS_SIZE_H))
    {
        return;
    }
    else if (this->idClassACrear == IDCLASS_CHELL)
    {
        item = new PersonajeChell(this->cantidadChells);
    }
    else if (this->idClassACrear == IDCLASS_BLOQUE_ROCA)
    {
        item = new BloqueDeRoca();
    }
    else if (this->idClassACrear == IDCLASS_BLOQUE_METAL)
    {
        item = new BloqueDeMetal();
    }
    else if (this->idClassACrear == IDCLASS_BOTON)
    {
        Boton *boton = new Boton();
        this->componentesCompuerta.append(boton);
        for (int i = 0; i < this->compuertas.size(); ++i)
        {
            this->compuertas[i]->agregar(boton);
        }
        item = boton;
    }
    else if (this->idClassACrear == IDCLASS_RECEPTOR)
    {
        Receptor *receptor = new Receptor();
        this->componentesCompuerta.append(receptor);
        for (int i = 0; i < this->compuertas.size(); ++i)
        {
            this->compuertas[i]->agregar(receptor);
        }
        item = receptor;
    }
    else if (this->idClassACrear == IDCLASS_COMPUERTA_REG)
    {
        Compuerta *compuerta = new CompuertaRegular();
        compuerta->agregar(this->componentesCompuerta);
        this->compuertas.append(compuerta);
        item = compuerta;
    }
    else if (this->idClassACrear == IDCLASS_COMPUERTA_AND)
    {
        Compuerta *compuerta = new CompuertaAND();
        compuerta->agregar(this->componentesCompuerta);
        this->compuertas.append(compuerta);
        item = compuerta;
    }
    else if (this->idClassACrear == IDCLASS_COMPUERTA_OR)
    {
        Compuerta *compuerta = new CompuertaOR();
        compuerta->agregar(this->componentesCompuerta);
        this->compuertas.append(compuerta);
        item = compuerta;
    }
    else if (this->idClassACrear == IDCLASS_PASTEL)
    {
        item = new Pastel(this->cantidadPasteles);
    }
    else if (this->idClassACrear == IDCLASS_ACIDO)
    {
        item = new Acido();
    }
    else if (this->idClassACrear == IDCLASS_ROCA)
    {
        item = new Roca();
    }
    else if (this->idClassACrear == IDCLASS_BARRERA_HORIZONTAL)
    {
        item = new BarreraDeEnergia(IDCLASS_BARRERA_HORIZONTAL);
    }
    else if (this->idClassACrear == IDCLASS_BARRERA_VERTICAL)
    {
        item = new BarreraDeEnergia(IDCLASS_BARRERA_VERTICAL);
    }
    else if (this->idClassACrear == IDCLASS_DIAGONAL_0)
    {
        item = new BloqueDeMetalDiagonal(IDCLASS_DIAGONAL_0);
    }
    else if (this->idClassACrear == IDCLASS_DIAGONAL_90)
    {
        item = new BloqueDeMetalDiagonal(IDCLASS_DIAGONAL_90);
    }
    else if (this->idClassACrear == IDCLASS_DIAGONAL_180)
    {
        item = new BloqueDeMetalDiagonal(IDCLASS_DIAGONAL_180);
    }
    else if (this->idClassACrear == IDCLASS_DIAGONAL_270)
    {
        item = new BloqueDeMetalDiagonal(IDCLASS_DIAGONAL_270);
    }
    else if (this->idClassACrear == IDCLASS_EMISOR_0)
    {
        item = new Emisor(IDCLASS_EMISOR_0);
    }
    else if (this->idClassACrear == IDCLASS_EMISOR_90)
    {
        item = new Emisor(IDCLASS_EMISOR_90);
    }
    else if (this->idClassACrear == IDCLASS_EMISOR_180)
    {
        item = new Emisor(IDCLASS_EMISOR_180);
    }
    else if (this->idClassACrear == IDCLASS_EMISOR_270)
    {
        item = new Emisor(IDCLASS_EMISOR_270);
    }

    this->agregarACeldas(item, posicion);
}

void EscenarioGrafico::moverItem(const QPointF posicion)
{
    for (int i = 0; i < this->celdas.size(); ++i)
    {
        if (this->celdas[i].abandonado())
        {
            if ((this->getCelda(posicion)).libre())
            {
                (this->getCelda(posicion)).ocupar(this->celdas[i].liberar());
            }
            else
            {
                this->celdas[i].recapturar();
            }
        }
    }
}

void EscenarioGrafico::setSpinBox(QSpinBox *spinBoxX_, QSpinBox *spinBoxY_)
{
    this->spinBoxX = spinBoxX_;
    this->spinBoxY = spinBoxY_;
}

void EscenarioGrafico::setFondoEscenario(std::string direccion, QSize tamanio)
{
    this->fondoEscenario = direccion;
    this->tamanio = tamanio;
    QPixmap nuevoFondo(direccion.c_str());
    nuevoFondo = nuevoFondo.scaled(tamanio);
    QBrush fondo(nuevoFondo);
    this->setBackgroundBrush(fondo);
}

void EscenarioGrafico::setIdClassACrear(unsigned idClass)
{
    this->idClassACrear = idClass;
}

CeldaGrafica &EscenarioGrafico::getCelda(QPointF posicion)
{
    int i = qFloor(posicion.x() / CELL_SIZE_W);
    int j = qFloor(posicion.y() / CELL_SIZE_H);
    int columnas = qFloor(WINDOWS_SIZE_W / CELL_SIZE_W);
    int k = columnas * j + i;
    return this->celdas[k];
}

void EscenarioGrafico::guardar(YAML::Node &nodo)
{
    QString advertencia(
        "Existen inconsistencias en el escenario que desea guardar:\n");
    QString inconsistencias;
    if (this->cantidadChells == 0)
    {
        inconsistencias += "- Deberia existir al menos una Chell\n";
    }
    if (this->cantidadPasteles > 1 || this->cantidadPasteles == 0)
    {
        inconsistencias += "- Deberia existir un solo Pastel\n";
    }
    for (int i = 0; i < this->compuertas.size(); i++)
    {
        if (!this->compuertas[i]->tieneReglasBienDefinidas())
        {
            inconsistencias +=
                "- Las compuertas deberian tener al menos un elemento en su";
            inconsistencias +=
                "logica.\n Y en el caso de las compuertas regulares, solo uno.";
            break;
        }
    }

    if (!inconsistencias.isEmpty())
    {
        advertencia += inconsistencias;
        advertencia += "\n";
        advertencia += "Aun asi, ¿Desea guardar el Escenario?\n";
        QMessageBox::StandardButton respuesta;
        respuesta = QMessageBox::question(nullptr,
                                          "Advertencia",
                                          advertencia,
                                          QMessageBox::Yes | QMessageBox::No);
        if (respuesta == QMessageBox::No)
        {
            return;
        }
    }

    nodo["escenario"]["pathFondoEscenario"] = this->fondoEscenario;
    nodo["escenario"]["tamanioAncho"] = this->tamanio.width();
    nodo["escenario"]["tamanioAlto"] = this->tamanio.height();
    nodo["escenario"]["cantidadCeldas"] = this->celdas.size();
    for (int i = 0; i < this->celdas.size(); ++i)
    {
        nodo["celdas"][i]["ocupado"] = this->celdas[i].ocupada();
        this->celdas[i].guardar(nodo);
    }
}

void EscenarioGrafico::abrir(YAML::Node &nodo)
{
    this->fondoEscenario = nodo["escenario"]["pathFondoEscenario"].as<std::string>();
    this->tamanio.setWidth(nodo["escenario"]["tamanioAncho"].as<int>());
    this->tamanio.setHeight(nodo["escenario"]["tamanioAlto"].as<int>());
    if (!this->fondoEscenario.empty())
    {
        QPixmap nuevoFondo(this->fondoEscenario.c_str());
        nuevoFondo = nuevoFondo.scaled(this->tamanio);
        QBrush fondo(nuevoFondo);
        this->setBackgroundBrush(fondo);
    }
    for (int i = 0; i < this->celdas.size(); ++i)
    {
        if (nodo["celdas"][i]["ocupado"].as<bool>())
        {
            this->idClassACrear = nodo["celdas"][i]["idClass"].as<int>();
            this->crearItem(this->celdas[i].getPosicionRelativaEscenario());
            this->celdas[i].abrir(nodo);
        }
    }
    for (int i = 0; i < this->compuertas.size(); i++)
    {
        this->compuertas[i]->abrirComponentes(nodo);
    }
}

void EscenarioGrafico::agregarACeldas(ItemGrafico *item, QPointF posicion)
{

    this->addItem(item);
    item->setPos((this->getCelda(posicion)).getPosicionRelativaEscenario());
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setFlag(QGraphicsItem::ItemIsSelectable);
    (this->getCelda(posicion)).ocupar(item);
}
