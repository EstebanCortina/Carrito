#include "ControlCarrito.h"
#define llantaDerechaAdelante 10
#define llantaIzquierdaAdelante 5
#define llantaDerechaAtras 11
#define llantaIzquierdAAtras 6
#define potenVelocidad A5

#define btnModoLinea 4
#define btnModoAutomatico 3

#define sensorDerecho A1
#define sensorCentroDerecha A2
#define sensorCentroIzquierda A3
#define sensorIzquierdo A4

#define trigPin 2
#define echoPin 7

bool lineMode = false;
long duration;
int distance_cm;

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

  carrito.setMaxValue(930);
  pinMode(btnModoAutomatico, INPUT);
  pinMode(btnModoLinea, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop() {
  //Quitar el comentario cuando tenga un potenciometro de nuevo. Perdi el de esli jaja

  //int velocidad = carrito.obtenerVelocidad();
  int velocidad = 255;
  if (isLineMode()) {
    //carrito.stop();
    delay(100);
    doLineMode(velocidad);
  } else {
    delay(100);
    //doAutomaticMode();
    Serial.println("Modo Automatico");
  }
}

bool isLineMode() {
  int estadoModoLinea = !digitalRead(btnModoLinea);
  int estadoAutomatico = !digitalRead(btnModoAutomatico);

  if (estadoModoLinea) {
    lineMode = true;
  } else if (estadoAutomatico) {
    carrito.stop();
    lineMode = false;
  }
  return lineMode;
}

void doLineMode(int velocidad) {
  Serial.println("Modo Linea");

  int izquierda = carrito.convertToDigital(analogRead(A5));
  int derecha = carrito.convertToDigital(analogRead(A2));
  int centro = carrito.convertToDigital(analogRead(A4));
  if (!izquierda && !centro && !derecha) {
    Serial.println("Stop");
    //carrito.stop();    
  }else if (centro) {
    Serial.println("Adelante");
    carrito.stop();
    carrito.adelante(velocidad);
  }else if (!izquierda) {
    Serial.println("Girando a la derecha: ");
    carrito.stop();
    carrito.girarIzquierda(velocidad);
  } else if (!derecha) {
    Serial.println("Girando a la izquierda: ");
    carrito.stop();
    carrito.girarDerecha(velocidad);    
  }
}
void doAutomaticMode() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);

  duration = pulseIn(echoPin, HIGH);
  distance_cm = duration * 0.034 / 2;
Serial.println(distance_cm);
  while (distance_cm < 25) {
    carrito.stop();
    carrito.girarDerecha(255);
    
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);

    duration = pulseIn(echoPin, HIGH);
    distance_cm = duration * 0.034 / 2;
    
    Serial.println(distance_cm);
  }
  carrito.stop();
  carrito.adelante(255);
}