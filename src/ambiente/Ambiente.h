#ifndef __AMBIENTE_H__
#define __AMBIENTE_H__

#include "../agente/Agente.h"
#include "../formas/Formas.h"

class Ambiente{

    public:
        Vector2 tela;
        int w, h;
        float mx, my;
        Forma *eixos[3];
        Agente agente;
        Ambiente(int w, int h);
        void render();
        std::vector<Forma> formas;
        void action(int key);
};














#endif