#include "Sensor.h"

Sensor::Sensor(int pin, string tipo)
{
    this->pin = pin;
    this->tipoSensor = tipo;
}

int Sensor::getPin() const {
    return this->pin;
}

void Sensor::setPin(int pin) {
    this->pin = pin;
}

string Sensor::getTipoSensor() const {
    return this->tipoSensor;
}

void Sensor::setTipoSensor(string tipo) {
    this->tipoSensor = tipo;
}