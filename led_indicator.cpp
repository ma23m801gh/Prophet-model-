const int trig = 11;
const int echo = 12;

const int LED[] = {2, 3, 4, 5, 6, 7, 8};
const int threshold[] = {5, 7, 10, 15, 17, 20, 25};

int duration = 0;
int distance = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
 
  for (int i = 0; i < 7; i++) {
    pinMode(LED[i], OUTPUT);
  }
 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 28.5;
  Serial.println(distance);

  for (int i = 0; i < 7; i++) {
    if (distance <= threshold[i]) {
      digitalWrite(LED[i], HIGH);
    } else {
      digitalWrite(LED[i], LOW);
    }
  }
}
