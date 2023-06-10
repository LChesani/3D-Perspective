#include "Ambiente.h"
#define SPEED 10



Ambiente::Ambiente(int w, int h){
    this->w = w;
    this->h = h;
    this->agente = Agente();
    tela = Vector2(w/2, h/2);
}

static void eixos(){
    CV::color(0, 0, 0);

}

void Ambiente::render(){
    for(unsigned int i = 0; i < this->formas.size(); i++){
        this->formas[i].render();
    }
}

void Ambiente::action(int key){

    if(key == ' '){
        agente.pos.y += SPEED;
        tela.y -= SPEED;
    }
    else if(key == 'c' || key == 'C'){
        agente.pos.y -= SPEED;
        tela.y += SPEED;
    }
    else if(key == 'a' || key == 'A'){
        agente.pos.x -= SPEED;
        tela.x += SPEED;
    }
    else if(key == 'd' || key == 'D'){
        agente.pos.x += SPEED;
        tela.x -= SPEED;
    }
    else if(key == 's' || key == 'S'){
        agente.pos.z += SPEED;
    }
    else if(key == 'w' || key == 'W'){
        agente.pos.z -= SPEED;
    }
    else if(key == 'p'){
        this->formas[0].m.print();
    }
    else{
        return;
    }

    printf("\n%.2f %.2f %.2f\n", agente.pos.x, agente.pos.y, agente.pos.z);
}
