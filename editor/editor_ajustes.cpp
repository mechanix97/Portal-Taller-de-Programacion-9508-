#include "editor_ajustes.h"
#include "ui_editor_ajustes.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

#define CONFIG_CUSTOM "../config/config.yaml"

//VALORES DEFAULT
#define BLOCK_FRICTION 0.5
#define BULLET_MAX_LIFE_STEPS 200
#define BULLET_SPEED 10.0
#define BUTTON_FRICTION 0.7
#define CHELL_JUMPSPEED 5
#define CHELL_MAX_HORIZONTAL_SPEED 4
#define CHELL_HORIZONTAL_SPEED 1.2
#define CHELL_RAY_ZOOM 10000
#define LAUNCHER_STEPS_PER_LAUNCH 50
#define PIN_TIME 60
#define STAGE_MAP_PATH "../maps/"
#define WORLD_GRAVITY_X 0
#define WORLD_GRAVITY_Y -9.8
#define GAMELOOP_FPS 120

Ajustes::Ajustes(QWidget *parent) : QDialog(parent),
                                    ui(new Ui::Ajustes)
{
    ui->setupUi(this);

    this->ui->friccionBloques->setMinimum(INT_MIN);
    this->ui->maximoAlcanceBalas->setMinimum(INT_MIN);
    this->ui->velocidadBalas->setMinimum(INT_MIN);
    this->ui->friccionBotones->setMinimum(INT_MIN);
    this->ui->velocidadSaltarChell->setMinimum(INT_MIN);
    this->ui->maximaVelocidadCorrerChell->setMinimum(INT_MIN);
    this->ui->velocidadCaminarChell->setMinimum(INT_MIN);
    this->ui->rayZoomChell->setMinimum(INT_MIN);
    this->ui->stepsPerLauncher->setMinimum(INT_MIN);
    this->ui->timePin->setMinimum(INT_MIN);
    this->ui->gravedadWorld->setMinimum(INT_MIN);
    this->ui->fpsGameloop->setMinimum(INT_MIN);

    this->ui->friccionBloques->setMaximum(INT_MAX);
    this->ui->maximoAlcanceBalas->setMaximum(INT_MAX);
    this->ui->velocidadBalas->setMaximum(INT_MAX);
    this->ui->friccionBotones->setMaximum(INT_MAX);
    this->ui->velocidadSaltarChell->setMaximum(INT_MAX);
    this->ui->maximaVelocidadCorrerChell->setMaximum(INT_MAX);
    this->ui->velocidadCaminarChell->setMaximum(INT_MAX);
    this->ui->rayZoomChell->setMaximum(INT_MAX);
    this->ui->stepsPerLauncher->setMaximum(INT_MAX);
    this->ui->timePin->setMaximum(INT_MAX);
    this->ui->gravedadWorld->setMaximum(INT_MAX);
    this->ui->fpsGameloop->setMaximum(INT_MAX);

    this->ui->friccionBloques->setValue(BLOCK_FRICTION);
    this->ui->maximoAlcanceBalas->setValue(BULLET_MAX_LIFE_STEPS);
    this->ui->velocidadBalas->setValue(BULLET_SPEED);
    this->ui->friccionBotones->setValue(BUTTON_FRICTION);
    this->ui->velocidadSaltarChell->setValue(CHELL_JUMPSPEED);
    this->ui->maximaVelocidadCorrerChell->setValue(CHELL_MAX_HORIZONTAL_SPEED);
    this->ui->velocidadCaminarChell->setValue(CHELL_HORIZONTAL_SPEED);
    this->ui->rayZoomChell->setValue(CHELL_RAY_ZOOM);
    this->ui->stepsPerLauncher->setValue(LAUNCHER_STEPS_PER_LAUNCH);
    this->ui->timePin->setValue(PIN_TIME);
    this->ui->mapPathStage->setText(STAGE_MAP_PATH);
    this->ui->gravedadWorld->setValue(WORLD_GRAVITY_Y);
    this->ui->fpsGameloop->setValue(GAMELOOP_FPS);
}

Ajustes::~Ajustes()
{
    delete ui;
}

void Ajustes::on_buttonBox_accepted()
{
    YAML::Node nodo;
    nodo["block"]["friction"] = this->ui->friccionBloques->value();

    nodo["bullet"]["max_life_steps"] = this->ui->maximoAlcanceBalas->value();
    nodo["bullet"]["speed"] = this->ui->velocidadBalas->value();

    nodo["button"]["friction"] = this->ui->friccionBotones->value();

    nodo["chell"]["jumpspeed"] = this->ui->velocidadSaltarChell->value();
    nodo["chell"]["max_horizontal_speed"] =
        this->ui->maximaVelocidadCorrerChell->value();
    nodo["chell"]["horizontal_speed"] =
        this->ui->velocidadCaminarChell->value();
    nodo["chell"]["ray_zoom"] = this->ui->rayZoomChell->value();

    nodo["launcher"]["steps_per_launch"] =
        this->ui->stepsPerLauncher->value();

    nodo["pin"]["time"] = this->ui->timePin->value();

    nodo["stage"]["map_path"] =
        (this->ui->mapPathStage->text()).toStdString();

    nodo["world"]["gravity_y"] = this->ui->gravedadWorld->value();
    nodo["world"]["gravity_x"] = 0;

    nodo["gameloop"]["fps"] = this->ui->fpsGameloop->value();

    std::ofstream configuracion(CONFIG_CUSTOM);
    configuracion << nodo;
    configuracion.close();
}

void Ajustes::on_buttonBox_rejected()
{
}

void Ajustes::on_pushButton_clicked()
{
    this->ui->friccionBloques->setValue(BLOCK_FRICTION);
    this->ui->maximoAlcanceBalas->setValue(BULLET_MAX_LIFE_STEPS);
    this->ui->velocidadBalas->setValue(BULLET_SPEED);
    this->ui->friccionBotones->setValue(BUTTON_FRICTION);
    this->ui->velocidadSaltarChell->setValue(CHELL_JUMPSPEED);
    this->ui->maximaVelocidadCorrerChell->setValue(CHELL_MAX_HORIZONTAL_SPEED);
    this->ui->velocidadCaminarChell->setValue(CHELL_HORIZONTAL_SPEED);
    this->ui->rayZoomChell->setValue(CHELL_RAY_ZOOM);
    this->ui->stepsPerLauncher->setValue(LAUNCHER_STEPS_PER_LAUNCH);
    this->ui->timePin->setValue(PIN_TIME);
    this->ui->mapPathStage->setText(STAGE_MAP_PATH);
    this->ui->gravedadWorld->setValue(WORLD_GRAVITY_Y);
    this->ui->fpsGameloop->setValue(GAMELOOP_FPS);
}
