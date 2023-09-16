
class ControlCarrito {
public:
  int llantaDerechaAdelante;
  int llantaIzquierdaAdelante;
  int llantaDerechaAtras;
  int llantaIzquierdaAtras;
  int potenVelocidad;

  ControlCarrito(
    int llantaDerechaAdelante,
    int llantaIzquierdaAdelante,
    int llantaDerechaAtras,
    int llantaIzquierdaAtras,
    int potenVelocidad) {
    this->llantaDerechaAdelante = llantaDerechaAdelante;
    this->llantaIzquierdaAdelante = llantaIzquierdaAdelante;
    this->llantaDerechaAtras = llantaDerechaAtras;
    this->llantaIzquierdaAtras = llantaIzquierdaAtras;
    this->potenVelocidad = potenVelocidad;
  }

  void init() {
    pinMode(this->llantaDerechaAdelante, OUTPUT);
    pinMode(this->llantaDerechaAtras, OUTPUT);
    pinMode(this->llantaIzquierdaAdelante, OUTPUT);
    pinMode(this->llantaIzquierdaAtras, OUTPUT);
  }


  int obtenerVelocidad() {
    int velocidad = analogRead(potenVelocidad);
    int velocidadFinal = map(velocidad, 0, 1023, 0, 255);
    return velocidadFinal;
  }
  void stop() {
    analogWrite(this->llantaDerechaAdelante, 0);
    analogWrite(this->llantaDerechaAtras, 0);
    analogWrite(this->llantaIzquierdaAdelante, 0);
    analogWrite(this->llantaIzquierdaAtras, 0);
  }
  void girarDerecha(int velocidad) {
    analogWrite(this->llantaIzquierdaAdelante, velocidad);
    analogWrite(this->llantaDerechaAtras, velocidad);
  }
  void girarIzquierda(int velocidad) {
    analogWrite(this->llantaDerechaAdelante, velocidad);
    analogWrite(this->llantaIzquierdaAtras, velocidad);
  }
  void adelante(int velocidad) {
    analogWrite(this->llantaDerechaAdelante, velocidad);
    analogWrite(this->llantaIzquierdaAdelante, velocidad);
  }
  void atras(int velocidad) {
    analogWrite(this->llantaDerechaAtras, velocidad);
    analogWrite(this->llantaIzquierdaAtras, velocidad);
  }
};