int p1 = 11;
int p2 = 9;
int red = 10;

int b1 = 6;
int b2 = 5;

int buzz = 3;

void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);

  Serial.begin(9600);
}

void blink_light(int pin, int n, int t) {
  for (int i=0; i<n;i++) {
        digitalWrite(pin, HIGH);
        delay(t);
        digitalWrite(pin, LOW);
        delay(t);
      }
}

void win_sound() {
  tone(buzz, 500, 500);
  delay(200);
  tone(buzz, 1000, 500);
  delay(200);
  tone(buzz, 1500, 500);
}

void play_game() {
  for (int i=0;i<3;i++){
    tone(buzz, 1000, 750);
    delay(1000);
  }
  tone(buzz, 1500, 500);
  
  delay(random(10000));
  digitalWrite(red, HIGH);

  while (true) {
     bool s1 = digitalRead(b1) == HIGH;
     bool s2 = digitalRead(b2) == HIGH; 

     if (s1) {
       win_sound();
       blink_light(p1, 3, 500);
       blink_light(red, 3, 500);
       return;
     } else if (s2) {
       win_sound();
       blink_light(p2, 3, 500);
       blink_light(red, 3, 500);
       return;
     }
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  play_game();
