void setup() {
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  int A = random(999);
  int B = random(999);
  int C = random(999);
  int D = random(999);

  digitalWrite(D3, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);

  Serial.println("---- Nieuwe cyclus ----");
  Serial.print("A: "); Serial.println(A);
  Serial.print("B: "); Serial.println(B);
  Serial.print("C: "); Serial.println(C);
  Serial.print("D: "); Serial.println(D);

  if (A > B || A < C) {
    digitalWrite(D3, HIGH);
    Serial.println("D3 AAN");
  }

  if (C > A && A < B) {
    digitalWrite(D5, HIGH);
    Serial.println("D5 AAN");
  }

  if (B > C && B > A && C < A) {
    digitalWrite(D6, HIGH);
    Serial.println("D6 AAN");
  }

  if (D > A && D > B && D > C) {
    Serial.println("D is het grootst -> ALLE lampen knipperen!");

    for (int i = 0; i < 10; i++) {
      digitalWrite(D3, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D6, HIGH);
      delay(200);

      digitalWrite(D3, LOW);
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
      delay(200);
    }
  }

  Serial.println("------------------------");

  delay(10000); //
}
