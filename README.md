Fire Alert System Using ESP8266
This project is a fire detection system that utilizes an ESP8266 microcontroller to monitor flame levels and alert users via Telegram. It also integrates with the Blynk platform to provide real-time monitoring through a virtual LED indicator.

Features
Flame Detection: Monitors flame levels using an analog flame sensor connected to the ESP8266.
Real-Time Alerts: Sends alerts to a specified Telegram chat when a flame is detected or no longer detected.
Blynk Integration: Controls a virtual LED on the Blynk app, indicating flame presence in real-time.
WiFi Connectivity: Connects to a specified WiFi network for internet access and communication with Telegram and Blynk.
Components Required
ESP8266 Microcontroller
Flame Sensor (Analog)
WiFi Network with Internet Access
Setup Instructions
Clone the Repository:

bash
Copy code
git clone https://github.com/yourusername/fire-alert-esp8266.git
cd fire-alert-esp8266
Install Required Libraries:

BlynkSimpleEsp8266
UniversalTelegramBot
ESP8266WiFi
You can install these libraries through the Arduino IDE Library Manager.

Configure the Code:

Open the fire_alert.ino file in the Arduino IDE.
Replace the BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME, and BLYNK_AUTH_TOKEN with your Blynk credentials.
Replace ssid and password with your WiFi network credentials.
Replace BOTtoken and CHAT_ID with your Telegram bot token and chat ID.
Upload the Code:

Connect your ESP8266 to your computer.
Select the correct board and port in the Arduino IDE.
Upload the code to the ESP8266.
Run the System:

Once the code is uploaded, the ESP8266 will connect to the specified WiFi network.
The system will and notify you via Telegram that it's online.
The system will begin monitoring the flame sensor, sending alerts and controlling the Blynk virtual LED based on flame detection.
How It Works
The flame sensor reads the flame level continuously.
If the flame level drops below a specified threshold, the system recognizes it as a flame and sends an alert to the configured Telegram chat.
The Blynk virtual LED is turned on to indicate flame detection.
If the flame level returns to normal (above the threshold), the system sends another alert to Telegram, and the virtual LED is turned off.
Future Enhancements
Temperature Monitoring: Integrate a temperature sensor to complement the flame detection and provide more accurate fire alerts.
IoT Dashboard: Create a dedicated IoT dashboard for real-time monitoring of multiple sensors.
SMS Alerts: Add SMS alert functionality using a third-party service.
