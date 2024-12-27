#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

#define DHTPIN D1
#define DHTTYPE DHT11
#define POWER_PIN D2
#define DO_PIN D3  
#define Relay D4
const int moisturePin = A0;

DHT dht(DHTPIN, DHTTYPE);

// Your WiFi credentials
char ssid[] = "";
char pass[] = "";

// Variable to track rain detection state
bool rainDetected = false;

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  dht.begin();
  
  // Initialize WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(POWER_PIN, OUTPUT);  
  pinMode(DO_PIN, INPUT);
}

void loop() {
  Blynk.run(); // Run Blynk

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float moisturePercentage;
  
  // Read rain state
  digitalWrite(POWER_PIN, HIGH); 
  delay(50);  
  int rain_state = digitalRead(DO_PIN);
  digitalWrite(POWER_PIN, LOW);
  
  // Read moisture level
  moisturePercentage = (100.00 - ((analogRead(moisturePin) / 1023.00) * 100.00)) + 40;

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print to serial monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);

  // Control LED on V3 based on rain detection and send notification
  if (rain_state == HIGH) {
    Serial.println("The rain is NOT detected");
    Blynk.virtualWrite(V3, 0); // Turn off LED (no rain detected)
    rainDetected = false; // Reset rain detection state
  } else {
    Serial.println("The rain is detected");
    Blynk.virtualWrite(V3, 255); // Turn on LED (rain detected)
    
    // Send notification if rain detected for the first time
    if (!rainDetected) {
      Blynk.logEvent("rain_detected");  // Trigger event for notification
      rainDetected = true; // Set rain detection state to true
    }
  }

  Serial.print(moisturePercentage);
  Serial.println("%");

  // Send sensor data to Blynk
  Blynk.virtualWrite(V1, h);                    // Virtual pin V1 for Humidity
  Blynk.virtualWrite(V0, t);                    // Virtual pin V0 for Temperature
  Blynk.virtualWrite(V2, moisturePercentage);   // Virtual pin V2 for Soil Moisture
  
  delay(1000); // Delay between sensor readings
}
