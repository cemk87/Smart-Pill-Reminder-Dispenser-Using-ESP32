# Smart Pill Reminder using ESP32
A Smart Pill Reminder System built using an ESP32, RTC DS3231, buzzer, LED indicators, pushbutton, and servo motor.

## 🎯 Overview
This project helps patients take their medicine on time by providing both audio and visual reminders. It also tracks whether the user has taken the medicine through a confirmation button.

## 🚀 Features

- Real-time clock tracking using **RTC DS3231**
- **Buzzer** and **LED** alerts at scheduled pill times
- **Red LED** indicates pill due
- **Green LED** confirms pill taken
- **Pushbutton** acknowledgment system
- **Servo motor** simulates pill dispensing
- User-configurable schedule (change time in code)
- Missed-dose alert if button not pressed in time

## 🛠️ Hardware Components

| Component | Description |
|-----------|---------------|
| ESP32 | Microcontroller |
| RTC DS3231 | Real-time clock module |
| BUZZER | Audio alert for pill time |
| RED LED | Indicates pill due |
| GREEN LED | Confirms pill taken |
| PUSH BUTTON | For user confirmation |
| SERVO MOTOR | Simulated pill sidpenser door |
| JUMPER WIRES & BREADBOARD | For connections |

## 🧠 How It Works
    1) The ESP32 continuously reads the time from the RTC DS3231 module.
    2) When the current time matches a scheduled pill time:
          - The buzzer sounds
          - The red LED turns ON
          - The servo motor opens to simulate dispensing
    3) When the patient presses the pushbutton, the system:
          - Stops the buzzer
          - Turns ON the green LED
          - Closes the servo tray
    4) If the button isn’t pressed within 10 seconds, the system triggers a missed-dose alert.

## 🔌 Circuit Connection


| COMPONENTS | ARDUINO UNO | CONNECTION TYPE | DESCRIPTION |
|-----------|---------------|---------------|---------------|
| RED LED | GPIO26 | OUTPUT | Turns ON when it's pill time |
| GREEN LED | GPIO27 | OUTPUT | Indicates medicine taken |
| PUSHBUTTON | GPIO14 | INPUT_PULLUP | Press to confirm pill taken |
| BUZZER | GPIO25 | OUTPUT | Sounds alarm at pill time |
| SERVO MOTOR (SIGNAL PIN) | GPIO17 | PWM OUTPUT | Opens/closes pill tray |
| RTC DS3231-SDA | GPIO21 | I²C DATA LINE | Communicates time data |
| RTC DS3231-SCL | GPIO22 | I²C CLOCK LINE | Synchronizes RTC timing |
| RTC DS3231-VCC | 3.3V | POWER | Powers the RTC module |
| RTC DS3231-GND | GND | GROUND | Common ground connection |

## 💻 Code Overview
                   int pillHours[]   = {9, 13, 22};
                   int pillMinutes[] = {0, 0, 30};
    These arrays define the pill reminder times (9:00 AM, 1:00 PM, and 10:30 PM).
    Modify them as per your medicine schedule.
  
     **Key Functions**-

      - triggerReminder() → Activates buzzer, LED, and servo
      - stopReminder() → Stops alert and confirms intake
      - missedDoseAlert() → Handles unacknowledged reminders

## ⚡ Quick Start
    1. Clone the repository:
       git clone https://github.com/yourusername/Smart-Pill-Reminder-Dispenser-Using-ESP32.git
       cd Smart-Pill-Reminder-Dispenser-Using-ESP32

    2. Instruction:
      - Install Arduino IDE (v2 or newer)
      - Add ESP32 board support via Boards Manager
      - Install required libraries:
                  (i)  RTClib
                  (ii) ESP32Servo
    3. Connect the components as per the table above
    4. Upload the code to your ESP32
    5. Open Serial Monitor at 115200 baud to view logs
      
## 🚀 Future Enhancements
   - Add LCD/OLED display for real-time clock and next dose info.
   - Integrate Wi-Fi & mobile alerts for missed doses.
   - Store schedules in EEPROM/NVS for persistence
   - Add a configuration menu via web or app interface
   

## 🤝 Contributing

Contributions are welcome! Here are ways you can help:

### 🐛 Reporting Bugs
- Open an issue with detailed description
- Include steps to reproduce
- Add relevant code/screenshots

### 💡 Suggesting Enhancements
- Describe the new feature
- Explain the use case
- Consider implementation approach

### 🔧 Code Contributions
    1. Fork the repository
    2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
    3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
    4. Push to the branch (`git push origin feature/AmazingFeature`)
    5. Open a Pull Request

## 🙏 Acknowledgments
     
- Arduino Community for continuous support
- Open-source hardware and software contributors


## 📞 Contact Me
If you have any questions, suggestions, or feedback, feel free to reach out:

 - **Name**: Subhojit Das
 - **Email**: [sd0273469@gmail.com]
 - **LinkedIn**: [linkedin.com/in/yourprofile]
 - **GitHub**: [github.com/yourusername](https://github.com/cemk87)
💡 I’d love to connect and collaborate on exciting projects!
