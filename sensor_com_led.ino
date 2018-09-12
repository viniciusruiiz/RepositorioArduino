
int pinoSensor = 0;
int valorLido = 0;
float temperatura = 0; 
int linha = 0;
int led = 2;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin (9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Hora, temperatura,linha");
  
}
void loop() {
  valorLido = analogRead(pinoSensor);
  temperatura = (valorLido * 0.00488);
  temperatura = temperatura * 100;
  linha++;
  
  Serial.print("DATA, TIME, ");  
  Serial.print(temperatura);
  Serial.print(",");
  Serial.println(linha);
  
  if(linha> 100)
  {
    linha = 0;
    Serial.println("ROW,SET,2");
  }
    
  if (temperatura >= 25) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }delay (400);
}
  
