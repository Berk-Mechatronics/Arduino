Arduino Projects Collection

This repository contains a collection of Arduino-based sensor, actuator, and control examples that I developed while learning embedded systems, sensor interfacing, and basic robotics.
Each folder includes a simple .ino sketch demonstrating how to read various sensors, control motors, or generate PWM signals.

The projects cover a wide range of modules commonly used in electronics, automation, and mechatronics.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
📂 Project List & Descriptions

A simple example that reads analog input values from the ADC pins and prints them to the Serial Monitor.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

A project demonstrating the use of the DHT11 temperature and humidity sensor.
Shows how to read humidity, temperature (°C), and print the results via serial.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Reads the position of a rotary encoder by counting pulses.
Useful for robotics, motors, and angular measurement tasks.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

A single-channel encoder reading example for basic pulse counting.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Interface to the HX711 load cell amplifier, commonly used in digital weighing scales.
Reads force/weight values from a load cell.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Reads analog temperature values from the LM35 analog temperature sensor and converts them to °C.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Motor control using a Pololu motor driver + encoder feedback.
Includes basic closed-loop motor reading.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Simple PWM (Pulse Width Modulation) examples showing how to control LED brightness or motor speed using analogWrite().
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Writes encoder pulse information to the serial monitor.
Useful for debugging encoders.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Reads data from an analog force-sensitive resistor (FSR).
Demonstrates how pressure/weight affects analog voltage output.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Reads light intensity using a photoresistor (LDR) and prints analog values.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Basic DC motor control using a motor driver (L298N or similar).
Demonstrates forward, reverse, and speed control.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

General-purpose digital pin reading/writing example (e.g., controlling LEDs or reading buttons).
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

A combined or larger project where multiple components were integrated.
This folder contains a renamed main.ino showing a more complex application.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

A simple digital thermometer project using an analog temperature sensor.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🛠️ Technologies & Components Used

Arduino UNO / Nano

Digital sensors (DHT11, Rotary Encoder)

Analog sensors (LM35, LDR, FSR, Thermistor)

Load cell with HX711

DC motors, Pololu motor drivers

PWM control

Serial communication
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🎯 Purpose of This Repository

This repository documents my progress in:

Embedded systems

Sensor reading and calibration

Motor control and PWM

Arduino programming fundamentals

Basic IoT and mechatronics tasks

It can also serve as sample code for beginners who want to learn Arduino through real examples.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
🚀 How to Use

Open any folder of interest

Load the .ino file into the Arduino IDE

Select the correct board & COM port

Upload to your device

Open the Serial Monitor (if required)
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
📄 License

This project is open-source. Feel free to use, modify, and learn from it.
