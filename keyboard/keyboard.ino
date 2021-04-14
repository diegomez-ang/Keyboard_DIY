//#include <Keyboard.h>
#include <HID-Project.h>
#include <HID-Settings.h>

//----- Pines del encoder -----

#define encoder_input_clock 1
#define encoder_input_DT 2
#define encoder_switch 3

//----- Define botones -----

#define button_1 4
#define button_2 5
#define button_3 6
#define button_4 7
#define button_5 8
#define button_6 9
#define button_7 10
#define button_8 11

int estadoActualClock;
int estadoAnteriorClock;


void setup() {
  // definiendo pines del encoder

  pinMode(encoder_input_clock,INPUT);
  pinMode(encoder_input_DT,INPUT);
  pinMode(encoder_switch,INPUT_PULLUP);

  pinMode(button_1, INPUT_PULLUP);
  pinMode(button_2, INPUT_PULLUP);
  pinMode(button_3, INPUT_PULLUP);
  pinMode(button_4, INPUT_PULLUP);
  pinMode(button_5, INPUT_PULLUP);
  pinMode(button_6, INPUT_PULLUP);
  pinMode(button_7, INPUT_PULLUP);
  pinMode(button_8, INPUT_PULLUP);

  Consumer.begin();
  Keyboard.begin();
  Serial.begin(9600);
}
void loop() {

  //----- Silenciar pc -----
    if(digitalRead(encoder_switch) == LOW){
    Consumer.write(MEDIA_VOLUME_MUTE);
    delay(200);   
  }
 ///----- Encoder -----

    estadoActualClock = digitalRead(encoder_input_clock); //lee el estado del clock

    if(estadoActualClock != estadoAnteriorClock){ //compara
        if(digitalRead(encoder_input_DT) != estadoActualClock){
            Consumer.write(MEDIA_VOLUME_UP);                         
          }
          else{
            Consumer.write(MEDIA_VOLUME_DOWN);
            }
      }
      estadoAnteriorClock = estadoActualClock;
//-------------- Configuracion de teclas --------------

/* 1 - Desbloquear pc.
   2 - Bloquear pc.
   3 - Ctrl + v.
   4 - Win + E.
   5 - Ctrl + X.
   6 - Vacio.
   7 - Ctrl + C.
   8 - Vacio.
*/

// ------ BLOQUEAR ------
  if(digitalRead(button_2)== LOW){
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('l');
    Keyboard.releaseAll();
    delay(200);
    } 

// ------ PEGAR ------
  if(digitalRead(button_3)== LOW){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('V');
    Keyboard.releaseAll();
    delay(200);
    } 
// ------ CORTAR ------
  if(digitalRead(button_5)== LOW){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('X');
    Keyboard.releaseAll();
    delay(200);
    } 
// ------ COPIAR ------
  if(digitalRead(button_7)== LOW){
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    Keyboard.releaseAll();
    delay(200);
    }

 
}
