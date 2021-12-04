int button = 5;
int red = 11;
int yellow = 10;
int green = 9;
int state = 0;

void setup() {
    // put your setup code here, to run once:
    pinMode(button, INPUT_PULLUP);
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(green, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    state = state % 3;
    // put your main code here, to run repeatedly:
    bool state1 = digitalRead(button) == LOW;
    delay(50);
    bool state2 = digitalRead(button) == LOW;

    bool click = (state1 == true) && (state2 == false);
    
    if (click) { 
        state++;
    }

    if (state == 1) {
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(green, LOW);
    } else if (state == 2) {
        digitalWrite(red, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(green, LOW);
    } else {
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(green, HIGH);
    }
}
