// 습도 센서 핀
int water_sensor = A0; 

// 모터 제어 핀
int motor_1 = 2;
int motor_2 = 3;

// 습도 센서 데이터 변수
int water_data;

void setup() {
  // 습도 센서 set
  pinMode(water_sensor,INPUT);

  // 모터 핀 set
  pinMode(motor_1,OUTPUT);
  pinMode(motor_2,OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
 water_data = analogRead(water_sensor);

  if( water_data > 300 ){ // 모터 활성화
     digitalWrite(motor_1,LOW);
     digitalWrite(motor_2,HIGH);
  }
  else{ // 모터 정지
     digitalWrite(motor_1,LOW);
     digitalWrite(motor_2,HIGH);
  }
}