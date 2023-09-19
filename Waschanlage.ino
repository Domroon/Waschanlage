#include <Servo.h>
#include <U8g2lib.h>

// variables for the display
U8G2_SSD1306_128X64_NONAME_F_HW_I2C front(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
static const unsigned char image_car[] U8X8_PROGMEM = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x01,0xfc,0xff,0x0f,0x00,0x00,0x00,0x00,0xff,0x01,0xfc,0xff,0x0f,0x00,0x00,0x00,0x00,0xff,0x01,0xfc,0xff,0x0f,0x00,0x00,0x00,0x00,0xc7,0xff,0x1f,0xc0,0xf1,0xff,0x3f,0x00,0x00,0xc7,0xff,0x1f,0xc0,0xf1,0xff,0x3f,0x00,0x00,0xc7,0xff,0x1f,0xc0,0xf1,0xff,0x3f,0x00,0x00,0xff,0x71,0x1c,0xc0,0xf1,0xe3,0xf8,0x0f,0x00,0xff,0x71,0x1c,0xc0,0xf1,0xe3,0xf8,0x0f,0x00,0xff,0x71,0x1c,0xc0,0xf1,0xe3,0xf8,0x0f,0x00,0xc7,0x71,0x1c,0x00,0xf0,0x03,0x38,0x0e,0x00,0xc7,0x71,0x1c,0x00,0xf0,0x03,0x38,0x0e,0x00,0xc7,0x71,0x1c,0x00,0xf0,0x03,0x38,0x0e,0x00,0xff,0x71,0xfc,0xff,0x8f,0xe3,0x38,0x0e,0x00,0xff,0x71,0xfc,0xff,0x8f,0xe3,0x38,0x0e,0x00,0xff,0x71,0xfc,0xff,0x8f,0xe3,0x38,0x0e,0x00,0xc7,0x81,0xff,0xf8,0x7f,0x00,0x38,0x0e,0x00,0xc7,0x81,0xff,0xf8,0x7f,0x00,0x38,0x0e,0x00,0xc7,0x81,0xff,0xf8,0x7f,0x00,0x38,0x0e,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x38,0x0e,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x38,0x0e,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x38,0x0e,0x00,0x38,0xf0,0x1f,0xc7,0x8f,0xff,0x00,0x0e,0x00,0x38,0xf0,0x1f,0xc7,0x8f,0xff,0x00,0x0e,0x00,0x38,0xf0,0x1f,0xc7,0x8f,0xff,0x00,0x0e,0x00,0xf8,0x71,0x1c,0x00,0x80,0xe3,0x00,0x0e,0x00,0xf8,0x71,0x1c,0x00,0x80,0xe3,0x00,0x0e,0x00,0xf8,0x71,0x1c,0x00,0x80,0xe3,0x00,0x0e,0x00,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x00,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x00,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0x0f,0x00,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0x01,0x00,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0x01,0x00,0xc0,0xff,0xff,0xff,0xff,0xff,0xff,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
static const unsigned char image_Pin_arrow_right_9x7_bits[] U8X8_PROGMEM = {0x20,0x00,0x60,0x00,0xff,0x00,0xff,0x01,0xff,0x00,0x60,0x00,0x20,0x00};
static const unsigned char image_Pin_arrow_left_9x7_bits[] U8X8_PROGMEM = {0x08,0x00,0x0c,0x00,0xfe,0x01,0xff,0x01,0xfe,0x01,0x0c,0x00,0x08,0x00};
static const unsigned char image_Smile_18x18_bits[] U8X8_PROGMEM = {0xc0,0x0f,0x00,0xf0,0x3f,0x00,0xf8,0x7f,0x00,0xfc,0xff,0x00,0xfe,0xff,0x01,0xfe,0xff,0x01,0xff,0xff,0x03,0xcf,0xcf,0x03,0x87,0x87,0x03,0x87,0x87,0x03,0xcf,0xcf,0x03,0xff,0xff,0x03,0xfe,0xff,0x01,0xbe,0xf7,0x01,0x7c,0xf8,0x00,0xf8,0x7f,0x00,0xf0,0x3f,0x00,0xc0,0x0f,0x00};
static const unsigned char image_Pin_back_arrow_10x8_bits[] U8X8_PROGMEM = {0x04,0x00,0x06,0x00,0xff,0x00,0x06,0x01,0x04,0x02,0x00,0x02,0x00,0x01,0xf8,0x00};
static const unsigned char image_FaceNopower_29x14_bits[] U8X8_PROGMEM = {0x00,0x00,0x00,0x00,0xc0,0x00,0x60,0x00,0xc0,0x00,0x60,0x00,0xe0,0x00,0xe0,0x00,0x7e,0x00,0xc0,0x0f,0x3e,0x00,0x80,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x03,0x00,0x00,0x0c,0x06,0x00,0x00,0xfe,0x0f,0x00,0x00,0xfe,0x0f,0x00,0x00,0x0e,0x0e,0x00,0x00,0x00,0x00,0x00};
static const unsigned char image_EviSmile1_18x21_bits[] U8X8_PROGMEM = {0x0c,0xc0,0x00,0x06,0x80,0x01,0x07,0x80,0x03,0xcf,0xcf,0x03,0xff,0xff,0x03,0xff,0xff,0x03,0xfe,0xff,0x01,0xfe,0xff,0x01,0xfe,0xff,0x01,0xf7,0xbf,0x03,0xe7,0x9f,0x03,0xc7,0x8f,0x03,0x87,0x87,0x03,0x8f,0xc7,0x03,0xff,0xff,0x03,0xfe,0xff,0x01,0xde,0xef,0x01,0xbc,0xf4,0x00,0x78,0x78,0x00,0xf0,0x3f,0x00,0xc0,0x0f,0x00};
static const unsigned char image_Button_18x18_bits[] U8X8_PROGMEM = {0xf8,0xff,0x00,0x06,0x00,0x01,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x03,0x00,0x02,0x07,0x00,0x03,0xfe,0xff,0x01,0xfc,0xff,0x00};


// variables for the distance sensor
int distance;
const byte triggerInput = 7;
const byte echoInput = 6;
byte minShouldPos = 4;
byte maxShouldPos = 7;
byte minDangerPos = 7;
byte maxDangerPos = 10;
int beforeBarrier = 15;

// inputs
const byte barrierTriggerBtn = 2;
const byte program1Btn = 12;
const byte program2Btn = 13;

// variables for the motors
Servo servo;  // Objekt der Klasse "Servo erzeugen"
const byte servoOutputPin = 8;
Servo leftServo;
const byte leftServoPin = 9;
Servo rightServo;
const byte rightServoPin = 10;


// variables for the barrier
bool barrierTrigger;

// variables for program state
byte state = 0;


class Timer{
  private:
    unsigned long startMillis = 0;
    unsigned int timerDuration;
  public:
    Timer(unsigned int duration){
      timerDuration = duration;
    }
    void start(){
      startMillis = millis();
    }
    void restart(){
      startMillis = millis();
    }
    unsigned int getDuration(){
      return timerDuration;
    }
    bool checkTimeOver() {;
      if (millis() - startMillis >= timerDuration){
        return true;
      } else {
        return false;
      }
    }
};

class Display{
  private:
  float timer1;
  float timeout1;
  bool timerbit1;
  int minPos;
  int maxPos;
  public:
    Display(int minShouldPos, int maxShouldPos){
      timer1 = 0;
      timeout1 = 5000;
      timerbit1 = false;
      minPos = minShouldPos;
      maxPos = maxShouldPos;
    }
    // void showWaitScreen(char infotext[]){
    //   uint8_t progressbar = 0;
    //   for(int i = 0; i < 21; i++){
    //     progressbar = progressbar + 5;
    //     front.clearBuffer();
    //     front.setBitmapMode(1);
    //     front.drawFrame(3, 2, 122, 60);
    //     front.drawXBMP( 48, 13, 29, 14, image_FaceConfused_29x14_bits);
    //     front.drawFrame(9, 48, 110, 10);
    //     front.drawBox(11, 50, progressbar, 6);
    //     front.setFont(u8g2_font_helvB08_tr);
    //     front.drawStr(10, 44, infotext);
    //     front.sendBuffer();
    //     }
    // }
    void showInPositionScreen(){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(4, 15, "IN POSITION!");
      front.drawXBMP( 16, 37, 18, 18, image_Smile_18x18_bits);
      front.sendBuffer();
      // timerbit1 = true;
      // if(millis() > timer1 + timeout1 && timerbit1 == true){
      //   timer1 = millis();
      // }
    }
    void showCarPositioningScreen(int distance){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.drawXBMP(distance*(-3) + 55, 17, 72, 73, image_car);
      if(distance >= maxPos){
        front.setBitmapMode(1);
        front.setFont(u8g2_font_helvB08_tr);
        front.drawStr(4, 15, "ANFAHREN!");
        front.drawXBMP(distance *(-1) + 125, 44, 9, 7, image_Pin_arrow_right_9x7_bits);
        timerbit1 = false;
        timer1 = millis();
      }else if(distance < minPos) {
        front.setBitmapMode(1);
        front.setFont(u8g2_font_helvB08_tr);
        front.drawStr(4, 15, "ZURUECK!");
        front.drawXBMP(distance *(-1) + 45, 44, 9, 7, image_Pin_arrow_left_9x7_bits);
        timerbit1 = false;
        timer1 = millis();
      }
      front.sendBuffer();
    }
    void showLeaveScreen(){
      float progressbar = 106;
      for(int i = 0; i < 106; i++){
        progressbar = progressbar - 1;
        front.clearBuffer();
        front.setBitmapMode(1);
        front.drawFrame(3, 3, 122, 58);
        front.drawFrame(9, 48, 110, 10);
        front.drawXBMP( 98, 22, 10, 8, image_Pin_back_arrow_10x8_bits);
        front.setFont(u8g2_font_helvB08_tr);
        front.drawStr(25, 31, "VERLASSEN");
        front.drawBox(11, 50, progressbar, 6);
        front.sendBuffer();
      }
    }
    void showChooseScreen(){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(13, 13, "PROGRAMM WAHL");
      front.drawXBMP( 87, 22, 18, 21, image_EviSmile1_18x21_bits);
      front.drawXBMP( 16, 26, 18, 18, image_Smile_18x18_bits);
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(13, 57, "PRG1");
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(84, 56, "PRG2");
      front.sendBuffer();
    }
    void showProgram1Screen(){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.drawFrame(2, 3, 124, 59);
      front.setFont(u8g2_font_profont22_tr);
      front.drawStr(17, 22, "PROGRAMM");
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(63, 39, "1");
      front.setFont(u8g2_font_haxrcorp4089_tr);
      front.drawStr(44, 55, "im gange.");
      front.drawXBMP( 56, 26, 18, 18, image_Button_18x18_bits);
      front.sendBuffer();
      // delay(2000);
    }
    void showProgram2Screen(){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.drawFrame(2, 3, 124, 59);
      front.setFont(u8g2_font_profont22_tr);
      front.drawStr(17, 22, "PROGRAMM");
      front.setFont(u8g2_font_helvB08_tr);
      front.drawStr(63, 39, "2");
      front.setFont(u8g2_font_haxrcorp4089_tr);
      front.drawStr(44, 55, "im gange.");
      front.drawXBMP( 56, 26, 18, 18, image_Button_18x18_bits);
      front.sendBuffer();
      // delay(2000);
    }
    void showDriveOutScreen(int distance){
      front.clearBuffer();
      front.setBitmapMode(1);
      front.drawXBMP(distance, 17, 72, 73, image_car);
      if(distance >= -60){
        front.setBitmapMode(1);
        front.setFont(u8g2_font_helvB08_tr);
        front.drawStr(4, 15, "ZURUECK!");
        front.drawXBMP(distance - 4, 44, 9, 7, image_Pin_arrow_left_9x7_bits);
      }
      front.sendBuffer();
    }
};

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
      servo.write(125);
    }
    void openForIntervall(int timeInMs, int distance, bool openTrigger){
      setBarrierState();
      if (firstIteration && openTrigger && !isOpen) {
        startMillis = millis();
        firstIteration = false; // start millis nur neu setzen, wenn dies der erste loop nach dem Trigger ist
        servo.write(0); //Position 1 ansteuern mit dem Winkel 0° - Schranke öffnen
        Serial.print(F("Open barrier for "));
        Serial.print(timeInMs);
        Serial.println(F("ms"));
        getAngle();
      }

      checkSecurityDistance(distance);      

      if (timeInMs <= millis() - startMillis && !carUnderBarrier && isOpen) { // wenn die Zeit nach dem trigger, time_in_ms überschreitet
        servo.write(125); //Position 2 ansteuern mit dem Winkel 90° - Schranke schließen
        firstIteration = true; // Variable zurücksetzen um die Funktion erneut triggern zu können
      }

      // EIN EIGENE FUNKTION PACKEN?
      // print error message 
      if(timeInMs <= millis() - startMillis && carUnderBarrier && carUnderBarrierFirstIteration && isOpen){
        Serial.println(F("A car is under the barrier."));
        carUnderBarrierFirstIteration = false;
      } 
    }
    void open(){
        servo.write(20); //Position 1 ansteuern mit dem Winkel 0° - Schranke öffnen
    }
    void close(){
        servo.write(125); //Position 2 ansteuern mit dem Winkel 90° - Schranke schließen
    }
    void getAngle(){
      Serial.print(F("Barrier Angle in degrees: "));
      Serial.println(servo.read());
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
      Serial.println(F(" cm"));
    }
    
};

