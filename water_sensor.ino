int water_sensor = A0; 

int motor_a = 7;
int motor_b = 8;

int motor_1 = 4;
int motor_2 = 5;

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

  if( water_data > 300 ){ // 모터 활성화
      digitalWrite(motor_a,HIGH);
     digitalWrite(motor_b,LOW);

     digitalWrite(motor_1,LOW);
     digitalWrite(motor_2,HIGH);
  }
  else{ // 모터 정지
     digitalWrite(motor_a,HIGH);
     digitalWrite(motor_b,LOW);

     digitalWrite(motor_1,LOW);
     digitalWrite(motor_2,HIGH);
  }
}