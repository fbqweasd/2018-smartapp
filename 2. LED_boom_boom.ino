// 습도 센서 핀
int water_sensor = A0; 

//LED 제어핀
int LED_R = 8;
int LED_G = 9;
int LED_B = 10;

// 입력 데이터 저장
int water_data;

void setup() {
  // 습도 센서 set
  pinMode(water_sensor,INPUT);

  // LED pin SET
  pinMode(LED_R,OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(LED_G,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 water_data = analogRead(water_sensor);

  if( water_data > 300 ){ // 촉촉함 
    digitalWrite(LED_R,LOW); // 초록색 LED on
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,LOW);
  }
  else if (water_data > 700){ // 경고
    digitalWrite(LED_R,HIGH); // 노란색 LED on
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,LOW);}
  else{ // 물 필요함
    digitalWrite(LED_R,LOW); //빨간 LED on
    digitalWrite(LED_G,HIGH);
    digitalWrite(LED_B,LOW);
  }
}