class Brushes{
  private:
    int test;
    byte rightAngle = 90;
    byte leftAngle = 90;
  public:
    Brushes(int t){
      test = t;
    }
    void setBasicPos(){
      rightAngle = 90;
      leftAngle = 90;
      rightServo.write(rightAngle);
      leftServo.write(leftAngle);
    }
    void exeProgram1Step(){
      if(rightAngle <= 0){
        rightAngle = 180;
      }
      rightServo.write(rightAngle);
      rightAngle -= 1;
      
      if(leftAngle >= 180){
        leftAngle = 0;
      }
      leftServo.write(leftAngle);
      leftAngle += 1;
    }
    void exeProgram2Step(){
      if(rightAngle <= 0){
        rightAngle = 180;
      } else {
        rightAngle = 0;
      }
      rightServo.write(rightAngle);
      
      if(leftAngle >= 180){
        leftAngle = 0;
      } else {
        leftAngle = 180;
      }
      leftServo.write(leftAngle);
      delay(1000);
    }
};

bool checkPosition(int distance) {
  if (distance >= minShouldPos && distance <= maxShouldPos) {
    return true;
  } else {
    return false;
  }
}


Barrier barrier(minDangerPos, maxDangerPos);
UltrasonicSensor sensor(triggerInput, echoInput);
Display display(minShouldPos, maxShouldPos);
Brushes brushes(42);
Timer positionTimer(3000);
Timer program1Timer(8000);
Timer program2Timer(8000);


