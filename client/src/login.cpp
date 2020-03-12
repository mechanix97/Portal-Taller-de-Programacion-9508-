#include "../include/login.h"

Login::Login(const ServerManager& sm,std::list<GameInfo> games, std::list<std::string> maps) 
: QDialog(nullptr), serverManager(sm), games(games), maps(maps), tableWidget(0,4), 
exitButton("Salir"), createGameButton("Crear partida"){
	this->createTable();
    this->createComboBox();
    this->setMinimumSize(342, 400);
    QVBoxLayout* verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(30);
    QHBoxLayout* horizontalLayout = new QHBoxLayout();
	verticalLayout->addWidget(&this->tableWidget);
    horizontalLayout->addWidget(&this->comboBox);
    horizontalLayout->addWidget(&this->createGameButton);
    verticalLayout->addLayout(horizontalLayout);
    verticalLayout->addWidget(&this->exitButton);
    this->setLayout(verticalLayout);
    QObject::connect(&this->createGameButton, &QPushButton::clicked,this, &Login::create);
    QObject::connect(&this->exitButton, &QPushButton::clicked,this, &Login::exit);
}

void Login::exit(){
    this->serverManager.sendNoneCommand();
    this->done(1);
}

void Login::join(uint32_t game){
    this->serverManager.joinGame(game);
    if(this->serverManager.receiveByte() == 0){
        this->done(0);
    } else {
        this->done(1);    
    }    
}

void Login::create(){
    if(this->comboBox.currentIndex() != -1){    
        QString qs = this->comboBox.currentText();
        std::string str = qs.toUtf8().constData();
        this->serverManager.createGame(str);
        if(this->serverManager.receiveByte() == 0){
            this->done(0);      
        } else {
            this->done(1);    
        }        
    }    
}

void Login::reject(){
    this->serverManager.sendNoneCommand();
    this->done(1);  
}

void Login::createTable(){
    this->tableWidget.verticalHeader()->hide();
    QStringList horzHeaders;
    horzHeaders<<"id"<<"Mapa"<<"Jugadores"<<"Unirse";
    this->tableWidget.setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tableWidget.setHorizontalHeaderLabels(horzHeaders);
    this->tableWidget.horizontalHeader()->setSectionResizeMode (QHeaderView::Fixed);
    this->tableWidget.setColumnWidth(0,40);
    this->tableWidget.setColumnWidth(1,120);
    this->tableWidget.setColumnWidth(2,80);
    this->tableWidget.setColumnWidth(3,80);
    for(GameInfo gi : games){
        if(gi.getPlayers() < gi.getCapacity()){            
            this->tableWidget.insertRow ( this->tableWidget.rowCount() );

            std::string str = std::to_string(gi.getId());
            QTableWidgetItem * item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 0, item);        
            
            str = gi.getMapName();
            str = str.substr(0, str.size()-5);
            item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 1, item);
            
            str = std::to_string(gi.getPlayers()) + "/" + std::to_string(gi.getCapacity());
            item = new QTableWidgetItem(QString(str.c_str()));
            item->setTextAlignment(Qt::AlignCenter);
            this->tableWidget.setItem   ( this->tableWidget.rowCount()-1, 2, item);

            
            QPushButton *btn = new QPushButton();
            btn->setText("Unirse");
            btn->setVisible(true);
            QObject::connect(btn, &QPushButton::clicked,this, [=]{this->join(gi.getId());});
            this->tableWidget.setCellWidget(this->tableWidget.rowCount()-1,3,btn);
        }
    }
}

void Login::createComboBox(){
    this->comboBox.setEditable(false);
    for(std::string map : this->maps){
        this->comboBox.addItem(QString(map.c_str()));
    }
    this->comboBox.setCurrentIndex(-1);
}
