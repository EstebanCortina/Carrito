#include "ControlCarrito.h"
#define llantaDerechaAdelante 11
#define llantaIzquierdaAdelante 6
#define llantaDerechaAtras 10
#define llantaIzquierdAAtras 5
#define potenVelocidad A5

#define btnModoLinea 4
#define btnModoAutomatico 3

#define sensorDerecho A1
#define sensorCentroDerecha A2
#define sensorCentroIzquierda A3
#define sensorIzquierdo A4

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
  carrito.sensoresInit(
    sensorDerecho,
    sensorCentroDerecha,
    sensorCentroIzquierda,
    sensorIzquierdo);

  carrito.setMaxValue(900);
  pinMode(btnModoAutomatico, INPUT);
  pinMode(btnModoLinea, INPUT);
}

void loop() {
  //Quitar el comentario cuando tenga un potenciometro de nuevo. Perdi el de esli jaja
  
  //int velocidad = carrito.obtenerVelocidad();
  int velocidad = 180;  
  if (isLineMode()) {
    delay(100);
    doLineMode(velocidad);
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

void doLineMode(int velocidad) {
  Serial.println("Modo Linea");
  int izquierda = carrito.convertToDigital(analogRead(carrito.D4));
  int derecha = carrito.convertToDigital(analogRead(carrito.D1));
  Serial.println(izquierda);

  if (izquierda) {
    carrito.girarDerecha(velocidad);
  } else if(derecha) {
    carrito.girarIzquierda(velocidad);    
  }else{
    //Cambiar despues stop por adelante
    carrito.stop();
  }
}