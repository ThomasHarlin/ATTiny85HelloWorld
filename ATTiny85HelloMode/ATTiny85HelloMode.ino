//Timer Variables
int timer = 100;
int start;
int trigger;

//Pin Variables
int led = 1;
int button = 0;

//Debouncing Variables
int buttCount = 0;
boolean buttState = true;
boolean isOn = false;
int nowState = 0;
int thenState = 0;

void setup() {
  // put your setup code here, to run once:

//Sets Beginning States
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(led, LOW);

  start = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  //starts timer
  trigger = millis();

  //Button Debouncer

  nowState = digitalRead(button);

  if (nowState == HIGH && thenState == LOW) {
    buttCount++;
    delay(10);
  }
  thenState = nowState;

  //State Machine
  switch (buttCount) {
    case 0:
      // light is off

      digitalWrite(led, LOW);

      break;
    case 1:
      // light is on

      digitalWrite(led, HIGH);

      break;
    case 2:
      // blinky

      if (trigger - start >= timer) {
        isOn = !isOn;
        if (isOn) {
          digitalWrite(led, HIGH);
        }
        else {
          digitalWrite(led, LOW);
        }
        start = millis();
      }

      break;
    case 3:
      // reset count

      buttCount = 0;

      break;
  }

}
