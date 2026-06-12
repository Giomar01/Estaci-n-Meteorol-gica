#include "SensorAmbiental.h"

SensorAmbiental::SensorAmbiental(int pin) : Sensor(pin, "Sensor de Temperatura y Humedad Relativa"), dht(pin, DHT11) {
    this->temperatura = 0.0;
    this->humedad = 0.0;
    this->dht.begin(); // IMPORTANTE: Activa el pin y la comunicación entre el DHT11 y la ESP32
}

SensorAmbiental::~SensorAmbiental() {
    // Destructor vacío, no hay recursos dinámicos que liberar
}

float SensorAmbiental::getTemperatura() const {
    return this->temperatura;
}

void SensorAmbiental::setTemperatura(float temperatura) {
    this->temperatura = temperatura;
}

float SensorAmbiental::getHumedad() const {
    return this->humedad;
}

void SensorAmbiental::setHumedad(float humedad) {
    this->humedad = humedad;
}

void SensorAmbiental::leerDatos() {
    // Lectura de valores mediante pin digital del sensor DHT11
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    this->setHumedad(h);
    this->setTemperatura(t);

    if (getTemperatura() && getHumedad()) {
        // Impresión Serial
        Serial.print("Temperatura: ");
        Serial.print(getTemperatura());
        Serial.println(" °C");
        Serial.print("Humedad Ambiental: ");
        Serial.print(getHumedad());
        Serial.println(" %");
    }

    // Verificación de lecturas válidas
    if (isnan(h) || isnan(t)) {
        Serial.println("Error en la lectura del sensor DHT11");
        return;
    }
}

string SensorAmbiental::obtenerDatosFormateados() {
    char buffer[30];
    sprintf(buffer, "T: %.1f H: %.0f%%", this->temperatura, this->humedad);
    return string(buffer);
}