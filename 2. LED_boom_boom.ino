// 습도 센서 핀
int water_sensor = A0; 

// 모터 제어 핀들 //
int motor_1 = 2;
int motor_2 = 3;
/* ------------- */

//LED 제어핀
int LED_R = 8;
int LED_G = 9;
int LED_B = 10;

// 입력 데이터 저장
int water_data;

void setup() {
  // 습도 센서 set
  pinMode(water_sensor,INPUT);

  // 모터 핀 set
  pinMode(motor_1,OUTPUT);
  pinMode(motor_2,OUTPUT);
  pinMode(motor_a,OUTPUT);
  pinMode(motor_b,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 water_data = analogRead(water_sensor);

  if( water_data > 300 ){ // 촉촉함 
    digitalWrite(motor_1,LOW); //모터 정지
    digitalWrite(motor_2,HIGH);
  }
  else if (water_data > 700){ // 경고
    digitalWrite(motor_1,LOW); // 모터 정지
    digitalWrite(motor_2,HIGH);
  }
  else{ // 물 필요함
    digitalWrite(motor_1,HIGH); //모터 활성화
    digitalWrite(motor_2,LOW);
  }
}