# 🌱 Intellectual Plant Pot (Smart Arduino Planter)

Interaktywna, "żywa" doniczka oparta na **Arduino Uno**, wyposażona w czujnik wilgotności gleby, monitor temperatury otoczenia oraz ekran OLED z emocjonalnym interfejsem ASCII.

Projekt został zaprojektowany w wariancie **całkowicie bezlutowcowym (solder-free)**, wykorzystującym precyzyjne łączenie przewodów za pomocą skręcania i koszulek termokurczliwych.

---

## 🚀 Główne funkcje
* **Żywy UI (ASCII Expressions):** Doniczka komunikuje swój stan za pomocą animowanych minek na ekranie OLED (`^.^`, `T_T`, `O_O`, `-_-`).
* **Monitorowanie temperatury:** Sprawdza temperaturę w pokoju za pomocą czujnika DHT11.
* **Kalibrowany czujnik gleby:** Pojemnościowy czujnik wilgotności skalibrowany pod rzeczywiste warunki glebowe (odczyty: powietrze ~595, woda ~213).
* **Bezpieczny montaż mechaniczny:** Połączenia zrealizowane bez użycia lutownicy, trwale zabezpieczone koszulkami termokurczliwymi.

---

## 🛠️ Użyte komponenty
* Arduino Uno
* Ekran OLED 0.96" I2C (128x64)
* Czujnik temperatury i wilgotności powietrza DHT11
* Pojemnościowy czujnik wilgotności gleby
* Przewody połączeniowe, koszulki termokurczliwe

---

## 📊 Kalibracja czujnika gleby
Czujnik został przeskalowany do następujących progów:
* **Sucho (powietrze):** ~595
* **Idealnie (podlana ziemia):** 350 – 530
* **Mokro (w wodzie):** < 350

---

## 💻 Podłączenie (Wiring)
| Komponent | Pin / Szyna w module | Pin w Arduino Uno |
| :--- | :--- | :--- |
| **OLED** | VCC / GND | Szyna Zasilania (VIN) / GND |
| | SCL / SDA | A5 / A4 |
| **DHT11** | VCC / GND | Szyna Zasilania (VIN) / GND |
| | DATA | Pin cyfrowy 2 |
| **Czujnik gleby** | VCC / GND | Szyna Zasilania (VIN) / GND |
| | AO (Analog Out) | Pin analogowy A0 |

---

## 📸 Podgląd projektu
<img width="1536" height="2048" alt="doniczka1" src="https://github.com/user-attachments/assets/d2377fc4-923b-43c6-91c5-661270e1fb5f" />
<img width="1536" height="2048" alt="doniczka2" src="https://github.com/user-attachments/assets/92e70456-5e6c-4aee-8657-63f986ff150a" />
<img width="1536" height="2048" alt="doniczka3" src="https://github.com/user-attachments/assets/734437bd-09cf-487b-b109-ae76ea61a67b" />
<img width="1536" height="2048" alt="doniczka4" src="https://github.com/user-attachments/assets/6914b51c-2219-49e0-80c5-9c53730bc4bf" />



