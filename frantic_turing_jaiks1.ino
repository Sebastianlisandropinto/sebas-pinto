#define led1 3
#define led2 4 
#define bot 2 
#define buz 6
#define temp A1

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(bot, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(temp, INPUT);
  Serial.begin(9600);
}

void loop() {
  int lectura = digitalRead(bot);
  int senal = analogRead(temp);
  float voltaje = (senal * 5.0 / 1024);
  float temperatura = (voltaje * 100.0 - 50.0);
  
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" Grados");
  
  if (temperatura > 30.0 && lectura == LOW) {
    tone(buz, 523);
  } else {
    noTone(buz);
  }
  
  if (temperatura > 30.0) {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
  } else {
    digitalWrite(led2, LOW);
    digitalWrite(led1, HIGH);
  }
}