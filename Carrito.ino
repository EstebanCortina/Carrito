#include "ControlCarrito.h"
#define llantaDerechaAdelante 11
#define llantaIzquierdaAdelante 6
#define llantaDerechaAtras 10
#define llantaIzquierdAAtras 5
#define potenVelocidad A5


#define btnDerecha 4
#define btnAdelante 3
#define btnIzquierda 2

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
  pinMode(btnDerecha, INPUT);
  pinMode(btnAdelante, INPUT);
  pinMode(btnIzquierda, INPUT);
}

void loop() {
  /*
  int velocidad = carrito.obtenerVelocidad();
  Serial.println(velocidad);

  int estadoDerecha = !digitalRead(btnDerecha);
  int estadoAdelante = !digitalRead(btnAdelante);
  int estadoIzquierda = !digitalRead(btnIzquierda);
 

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
  Serial.println(carrito.convertToDigital(analogRead(carrito.D4)));
  delay(200);
}
