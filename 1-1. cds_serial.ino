// 습도 센서 핀
int water_sensor = A0; 
int cds_sensor = A1;

// 습도 센서 데이터 변수
int water_data;
int cds_data;

void setup() {
   //Serial 통신 설정
   Serial.begin(9600);

   // 습도 센서 set
   pinMode(water_sensor,INPUT);
}

// the loop function runs over and over again forever
void loop() {
   water_data = analogRead(water_sensor);
   cds_data = analogRead(cds_sensor);

   Serial.print("습도 : ");
   Serial.println(water_data);
   
   Serial.print("조도 : ");
   Serial.println(cds_data);
   Serial.println();
   delay(100);
}