int REDled = 11;
int GREENled = 10;
int YELLOWled = 9;

#define echoPin 2
#define trigPin 3


long duration; 
int distance;

void setup() {
  pinMode(YELLOWled,OUTPUT);
  pinMode(REDled,OUTPUT);
  pinMode(GREENled,OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
}
void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance > 30){
  digitalWrite(GREENled,HIGH);
  digitalWrite(REDled,LOW);
  digitalWrite(YELLOWled,LOW);
}
  else if(distance > 10&&distance < 30) {
  digitalWrite(YELLOWled,HIGH);
  digitalWrite(GREENled,LOW);
  digitalWrite(REDled,LOW);
  }
  else {
  digitalWrite(REDled,HIGH);
  digitalWrite(GREENled,LOW);
  digitalWrite(YELLOWled,LOW);
  }
}