void setup() {
  Serial.begin(9600); // Baudrate muss 9600 sein
  Serial.println(F("Start Program"));

  // input init
  pinMode(barrierTriggerBtn, INPUT);

  // servo init
  servo.attach(servoOutputPin);  // Pin 8 als Ausgang benutzen
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);
  brushes.setBasicPos();

  barrier.open();

  // display
  front.setI2CAddress(0x3C * 2);
  front.begin();
  // display.showWaitScreen("LOADING...");
}

void loop() {
  // check inputs
  distance = sensor.calculateDistance();
  barrierTrigger = digitalRead(barrierTriggerBtn);
  
  // control barrier
  // barrier.openForIntervall(2000, distance, barrierTrigger);

  // execute state
  switch(state) {

    // START
    case 0:
      display.showCarPositioningScreen(distance);
      if (checkPosition(distance) == true){
        state = 1;
      }
      break;

    // car in position - print
    case 1:
      Serial.println(F("Car in position"));
      Serial.print(F("Wait for "));
      Serial.print(positionTimer.getDuration());
      Serial.println(F(" ms"));
      // startMillisPosition = millis();
      display.showInPositionScreen();
      positionTimer.start();
      state = 2;
      break;

    // car in position - check timer
    case 2:
      if (checkPosition(distance) == true){
        if (positionTimer.checkTimeOver() == true){
          barrier.close();
          state = 3;
        } 
      } else {
        Serial.println(F("Car NOT in position"));
        Serial.println(F("Restart Timer"));
        positionTimer.restart();
        state = 0;
      }
      break;

    // choose program - print
    case 3:
      if (checkPosition(distance) == true){
        display.showChooseScreen();
        Serial.println(F("Choose a wash program"));
        state = 4;
      } else {
        Serial.println(F("Car NOT in position"));
        state = 0;
      }
      break;

    // choose program - check pos and user input
    case 4:
      if (checkPosition(distance) == true){
      } else {
        Serial.println(F("Car NOT in position"));
        state = 0;
      }
      if (digitalRead(program1Btn) == true){
        Serial.println(F("Button 1 is pressed"));
        state = 5;
      } else if (digitalRead(program2Btn) == true){
        Serial.println(F("Button 2 is pressed")); 
        state = 7;
      }

      break;

    // in program 1 - show program screen
    case 5:
      Serial.println(F("In Program 1"));
      display.showProgram1Screen();
      program1Timer.start();
      state = 6;
      break;

    // in program 1 - execute
    case 6:
      if (program1Timer.checkTimeOver() == true){
          state = 9;
      }
      brushes.exeProgram1Step();
      break;

    // in program 2 - show program screen
    case 7:
      Serial.println(F("In Program 2"));
      display.showProgram2Screen();
      program2Timer.start();
      state = 8;
      break;

    // in program 2 - execute
    case 8:
      if (program2Timer.checkTimeOver() == true){
          state = 9;
      }
      brushes.exeProgram2Step();
      break;

    // show leave screen until car is in front of barrier
    case 9:
      brushes.setBasicPos();
      barrier.open();
      delay(1000); // wait until the motors have reached the end position
      Serial.println(F("Leave Waschanlange!"));
      display.showDriveOutScreen(distance);
      state = 10;
      break;

    case 10:
      if (distance >= beforeBarrier){
        state = 0;
        Serial.println(F("Go to state 0 (start)"));
      }
      break;
  }

  // solange auto in position und schranke unten: 3s timer
  // wenn auto die position verlässt - timer zurück setzen
  // wenn auto auch nach 3 sekunden stelle verlässt:
  // programm von vorne starten

  // anzeige: programm 1 oder 2
  // auf benutzereingabe warten
  // Programm 1 oder 2 durchführen
}