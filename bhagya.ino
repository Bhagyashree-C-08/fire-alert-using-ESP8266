#define BLYNK_TEMPLATE_ID "TMPL3mqdTOhNu"
#define BLYNK_TEMPLATE_NAME "fire1"
#define BLYNK_AUTH_TOKEN "IcA-CWG2OyxO6aWQ3gr0UQmV90hpr7E9"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

// WiFi credentials
char auth[] = BLYNK_AUTH_TOKEN;
const char* ssid = "OnePlus Nord CE ";
const char* password = "anitha@2210";

// Telegram credentials
#define BOTtoken "7409616492:AAEMe8wIvJYZerMXrOsIXFGhubn1VUpOxhs"
#define CHAT_ID "7479853040"

// Pins
const int flameSensorPin = A0;  // Analog pin for flame sensor

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

int threshold = 37;  // Base threshold value
bool flameDetected = false; // Flag to track flame detection state

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org");
  client.setTrustAnchors(&cert);

  // Initialize WiFi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(5);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Initialize Blynk
  Blynk.begin(auth, ssid, password);

  // Send startup messages to Telegram
  bot.sendMessage(CHAT_ID, "Wifi Connected!", "");
  bot.sendMessage(CHAT_ID, "Flame Detection System has Started!!", "");
}

void loop() {
  Blynk.run();

  // Read flame sensor value
  int flameLevel = analogRead(flameSensorPin);

  // Calculate the percentage difference from the threshold
  float percentage = ((float)(threshold - flameLevel) / threshold) * 100;

  // Check if flame is detected (1% above the threshold)
  if (flameLevel < threshold * 0.99) {
    if (!flameDetected) {  // Flame detected for the first time
      flameDetected = true;
      Blynk.virtualWrite(V0, 255); // Turn on the virtual LED

      // Send message with the calculated percentage
      String message = "Flame Detected! Virtual LED turned ON. Flame level is " + String(percentage, 2) + "% below the threshold.";
      bot.sendMessage(CHAT_ID, message, "");
    }
  } else {
    if (flameDetected) {  // Flame no longer detected
      flameDetected = false;
      Blynk.virtualWrite(V0, 0); // Turn off the virtual LED
      bot.sendMessage(CHAT_ID, "Flame no longer detected. Virtual LED turned OFF.", "");
    }
  }

  delay(1000); // Wait for a second before the next measurement
}
