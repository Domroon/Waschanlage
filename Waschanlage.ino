#include <SoftwareSerial.h>
#include <Servo.h>
#include <U8g2lib.h>

// variables for the distance sensor
int distance;
const byte triggerInput = 7;
const byte echoInput = 6;
int minShouldPos = 5;
int maxShouldPos = 9;
int minDangerPos = 40;
int maxDangerPos = 60;

// inputs
const byte buttonInputPin = 2;
const byte program1Btn = 12;
const byte program2Btn = 13;

// variables for the motors
Servo servo;  // Objekt der Klasse "Servo erzeugen"
const byte servoOutputPin = 8;

// variables for the barrier
bool barrierTrigger;

// variables for timers
unsigned int startMillis;
bool active = true;
int positionTime = 3000;
int program1Time = 5000;
int program2Time = 1000;

// variables for program state
byte state = 0;


class Barrier{
  private:
    bool buttonState;
    bool barrierIsOpen;
    bool firstIteration;
    unsigned long startMillis;
    bool carUnderBarrier;
    bool carUnderBarrierFirstIteration; // damit die Fehlermeldung nur einmal erscheint
    int minDistance; // Sicherheitsbereich der Schranke
    int maxDistance; // Sicherheitsbereich der Schranke
    void setBarrierState(){
      if(servo.read() >= 80){
        // Serial.println(servo.read());
        isOpen = false;
      } else if (servo.read() <= 10){
        isOpen = true;
      }
    }
    void checkSecurityDistance(int distance){
      // befindet sich ein Auto unter der Schranke?
      // min| -------- |max
      if(distance >= minDistance && distance <= maxDistance){
        carUnderBarrier = true;
      } else {
        carUnderBarrier = false;
        carUnderBarrierFirstIteration = true;
      }
    }
  public:
    bool isOpen;
    Barrier(int minDis, int maxDis){
      buttonState = false;
      barrierIsOpen = false;
      firstIteration = true;
      startMillis = 0;
      carUnderBarrier = true;
      carUnderBarrierFirstIteration = true;
      minDistance = minDis;
      maxDistance = maxDis;

    }
    void openForIntervall(int timeInMs, int distance, bool openTrigger){
      setBarrierState();
      if (firstIteration && openTrigger && !isOpen) {
        startMillis = millis();
        firstIteration = false; // start millis nur neu setzen, wenn dies der erste loop nach dem Trigger ist
        servo.write(0); //Position 1 ansteuern mit dem Winkel 0° - Schranke öffnen
        Serial.print("Open barrier for ");
        Serial.print(timeInMs);
        Serial.println("ms");
      }

      checkSecurityDistance(distance);      

      if (timeInMs <= millis() - startMillis && !carUnderBarrier && isOpen) { // wenn die Zeit nach dem trigger, time_in_ms überschreitet
        servo.write(90); //Position 2 ansteuern mit dem Winkel 90° - Schranke schließen
        firstIteration = true; // Variable zurücksetzen um die Funktion erneut triggern zu können
      }

      // EIN EIGENE FUNKTION PACKEN?
      // print error message 
      if(timeInMs <= millis() - startMillis && carUnderBarrier && carUnderBarrierFirstIteration && isOpen){
        Serial.println("A car is under the barrier.");
        carUnderBarrierFirstIteration = false;
      } 
    }
    void open(){
        servo.write(0); //Position 1 ansteuern mit dem Winkel 0° - Schranke öffnen
    }
    void close(){
        servo.write(90); //Position 2 ansteuern mit dem Winkel 90° - Schranke schließen
    }
};

class UltrasonicSensor{
  private:
    int trigger;
    int echo;
    int duration;
    int distance;
    void measure(){
      digitalWrite(trigger, LOW); 
      delay(5); //
      digitalWrite(trigger, HIGH); 
      delay(10); 
      digitalWrite(trigger, LOW);
      duration = pulseIn(echo, HIGH);
    }
  public:
    UltrasonicSensor(int trig, int e){
      trigger = trig;
      echo = e;
      pinMode(trigger, OUTPUT);
      pinMode(echo, INPUT);
    }
    int calculateDistance(){ 
      measure();
      distance = (duration/2) * 0.03432;
      if (distance >= 500 || distance <= 0){
        return NULL;
      } else {
        return distance;
      }
    }
    void printDistance(){
      Serial.print(distance);
      Serial.println(" cm");
    }
    
};

bool checkPosition(int distance) {
  if (distance >= minShouldPos && distance <= maxShouldPos) {
    return true;
  } else {
    return false;
  }
}

bool checkTimer(unsigned int startMillis, int timerSeconds){
  if (millis() - startMillis >= timerSeconds){
    return true;
  } else {
    return false;
  }
}

Barrier barrier(minDangerPos, maxDangerPos);
UltrasonicSensor sensor(triggerInput, echoInput);


void setup() {
  Serial.begin(9600); // Baudrate muss 9600 sein
  Serial.println("Start Program");

  // input init
  pinMode(buttonInputPin, INPUT);

  // servo init
  servo.attach(servoOutputPin);  // Pin 8 als Ausgang benutzen
}

void loop() {
  // check inputs
  distance = sensor.calculateDistance();
  barrierTrigger = digitalRead(buttonInputPin);

  // execute state
  switch(state) {

    // START
    case 0:
      if (barrier.isOpen == false){
        barrier.open();
      }
      if (checkPosition(distance) == true){
        state = 1;
        barrier.close();
      }
      break;

    // car in position - print
    case 1:
      Serial.println("Car in position");
      Serial.print("Wait for ");
      Serial.print(positionTime);
      Serial.println(" Milliseconds");
      startMillis = millis();
      state = 2;
      break;

    // car in position - check timer
    case 2:
      if (checkPosition(distance) == true){
        if (checkTimer(startMillis, positionTime) == true){
          state = 3;
        } 
      } else {
        Serial.println("Car NOT in position");
        Serial.println("Reset Timer");
        startMillis = millis();
        state = 0;
      }
      break;

    // choose program - print
    case 3:
      if (checkPosition(distance) == true){
        Serial.println("Choose a wash program");
        state = 4;
      } else {
        Serial.println("Car NOT in position");
        state = 0;
      }
      break;

    // choose program - check pos and user input
    case 4:
      if (checkPosition(distance) == true){
      } else {
        Serial.println("Car NOT in position");
        state = 0;
      }
      if (digitalRead(program1Btn) == true){
        Serial.println("Button 1 is pressed");
        state = 5;
      } else if (digitalRead(program2Btn) == true){
        Serial.println("Button 2 is pressed"); 
        state = 7;
      }

      break;

    case 5:
      Serial.println("In Program 1");
      startMillis = millis();
      state = 6;
      break;

    case 6:
      // execute program 1 here
      if (checkTimer(startMillis, program1Time) == true){
          state = 9;
      } 
      break;

    case 7:
      Serial.println("In Program 2");
      startMillis = millis();
      state = 8;
      break;

    case 8:
      // execute program 2 here
      if (checkTimer(startMillis, program2Time) == true){
          state = 9;
      } 
      break;

    case 9:
      Serial.println("Leave Waschanlange!");
      Serial.println("Go to state 0");
      state = 0;
  }

  // solange auto in position und schranke unten: 3s timer
  // wenn auto die position verlässt - timer zurück setzen
  // wenn auto auch nach 3 sekunden stelle verlässt:
  // programm von vorne starten

  // anzeige: programm 1 oder 2
  // auf benutzereingabe warten
  // Programm 1 oder 2 durchführen
}