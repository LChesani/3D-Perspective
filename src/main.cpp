#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ambiente/Ambiente.h"

int screenWidth = 600, screenHeight = 600; //largura e altura inicial da tela . Alteram com o redimensionamento de tela.
int mouseX, mouseY; //variaveis globais do mouse para poder exibir dentro da render().
bool clicking = false;
float prevX = 0, prevY = 0;
Ambiente *ambiente = nullptr;
Vector3 ini = Vector3(0, 0, 0); //evitar divisão por zero
Vector3 cursor = Vector3(0, 0, 0);
//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis globais
//Todos os comandos para desenho na canvas devem ser chamados dentro da render().
//Deve-se manter essa fun��o com poucas linhas de codigo.

float ang = 0.0f;
float x = 0, y = 0, z = 0;
int cresX = 1;
int cresY = 1;
int cresZ = 1;
void render(){
   
   x = 12 * cos(ang);
   y = 12 * cos(ang);
   z = 12 * sin(ang);

   CV::translate(ambiente->tela.x, ambiente->tela.y);
   


      float diff = ambiente->formas[0].pos.z - ambiente->agente.pos.z;
      
      Matriz c1[] = {

         Matriz().transl(0.0f, -20.0f, -12.0f),
         Matriz().persp(diff),
         Matriz().transl(-ambiente->agente.pos.x, -ambiente->agente.pos.y, -ambiente->agente.pos.z),

         Matriz().vis(ambiente->agente.pos, cursor, Vector3(0, 1, 0))
      };

      ambiente->formas[0].m.transform(c1, 4);

   diff = ambiente->formas[1].pos.z - ambiente->agente.pos.z;
   Matriz c2[]{
      Matriz().rot(ang, ang, 0),
      Matriz().transl(0.0f, 0.0f, -20.0f),
      
      Matriz().persp(diff),
      Matriz().transl(-ambiente->agente.pos.x, -ambiente->agente.pos.y, -ambiente->agente.pos.z),

      Matriz().vis(ambiente->agente.pos, cursor, Vector3(0, 1, 0))
   };

   ambiente->formas[1].m.transform(c2, 5);

   diff = ambiente->formas[2].pos.z - ambiente->agente.pos.z;

   Matriz c3[]{
      Matriz().rot(ang, ang, ang),
      Matriz().transl(0.0f, 0.0f, -20.0f),
      Matriz().transl(x, y, z),
      
   
      
      Matriz().persp(diff),
      Matriz().transl(-ambiente->agente.pos.x, -ambiente->agente.pos.y, -ambiente->agente.pos.z),

      Matriz().vis(ambiente->agente.pos, cursor, Vector3(0, 1, 0))
   };

   ambiente->formas[2].m.transform(c3, 6);
   ambiente->render();
   ang+=0.001f;
}

//funcao chamada toda vez que uma tecla for pressionada.
void keyboard(int key){
   ambiente->action(key);
}

//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key){}

void mouse(int button, int state, int wheel, int direction, int x, int y){
   if(clicking){
      int deltaX = x - prevX;
      int deltaY = y - prevY;
      
      cursor.x = deltaX;
      cursor.y = deltaY;
   }
   if(state == 0){
      prevX = x;
      prevY = y;
      clicking = true;
   }
   if(state == 1){
      clicking = false;
   }
}


float func(float x, float y){
   return x*x + y*y;
}

int main(void){
   ambiente = new Ambiente(screenWidth, screenHeight);

   Forma f1 = Forma(20, ini);
   Forma f2 = Forma(20, ini);
   Forma f3 = Forma(20, ini);
   //f.funcao(-10.0f, 10.0f, func);
   //f.esfera(25);
   //f.funcao(-10, 10, func);
   f1.superficie();
   f2.esfera(10);
   f3.esfera(3);
   ambiente->formas.push_back(f1);
   ambiente->formas.push_back(f2);
   ambiente->formas.push_back(f3);

   CV::init(&screenWidth, &screenHeight, "cachorro");

   CV::run();
}
