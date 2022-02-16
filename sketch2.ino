#define echo 7
#define trig 8
#define kirmizi 5
#define yesil 6
#define mavi 3
long sure;
long mesafe;
int buzzerPin = 10;

void setup() {
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(kirmizi, OUTPUT);
  pinMode(yesil, OUTPUT);
  pinMode(mavi, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
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
  Serial.print(mesafe);
  Serial.println(" cm uzaklıkta");
  if(mesafe <= 20) {
   digitalWrite(yesil, LOW);
   digitalWrite(mavi, LOW);
   delay(100);
   digitalWrite(kirmizi, HIGH);
   digitalWrite(buzzerPin, HIGH);
  } 
  if(mesafe >= 20 && mesafe <= 40) {
   digitalWrite(buzzerPin, LOW);
   digitalWrite(kirmizi, LOW);
   digitalWrite(yesil, LOW);
   delay(100);
   digitalWrite(mavi, HIGH);
  } 
  if(mesafe > 40){
   digitalWrite(mavi, LOW);
   digitalWrite(kirmizi, LOW);
   delay(100);
   digitalWrite(yesil, HIGH);
  }
}
