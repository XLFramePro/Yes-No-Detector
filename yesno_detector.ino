const int GreenLED = 2;
const int RedLED = 3;
const int BuzzerPin = 8;
const int antennaLeftPin = A0;
const int antennaRightPin = A1;

void setup() {
  pinMode(GreenLED, OUTPUT);
  pinMode(RedLED, OUTPUT);
  pinMode(BuzzerPin, OUTPUT);
  pinMode(antennaLeftPin, INPUT);
  pinMode(antennaRightPin, INPUT);

  digitalWrite(GreenLED, HIGH); 
  digitalWrite(RedLED, HIGH);  
  Sound(400, 100);
  delay(500); 

  digitalWrite(GreenLED, LOW);
  digitalWrite(RedLED, LOW);
  delay(1000);
}

void loop() {
  int valueLeftAntenna = analogRead(antennaLeftPin);
  int valueRightAntenna = analogRead(antennaRightPin);

  if (valueLeftAntenna > 500) {
    digitalWrite(GreenLED, HIGH);
    Sound(400, 100);
    delay(500);
    digitalWrite(GreenLED, LOW);
  }

  if (valueRightAntenna > 500) {
    digitalWrite(RedLED, HIGH);
    Sound(400, 100);
    delay(500);
    digitalWrite(RedLED, LOW);
  }
}

void Sound(int frequency, int time) {
  tone(BuzzerPin, frequency);
  delay(time);
  noTone(BuzzerPin);
}
