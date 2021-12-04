int counter = 0;
int red = 11;
int yellow = 10;
int green = 9;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  Serial.begin(9600);
}


void loop() {
  counter = counter % 3;
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  //Changes between states every second
  if(counter==0){
    // red light
    Serial.println("red light");
    digitalWrite(red, HIGH);
    delay(5000);
    counter++;
  } else if(counter==1){
    // yellow light
    Serial.println("yellow light");
    digitalWrite(yellow, HIGH);
    delay(1000);
    counter++;
  } else if(counter==2){
    Serial.println("green light");
    digitalWrite(green, HIGH);
    delay(5000);
    counter++;
  }
}
