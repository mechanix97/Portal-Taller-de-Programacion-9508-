#include "../include/player.h"

static bool ends_with(std::string const & value, std::string const & ending){
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

Player::Player(Socket socket):
    protocol(std::move(socket)),
    inputReceiver(protocol),
    updateSender(protocol,&this->updates) {
}

Player::~Player(){}

void Player::stop(){    
    try{
        this->protocol.close();
    } catch (const ConnectionErrorException &e){

    }
    this->inputReceiver.stop();
    this->updateSender.stop();
    this->updateSender.join();
    this->inputReceiver.join();   
}

void Player::start() {
    this->inputReceiver.start();
    this->updateSender.start();
}

void Player::setDisconnecterPtr(Disconnecter* disconecter){
    this->inputReceiver.setDisconnecterPtr(disconecter);    
}

void Player::sendChellIdToClient(uint32_t id) const{
    this->protocol.sendQuad(id);
}

void Player::setInputPtr(ProtectedQueue<Action>* ptr){
	this->inputReceiver.setInputPtr(ptr);
}

ProtectedQueue<Update>* Player::getUpdatesPtr(){
    return &this->updates;
}

void Player::pushBackUpdate(Update update){
    this->updates.push(update);
}

void Player::sendGamesList(const std::list<GameInfo>& games){
    this->protocol.sendQuad(games.size());
    for(GameInfo gi: games){
        this->protocol.sendGameInfo(gi);
    }
}

void Player::sendMapList(){
    std::list<std::string> maps;
    DIR* dirp;
    struct dirent *directory;
    dirp = opendir(MAP_SAVE_ROUTE);
    if (dirp){
        while ((directory = readdir(dirp)) != NULL){
            if(ends_with(std::string(directory->d_name),
                std::string(".yaml"))){
                std::string map = std::string(directory->d_name); 
                map = map.substr(0, map.size()-5);
                maps.push_back(map);
            }            
        }
        closedir(dirp);
    }   
    this->protocol.sendQuad(maps.size());    
    for(std::string str : maps){
        this->protocol.sendLine(str);
    }
}

void Player::sendByte(uint8_t byte) const{
    this->protocol.sendByte(byte);
}

uint8_t Player::receiveByte() const{
    return this->protocol.receiveByte();
}

uint32_t Player::receiveQuad() const{
    return this->protocol.receiveQuad();   
}

std::string Player::receiveLine() const{
    return this->protocol.receiveLine();
}

void Player::sendBackground(const std::string& str) const{
    this->protocol.sendLine(str);
}