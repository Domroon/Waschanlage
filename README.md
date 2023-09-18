# Waschlange

## Arduino Documentation

https://content.arduino.cc/assets/A000066-full-pinout.pdf

## Servo

https://www.amazon.de/Longruner-Helicopter-Airplane-Controls-KY66-5/dp/B07236KYVC?th=1

- brown -> mass
- red -> +5V
- orange -> PWM

## Display

https://www.az-delivery.de/en/products/1-3zoll-i2c-oled-display

- GND -> GND
- VCC -> +5V
- SCL -> SCL
- SDA -> SDA

## Ultraconic Sensor

- GND -> GND
- VCC -> +5V
- Trig -> 7
- Echo -> 6

## Compile and Upload

    arduino-cli compile --fqbn arduino:avr:uno Waschanlage.ino
    arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno Waschanlage.ino && arduino-cli monitor -p /dev/ttyACM0

## Monitor
