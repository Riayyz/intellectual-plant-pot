#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Konfiguracja ekranu OLED (128x64)
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 ekran(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Konfiguracja czujnika temperatury DHT11 (pin 2)
#define DHTPIN 2     
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

// Pin analogowy dla czujnika gleby
const int soilPin = A0; 

// Zmienna do animacji mrugania oczami
bool mrugniecie = false;

void setup() {
  pinMode(soilPin, INPUT);

  dht.begin();
  
  if(!ekran.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(1); // Zatrzymaj program, jeśli ekran nie odpowiada
  }
  
  ekran.clearDisplay();
  ekran.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Pobieramy dane ze sensorów
  float temp = dht.readTemperature();
  int soilValue = analogRead(soilPin);

  // --- EKRAN 1: Temperatura w pokoju (wyświetlana przez 5 sekund) ---
  ekran.clearDisplay();
  ekran.setTextSize(1);
  ekran.setCursor(0, 0);
  ekran.print("STATUS: POKOJ");
  ekran.drawLine(0, 10, 128, 10, WHITE);

  ekran.setTextSize(1);
  ekran.setCursor(0, 22);
  ekran.print("Temperatura:");

  ekran.setTextSize(2);
  ekran.setCursor(0, 38);
  if (isnan(temp)) {
    ekran.print("Blad");
  } else {
    ekran.print(temp);
    ekran.print(" C");
  }
  ekran.display();
  delay(5000); // 5 sekund przerwy


  // --- EKRAN 2: Wilgotność gleby z animowaną minką (wyświetlana przez 5 sekund) ---
  // 10 iteracji po 0.5 sekundy = 5 sekund całkowitego czasu wyświetlania
  for (int i = 0; i < 10; i++) {
    ekran.clearDisplay();
    
    ekran.setTextSize(1);
    ekran.setCursor(0, 0);
    ekran.print("STATUS: KWIATEK");
    ekran.drawLine(0, 10, 128, 10, WHITE);

    ekran.setTextSize(1);
    ekran.setCursor(0, 20);
    
    // Przełączamy stan mrugania co pół sekundy
    mrugniecie = !mrugniecie;

    // Progi oparte na Twoich testach (Powietrze: 595, Podlane: ~500, Woda: 213)
    if (soilValue > 530) {
      // --- SMUTNA MINKA (SUCHO) ---
      ekran.print("Suszy mnie :C(");
      ekran.setTextSize(3);
      ekran.setCursor(20, 35);
      if (mrugniecie) {
        ekran.print("T_T"); 
      } else {
        ekran.print("-_-"); 
      }
    } 
    else if (soilValue >= 350 && soilValue <= 530) {
      // --- UŚMECHNIĘTA MINKA (IDEALNIE) ---
      ekran.print("Ideolo C:");
      ekran.setTextSize(3);
      ekran.setCursor(25, 35);
      if (mrugniecie) {
        ekran.print("^.^"); 
      } else {
        ekran.print("-.-"); 
      }
    } 
    else {
      // --- ZASKOCZONA MINKA (MOKRO) ---
      ekran.print("Mokro mi");
      ekran.setTextSize(3);
      ekran.setCursor(25, 35);
      if (mrugniecie) {
        ekran.print("O_O"); 
      } else {
        ekran.print("-_-"); 
      }
    }

    ekran.display();
    delay(500); 
  }
}
