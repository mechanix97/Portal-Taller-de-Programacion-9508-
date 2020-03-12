#include "../include/accepter.h"

Accepter::Accepter(const char *port){
    this->socket.bindAndListen(port);
    this->keep_running = true;
}

Accepter::~Accepter(){
    for(auto it :  this->games){
        delete it.second;
    }
    for(PlayerLogin* pl: this->logins){
        if(pl != nullptr){
            pl->join();
            delete pl;
        }
    }
}

void Accepter::run() {
    try {
        while (this->keep_running) {
            Socket peer = this->socket.accept();

            if(this->keep_running){//detengo las partidas terminadas
                for(auto it : this->games){
                    if(it.second->isFinished()){
                        it.second->stop();
                        this->games.erase(it.first);
                        delete it.second;
                    }
                }

                PlayerLogin* playerLogin = new PlayerLogin(&this->games,std::move(peer));
                playerLogin->start();
                this->logins.push_back(playerLogin);

                //cierro los login terminados
                for(uint32_t i = 0; i < this->logins.size(); ++i ){
                    if(this->logins[i] != nullptr &&
                        this->logins[i]->isJoinable()){
                        this->logins[i]->join();
                        delete this->logins[i];
                        this->logins[i] = nullptr;
                    }
                }
            }
        }
    } catch (const ConnectionErrorException &e) {
    }
    for(auto it :  this->games){
        it.second->stop();
    }
}

void Accepter::stop() {
    this->keep_running = false;
    this->socket.close();
}
