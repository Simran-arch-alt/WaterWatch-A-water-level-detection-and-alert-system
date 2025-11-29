// Pin definitions
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;
const int buzzer = 6;  // Buzzer pin

// Variables for non-blocking buzzer timing
unsigned long previousMillis = 0;
bool buzzerState = false;
const long buzzerOnTime = 2000;  // 2 seconds
const long buzzerOffTime = 5000; // 5 seconds

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);
  Serial.begin(9600);
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = (duration * 0.034) / 2;
  return distance;
}

void loop() {
  float distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // SAFE ZONE (GREEN)
  if (distance >= 9.0) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    buzzerState = false;

    Serial.println("STATUS: ✅ SAFE");

  }
  // ALERT ZONE (YELLOW)
  else if (distance >= 8.0 && distance < 9.0) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite(buzzer, LOW);
    buzzerState = false;

    Serial.println("STATUS: ⚠️ ALERT - Water rising!");

  }
  // DANGER ZONE (RED)
  else if (distance < 8.0) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(redLED, HIGH);

    Serial.println("STATUS: 🚨 DANGER - Flood level critical!");

    // Non-blocking buzzer
    if (buzzerState == false && (currentMillis - previousMillis >= buzzerOffTime)) {
      buzzerState = true;
      previousMillis = currentMillis;
      digitalWrite(buzzer, HIGH);
    }
    else if (buzzerState == true && (currentMillis - previousMillis >= buzzerOnTime)) {
      buzzerState = false;
      previousMillis = currentMillis;
      digitalWrite(buzzer, LOW);
    }
  }

  Serial.println("--------------------");
  delay(300); // Slight delay for readability
}
