const int trig = 2;
const int echo = 3;
const int led= 10;

void setup() {
  // sets the trig and echo pin for the ultrasonic sensor
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  // sets myLed pin of the led to output
  pinMode(led, OUTPUT);

  // allows for printouts in Serial console
  Serial.begin(9600);
}

void loop() {
  // send out a pulse on maxDistance_trigPin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  // wait for signal to return
  // convert duration to distance in cm and check if smaller than range
  double distance = 300 - (0.01715 * pulseIn(echo, HIGH));
  
  // bool maxDistance = 50 > maxDistance_distance;
  
  // dims led according to distance measured
  analogWrite(led, distance);
  /*
  if (maxDistance) {
    analogWrite(myLed_pin, LOW);
  } else {
    analogWrite(myLed_pin, HIGH);
  }
  */
}
