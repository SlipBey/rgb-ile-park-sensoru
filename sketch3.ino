#define echo 6
#define trig 7
int kirmizi = 3;
int yesil = 2;
int mavi = 4;
int buzzer = 5;
long sure;
long mesafe;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  sure = pulseIn(echo, HIGH);
  mesafe = (sure/2)/29.1;
  if(mesafe > 200) {
    mesafe = 200;
  }
  if(mesafe <= 20) {
   for(int buzzer = 0; buzzer < 20; buzzer++) {
    digitalWrite(yesil, LOW);
    digitalWrite(mavi, LOW);
    delay(10);
    digitalWrite(kirmizi, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(10);
   }
  } 
  if(mesafe >= 20 && mesafe <= 40) {
    for(int buzzer = 0; buzzer < 20; buzzer++) {
   digitalWrite(buzzer, LOW);
   digitalWrite(kirmizi, LOW);
   digitalWrite(yesil, LOW);
   delay(100);
   digitalWrite(mavi, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(120);
    digitalWrite(buzzer, LOW);
    delay(10);
   }   
  } 
  if(mesafe > 40){
   digitalWrite(buzzer, LOW);
   digitalWrite(mavi, LOW);
   digitalWrite(kirmizi, LOW);
   delay(100);
   digitalWrite(yesil, HIGH);
  }
    Serial.print(mesafe);
  Serial.println(" cm uzaklıkta");
}
