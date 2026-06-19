#include "EstacionMeteorologica.h"
#include "SensorAmbiental.h"
#include "SensorSuelo.h"
#include "SensorLuz.h"
#include "SensorAire.h"
#include "PantallaLCD.h"

// 1. Declaración de objetos globales a través de punteros para permitir su inicialización en setup()
PantallaLCD* pantallaLCD = nullptr;
EstacionMeteorologica* estacionMetereologica = nullptr;

// Definición de pines
const int BTN_IZQ = 18;
const int BTN_DER = 19;

void setup() {
    Serial.begin(115200);

    // 2. Inicialización de la pantalla LCD, la estación meteorológica y pines de botones
    pantallaLCD = new PantallaLCD(0x27, 16, 2);
    pantallaLCD->inicializar();
    pantallaLCD->mostrarMensaje("Iniciando...", "Iniciando...");

    pinMode(BTN_IZQ, INPUT_PULLUP);
    pinMode(BTN_DER, INPUT_PULLUP);

    estacionMetereologica = new EstacionMeteorologica(4, pantallaLCD);

    // 3. Creación de los sensores en la memoria 'heap' de la estación
    estacionMetereologica->agregarSensor(new SensorAmbiental(4)); // Pin digital DHT11
    estacionMetereologica->agregarSensor(new SensorSuelo(34));    // Pin analógico HC69
    estacionMetereologica->agregarSensor(new SensorAire(35));     // Pin analógico MQ135
    estacionMetereologica->agregarSensor(new SensorLuz(33));      // Pin digital LDR
    
    delay(2000);
}

void loop() {
    
    // 4. Actualización de las mediciones y lectura de botones (LOW significa presionado por el PULLUP)
    if (digitalRead(BTN_IZQ) == LOW) {
        estacionMetereologica->anteriorSensor();
        estacionMetereologica->mostrarSensorActual();
        delay(300); // Debounce simple para evitar rebotes
    }
    
    if (digitalRead(BTN_DER) == LOW) {
        estacionMetereologica->siguienteSensor();
        estacionMetereologica->mostrarSensorActual();
        delay(300);
    }
    
    // 5. Actualizar mediciones periódicamente sin cambiar de pantalla
    static unsigned long ultimaActualizacion = 0;
    
    if (millis() - ultimaActualizacion > 2000) { // Actualiza cada 2 segundos
        estacionMetereologica->actualizarMediciones();
        estacionMetereologica->mostrarSensorActual(); // Refresca los datos en pantalla
        ultimaActualizacion = millis();
    }
}