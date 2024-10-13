#include <EEPROM.h>
#include "GravityTDS.h"

// Pin yang digunakan untuk sensor TDS
#define TdsSensorPin 27 // Pin ADC yang digunakan untuk membaca TDS

// Objek GravityTDS
GravityTDS gravityTds;

// Suhu yang digunakan untuk kompensasi (default 25°C)
float temperature = 25;

// Nilai TDS yang dihitung
float tdsValue = 0;

void setup() {
  Serial.begin(115200); // Mulai komunikasi serial pada 115200 bps

  // Inisialisasi pin sensor TDS
  gravityTds.setPin(TdsSensorPin);

  // Atur referensi tegangan ADC (default 3.3V)
  gravityTds.setAref(3.3);

  // Atur rentang ADC (4096 untuk 10-bit)
  gravityTds.setAdcRange(4096);

  // Mulai inisialisasi sensor TDS
  gravityTds.begin();
}

void loop() {
  // Baca dan hitung nilai TDS
  gravityTds.update();

  // Ambil nilai TDS yang telah dikompensasi
  tdsValue = gravityTds.getTdsValue();

  // Cetak nilai TDS dalam ppm
  Serial.print("Nilai TDS: ");
  Serial.print(tdsValue, 0);
  Serial.println(" ppm");

  // Tunggu selama 1 detik sebelum membaca ulang
  delay(1000);
}