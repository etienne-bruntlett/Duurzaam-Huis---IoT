void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  
  Serial.begin(115200);
}

void loop() {
  int ldr_value = random(1023);
  int ldr_delay = random(100, 500);

  if (ldr_value < 500) {
    digitalWrite(D3, HIGH);
    digitalWrite(D5, HIGH);
    digitalWrite(D6, HIGH);
    delay(ldr_delay);
    
    digitalWrite(D3, LOW);
    digitalWrite(D5, LOW);
    digitalWrite(D6, LOW);
  }

  Serial.print("{\"huidige\":");
  Serial.print(ldr_value);
  Serial.println("}");

  delay(500);
}
