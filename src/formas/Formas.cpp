#include "Formas.h"

Forma::Forma(int DIM, Vector3 pos){
    m.init(DIM);

    this->pos = pos;
}


void Forma::render() {
    CV::color(0, 0, 0);
    /*for(int x=0; x<=this->m.DIM; x++){
        for(int z=0; z<=this->m.DIM; z++){
            CV::circleFill(this->m.proj[x][z].x, this->m.proj[x][z].y, 5, 20);
        }
    }*/

    //desenha as arestas
    for(int x=0; x <= this->m.DIM; x++){
        for(int z=0; z <= this->m.DIM; z++){
            m.desc[x][z] = m.desc[x][z] - pos;
        }
    }
    for(int x=0; x < this->m.DIM; x++){
        for(int z=0; z < this->m.DIM; z++){
            CV::line(this->m.proj[x][z].x, this->m.proj[x][z].y, this->m.proj[x+1][z].x, this->m.proj[x+1][z].y );
            CV::line(this->m.proj[x][z].x, this->m.proj[x][z].y, this->m.proj[x][z+1].x, this->m.proj[x][z+1].y );
        }
    }
}


void Forma::elipsoide(int rx, int ry, int rz){
    float theta = -PI;
    
    for(int i = 0; i <= this->m.DIM; i++){
        float phi = -PI/2;
        for(int j = 0; j <= this->m.DIM; j++){
            float x = rx*cos(theta)*cos(phi) + pos.x;
            float z = rz*sin(theta)*cos(phi) + pos.z;
            float y = ry*sin(phi) + pos.y;
            this->m.desc[i][j] = Vector3(x, y, z);
            phi += (PI/2)/this->m.DIM;
        }
        theta += PI/this->m.DIM;
    }
}

void Forma::esfera(int r){
    float theta = 0;
    
    for(int i = 0; i <= this->m.DIM; i++){
        float phi = 0;
        for(int j = 0; j <= this->m.DIM; j++){
            float x = r*cos(theta)*sin(phi) + pos.x;
            float y = r*sin(theta)*sin(phi) + pos.y;
            float z = r*cos(phi) + pos.z;
            this->m.desc[i][j] = Vector3(x, y, z);
            phi += PI/this->m.DIM;
        }
        theta += 2*PI/this->m.DIM;
    }
}

void Forma::cilindro(int r){
    float theta = 0;
    for(int i = 0; i <= this->m.DIM; i++){
        float phi = 0;
        for(int j = 0; j <= this->m.DIM; j++){
            float x = r*cos(theta) + pos.x;
            float y = r*sin(theta) + pos.y;
            float z = r * sin(phi) + pos.z;
            this->m.desc[i][j] = Vector3(x, y, z);
            phi += PI/this->m.DIM;
        }
        theta += 2*PI/this->m.DIM;
    }
}

void Forma::cubo(float lado){
    
}





void Forma::superficie(){
    //geracao de terrenos aleatorios a cada execucao
    srand(time(NULL));

    //cria um terreno centrado na origem
    for(int x=0; x <= m.DIM; x++){
        for(int z=0; z <= m.DIM; z++){
            this->m.desc[x][z].x = x - (float)( this->m.DIM/2.0 ) + pos.x;
            this->m.desc[x][z].y = ( rand()%18 ) / 10.0 + pos.y;
            this->m.desc[x][z].z = z - (float)( this->m.DIM/2.0 ) + pos.z;
        }
    }
}

void Forma::funcao(float ini, float fim, float (*f)(float, float)){
    float x = ini;
    float inc = (fim - ini) / this->m.DIM;
    for(int i=0; i <= this->m.DIM; i++){
        float y = ini;
        for(int j=0; j <= this->m.DIM; j++){
            this->m.desc[i][j].x = x + pos.x;
            this->m.desc[i][j].y = y +  pos.y;
            this->m.desc[i][j].z = f(x, y) + pos.z;
            y += inc;
        }
        x += inc;
    }
}