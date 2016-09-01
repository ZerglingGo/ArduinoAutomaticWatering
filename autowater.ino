/*
 * Arduino automatic watering system
 * 
 * Author  : SeongKwon Choi <zerglinggo@zerglinggo.net>
 * License : MIT License
 */
int pinMoistureSensor = A0;
int pinWaterPump      = A1;
bool isSprinkle = false;
/*
 * soil moisture sensor value
 * Range : 0 ~ 1000
 * 
 * dry : 0 ~ 300
 * humid : 301 ~ 700
 * water : 701 ~ 1000
 */
int moistureLow  = 250;
int moistureHigh = 400

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinWaterPump, OUTPUT);
  digitalWrite(pinWaterPump, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int moistureValue;
  moistureValue = analogRead(pinMoistureSensor);
  Serial.println(moistureValue);
  
  if(isSprinkle) {
    digitalWrite(pinWaterPump, HIGH);
  } else {
    digitalWrite(pinWaterPump, LOW);
  }
  
  if(moistureValue <= moistureLow) {
    isSprinkle = true;
  } else if (moistureValue >= moistureHigh) {
    isSprinkle = false;
  }
}
