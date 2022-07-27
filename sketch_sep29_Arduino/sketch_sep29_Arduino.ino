
//puertos utilizados (motor y ventilador)
const int B1A = 9;
const int B1B = 8;
const int A1A = 7;
const int A1B = 6;
const int VN = 2;

//Constantes para leer puerto Serial
char dato;
String comando;
int aux1;
int aux2;

//Funcion para leer el puerto Serial
void LeerPuertoSerie() {
  comando = "";
  while(Serial.available()){
    delay(10);
    if (Serial.available() > 0){
      dato = Serial.read();
      comando += dato;
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode (B1A, OUTPUT);
  pinMode (B1B, OUTPUT);
  pinMode (A1A, OUTPUT);
  pinMode (A1B, OUTPUT);
  pinMode (VN, OUTPUT);

}

void loop() {

  LeerPuertoSerie();
  if (comando.length() > 0){
    Serial.println(comando);
    Serial.println(comando.length());
    if (comando.substring(0,comando.length()-2) == "ON") {
        //motor
        digitalWrite(B1B, LOW);
        analogWrite(B1A, 53);
        Serial.println("SE ENCIENDE EL MOTOR"); 
        //cooler
        digitalWrite(A1B, LOW);
        analogWrite(A1A, 255);
        Serial.println("SE ENCIENDE EL COOLER");
        //cooler 2
        digitalWrite(VN, HIGH);
        Serial.println("SE ENCIENDE EL SEGUNDO COOLER");
        delay(10);
        comando == "";
    } else {
      if (comando.substring(0,comando.length()-2) == "OFF") {
        //motor
        digitalWrite(B1A, LOW); 
        digitalWrite(B1B, LOW);
        Serial.println("SE APAGA EL MOTOR");
        //cooler
        digitalWrite(A1A, LOW); 
        digitalWrite(A1B, LOW);
        Serial.println("SE APAGA EL COOLER");
        //cooler 2
        digitalWrite(VN, LOW);
        Serial.println("SE APAGA EL SEGUNDO COOLER");
        delay(10);
        comando == "";
      } else {
        if (comando.substring(0,1) == "M"){
          aux1= comando.substring(1,comando.length()-2).toInt();
          Serial.println(aux1);
          //motor
          /*------------*/
          digitalWrite(B1B, LOW);
          analogWrite(B1A, 60);
          Serial.println("VALOR ALTO POR 10 MILISEGUNDO");
          delay(10);
          /*------------*/
          digitalWrite(B1B, LOW);
          analogWrite(B1A, aux1);
          Serial.println("SE CAMBIA LA VELOCIDAD");
          delay(10); 
        } else {
          if (comando.substring(0,1) == "V"){
            aux2= comando.substring(1,comando.length()-2).toInt();
            Serial.println(aux2);
            //cooler
            digitalWrite(A1B, LOW);
            analogWrite(A1A, aux2);
            Serial.println("SE CAMBIA LA VELOCIDAD");
            delay(10);
          }
        }
      }
    }
  }
}
