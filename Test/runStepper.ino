#include <AccelStepper.h>
AccelStepper stepper(1,2,5);// pin 5 step, pin 4 dir

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT); // Enable
  digitalWrite(8,LOW); // Dặt Enable xuống low để khởi động động cơ
}

void loop() {
  if (stepper.distanceToGo() == 0)  //kiểm tra thử động cơ bước có còn đang chạy hay không, nếu không còn chạy thì...
  {  
    delay(1000);
    stepper.moveTo(rand() % 400); //chuyển đến tọa độ 0 - 399 (Random)
    stepper.setMaxSpeed((rand() % 400) + 200);  //chỉnh tốc độ. 
    stepper.setAcceleration((rand() % 200) + 100); //chỉnh gia tốc.
    //kiến thức về tốc độ và gia tốc là kiến thức cơ bản vật lý lớp 10, vì vậy, các bạn lớp 9 trở xuống muốn dùng động cơ bước thì nhớ tìm hiểu khái niệm này nhé. hehe
  }

  Serial.println(stepper.distanceToGo());
  stepper.run();  // phải có hàm này ở hàm loop với mỗi biến stepper thì nói mới chạy được
}