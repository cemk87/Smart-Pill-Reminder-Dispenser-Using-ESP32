#include <Wire.h>
#include <RTClib.h>
#include <ESP32Servo.h> // ✅ For ESP32 boards

// Hardware pins (adjust to match Wokwi wiring)
#define BUZZER_PIN 25
#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define BUTTON_PIN 14
#define SERVO_PIN 17

RTC_DS3231 rtc;
Servo pillServo; // From ESP32Servo library

// Pill schedule (HH, MM)
int pillHours[]   = {9, 13, 22};  // Example: 9 AM, 1 PM, 8 PM
int pillMinutes[] = {0, 0, 30};
bool pillGiven[3] = {false, false, false};

bool reminderActive = false;
unsigned long reminderStart = 0;
unsigned long reminderTimeout = 10000; // 10s for simulation

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  pillServo.attach(SERVO_PIN);
  pillServo.write(0); // closed

  Serial.println("Smart Pill Dispenser Simulation Started");
}

void loop() {
  DateTime now = rtc.now();
  Serial.printf("Time: %02d:%02d:%02d\n", now.hour(), now.minute(), now.second());

  for (int i = 0; i < 3; i++) {
    if (now.hour() == pillHours[i] && now.minute() == pillMinutes[i] && !pillGiven[i]) {
      triggerReminder(i);
    }
  }

  if (reminderActive) {
    if (digitalRead(BUTTON_PIN) == LOW) {
      stopReminder();
    } else if (millis() - reminderStart > reminderTimeout) {
      missedDoseAlert();
    }
  }

  delay(1000);
}

void triggerReminder(int index) {
  Serial.println("Pill Time! Triggering reminder...");
  digitalWrite(RED_LED_PIN, HIGH);
  tone(BUZZER_PIN, 1000);
  pillServo.write(90); // open
  reminderActive = true;
  reminderStart = millis();
  pillGiven[index] = true;
}

void stopReminder() {
  Serial.println("Pill taken. Stopping reminder.");
  noTone(BUZZER_PIN);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, HIGH);
  pillServo.write(0); // close
  delay(2000);
  digitalWrite(GREEN_LED_PIN, LOW);
  reminderActive = false;
}

void missedDoseAlert() {
  Serial.println("⚠ Missed dose! Sending alert.");
  noTone(BUZZER_PIN);
  digitalWrite(RED_LED_PIN, LOW);
  pillServo.write(0);
  reminderActive = false;
}
