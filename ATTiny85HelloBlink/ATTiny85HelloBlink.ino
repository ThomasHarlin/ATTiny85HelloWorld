int timer = 100;
int start;
int trigger;

int led = 1;
int button = 0;

void setup() {
  // put your setup code here, to run once:

pinMode(led, OUTPUT);
pinMode(button, INPUT);


digitalWrite(led,LOW);

start = millis();



}

void loop() {
  // put your main code here, to run repeatedly:
trigger = millis();

if(trigger-start>=timer){

digitalWrite(led,HIGH);
delay(100);
digitalWrite(led,LOW);

  start = millis();
}


}
