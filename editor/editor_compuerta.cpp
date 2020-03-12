#include "editor_compuerta.h"
#include "editor_defines.h"
#include "editor_listado_de_activables.h"

Compuerta::Compuerta(QString direccionSprite, unsigned idClass) : ItemGrafico(direccionSprite, idClass)
{
    this->sprite = this->sprite.scaled(CELL_SIZE_W, CELL_SIZE_H * 2);
    this->setPixmap(this->sprite);
}

Compuerta::~Compuerta()
{
}

void Compuerta::eliminar(ComponenteCompuerta *componente)
{
    this->logica.remove(componente);
}

void Compuerta::agregar(ComponenteCompuerta *componente)
{
    item_logica_t item;
    this->logica[componente] = item;
}

void Compuerta::agregar(QList<ComponenteCompuerta *> componentes)
{
    for (int i = 0; i < componentes.size(); i++)
    {
        item_logica_t item;
        this->logica[componentes[i]] = item;
    }
}

void Compuerta::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    ListadoDeActivables listadoDeActivables;
    listadoDeActivables.setLogica(&(this->logica));
    listadoDeActivables.setModal(true);
    listadoDeActivables.exec();
}

void Compuerta::guardar(YAML::Node &nodo)
{
    ItemGrafico::guardar(nodo);

    int j = 0;
    QList<ComponenteCompuerta *> componentes = this->logica.keys();
    for (int i = 0; i < componentes.size(); i++)
    {
        item_logica_t item = this->logica[componentes[i]];
        if (item.es_parte)
        {
            nodo["compuertas"][this->getIdCelda()][j]["idCelda"] =
                componentes[i]->getIdCelda();
            nodo["compuertas"][this->getIdCelda()][j]["idObject"] =
                componentes[i]->getIdCelda();
            nodo["compuertas"][this->getIdCelda()][j]["negado"] =
                item.esta_negado;
            ++j;
        }
    }
    nodo["compuertas"][this->getIdCelda()]["size"] = j;
}

void Compuerta::abrirComponentes(YAML::Node &nodo)
{
    QList<ComponenteCompuerta *> componentes = this->logica.keys();
    int size = nodo["compuertas"][this->getIdCelda()]["size"].as<int>();
    for (int i = 0; i < size; i++)
    {
        int idComponente = nodo["compuertas"][this->getIdCelda()][i]["idCelda"].as<int>();
        bool negado = nodo["compuertas"][this->getIdCelda()][i]["negado"].as<bool>();

        for (int j = 0; j < componentes.size(); j++)
        {
            if (idComponente == componentes[j]->getIdCelda())
            {
                this->logica[componentes[j]].es_parte = true;
                this->logica[componentes[j]].esta_negado = negado;
                break;
            }
        }
    }
}