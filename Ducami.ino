// 습도 센서 핀
int water_sensor = A0; 

// 모터 제어 핀
int motor_1 = 2;
int motor_2 = 3;

//LED 제어핀
int LED_R = 8;
int LED_G = 9;
int LED_B = 10;

//millis
unsigned long p_time;
unsigned long now_time;

// auto auto_mode
char auto_mode = 0;

// 입력 데이터 저장
int water_data;

void setup() {
  //Serial
  Serial.begin(9600);

  // 습도 센서 set
  pinMode(water_sensor,INPUT);

  // LED pin SET
  pinMode(LED_R,OUTPUT);
  pinMode(LED_B,OUTPUT);
  pinMode(LED_G,OUTPUT);

  // 모터 핀 set
  pinMode(motor_1,OUTPUT);
  pinMode(motor_2,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  now_time = millis();
  char c;

  if(Serial.available() > 0){
    c = Serial.read();
  }

  switch(c){
    case '1': // LED on 
      digitalWrite(LED_R,HIGH); // LED on
      digitalWrite(LED_G,HIGH);
      digitalWrite(LED_B,HIGH);
      break;
    
    case '2': // LED off
      digitalWrite(LED_R,LOW); // LED off
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,LOW);
      break;

    case '5': // auto on
      auto_mode = 1;
      break;

    case '6': // auto off 
      auto_mode = 0;
      break;

    case '3':
      motor_on();
      break;

    case '4':
      motor_off();
      break;

    default:
      break;
  }

  if(auto_mode){
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
      digitalWrite(LED_R,HIGH); //빨간 LED on
      digitalWrite(LED_G,LOW);
      digitalWrite(LED_B,LOW);
    }
  }

  if(p_time - now_time > 10000){
    p_time = now_time;
    water_data = analogRead(water_sensor);
    Serial.print(water_data);
  }

}

void motor_on(){
  digitalWrite(motor_1,HIGH);
  digitalWrite(motor_2,LOW);
}

void motor_off(){
  digitalWrite(motor_1,LOW);
  digitalWrite(motor_2,LOW);
}
