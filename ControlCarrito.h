
class ControlCarrito {
private:
  int llantaDerechaAdelante;
  int llantaIzquierdaAdelante;
  int llantaDerechaAtras;
  int llantaIzquierdaAtras;
  int potenVelocidad;
  int maxValue;
public:
  int D1;
  int D2;
  int D3;
  int D4;
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

  /* SEGUIDOR DE LINEA */

  void sensoresInit(int D1, int D2, int D3, int D4) {
    this->D1 = D1;
    this->D2 = D2;
    this->D3 = D3;
    this->D4 = D4;
  }

  void setMaxValue(int value) {
    this->maxValue = value;
  }

  int convertToDigital(int sensorValue) {
    return (sensorValue < this->maxValue) ? 0 : 1;
  }
  /* CONTROLES DE LOS MOTORES */

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