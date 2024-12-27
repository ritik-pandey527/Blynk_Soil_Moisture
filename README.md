# IoT-Based Soil Moisture and Rain Detection System with Blynk

## Overview
This project is an IoT-based system that uses various sensors to monitor environmental conditions and send the data to the Blynk app. It includes a soil moisture sensor, a rain detection sensor, and a DHT11 sensor for temperature and humidity. The system also provides real-time updates through the Blynk app and sends notifications when it detects rain.

## Features
- **Temperature and Humidity Monitoring**: Uses a DHT11 sensor to measure environmental temperature and humidity.
- **Soil Moisture Monitoring**: Measures soil moisture levels to determine if irrigation is needed.
- **Rain Detection**: Detects the presence of rain using a rain sensor and provides notifications.
- **Remote Control**: Controls the state of the rain detection system and displays data on the Blynk app.

## Components
- **ESP8266**: Microcontroller for sensor interfacing and Blynk communication.
- **DHT11 Sensor**: Measures temperature and humidity.
- **Soil Moisture Sensor**: Detects soil moisture levels for irrigation decisions.
- **Rain Detection Sensor**: Detects the presence of rain.
- **Relay**: Used to control an external device (like a water pump or irrigation system).
- **LED (Optional)**: Indicates rain detection status.

## Circuit Diagram
1. **DHT11 Sensor**: Connected to pin `D1`.
2. **Soil Moisture Sensor**: Connected to analog pin `A0`.
3. **Rain Detection Sensor**: Connected to digital pin `D3`.
4. **Relay**: Connected to pin `D4`.
5. **LED**: Connected to virtual pin `V3` (for rain detection status).

## Blynk App Setup
- **Template ID**: `TMPL3TfTQd6M7`
- **Template Name**: `ESP8266`
- **Auth Token**: `CrxapjbhPWUVgOj2OBSnGDRQcCG1c4YW`
- Create a new project on the Blynk app and add the virtual pins `V0`, `V1`, `V2`, and `V3` for displaying temperature, humidity, moisture, and rain status.

## Commands and Notifications
- **Rain Detection**: When rain is detected, the system triggers an event (`rain_detected`) on Blynk and sends notifications.
- **Moisture and Temperature/Humidity Data**: Real-time data updates on the Blynk app.

## Installation and Setup
1. Clone this repository to your local machine.
2. Install the required libraries in the Arduino IDE:
   - `DHT`
   - `BlynkSimpleEsp8266`
   - `ESP8266WiFi`
3. Update the following variables with your details:
   - `ssid`: Your Wi-Fi SSID.
   - `pass`: Your Wi-Fi password.
   - `BLYNK_AUTH_TOKEN`: Your Blynk authentication token.
4. Upload the code to your ESP8266 using the Arduino IDE.

## Usage
1. Power up the ESP8266 and ensure it connects to the Wi-Fi network.
2. Open the Blynk app to monitor real-time data.
   - The temperature and humidity will be shown on Virtual Pins `V0` and `V1`.
   - The soil moisture will be shown on Virtual Pin `V2`.
   - The rain detection status will be indicated by the LED on Virtual Pin `V3`.
3. Receive notifications if rain is detected.

## Future Enhancements
- Integrate more environmental sensors for broader monitoring.
- Add support for controlling irrigation systems via Blynk based on moisture levels.
- Implement data logging to track historical sensor readings.
