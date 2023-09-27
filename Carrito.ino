#include "ControlCarrito.h"
#define llantaDerechaAdelante 11
#define llantaIzquierdaAdelante 6
#define llantaDerechaAtras 10
#define llantaIzquierdAAtras 5
#define potenVelocidad A5

#define btnModoLinea 4
#define btnModoAutomatico 3
bool lineMode = false;

ControlCarrito carrito(
  llantaDerechaAdelante,
  llantaIzquierdaAdelante,
  llantaDerechaAtras,
  llantaIzquierdAAtras,
  potenVelocidad);

void setup() {
  Serial.begin(9600);
  carrito.init();
  carrito.sensoresInit(A1, A2, A3, A4);
  carrito.setMaxValue(900);
  pinMode(btnModoAutomatico, INPUT);
  pinMode(btnModoAutomatico, INPUT);  
}

void loop() {

  /*
  
  if (estadoDerecha) {
    Serial.println("Derecha");
    carrito.girarDerecha(velocidad);
  } else if (estadoAdelante) {
    Serial.println("Adelante");
    carrito.adelante(velocidad);
  } else if (estadoIzquierda) {
    Serial.println("Izquierda");
    carrito.girarIzquierda(velocidad);
  } else {
    carrito.stop();
  }
*/
  if (isLineMode()) {
    delay(100);
    doLineMode();
  } else {
    delay(100);
    Serial.println("Modo Automatico");
  }

  delay(200);
}

bool isLineMode() {
  int estadoModoLinea = !digitalRead(btnModoLinea);
  int estadoAutomatico = !digitalRead(btnModoAutomatico);

  if (estadoModoLinea) {
    lineMode = true;
  } else if (estadoAutomatico) {
    lineMode = false;
  }  
  return lineMode;
}

void doLineMode(){
  Serial.println("Modo Linea");
    Serial.println(carrito.convertToDigital(analogRead(carrito.D4)));
    int izquierda = carrito.convertToDigital(analogRead(carrito.D4));
    //Quitara el comentario cuando tenga un potenciometro de nuevo. Perdi el de esli jaja
    //int velocidad = carrito.obtenerVelocidad();
    int velocidad = 180;
    Serial.println(velocidad);
    if(izquierda){
      carrito.girarIzquierda(velocidad);
    }else{
      //Cambiar despues stop por adelante      
      carrito.stop();
    }
}