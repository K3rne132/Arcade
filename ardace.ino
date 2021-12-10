#define BUZZER 0

#define A3   220
#define A3is 233
#define B3   247

#define C4   261
#define C4is 277
#define D4   294
#define D4is 311
#define E4   330
#define F4   349
#define F4is 370
#define G4   392
#define G4is 415
#define A4   440
#define A4is 466
#define B4   494

#define C5   523
#define C5is 554
#define D5   587
#define D5is 622
#define E5   659
#define F5   698
#define F5is 740
#define G5   784
#define G5is 831
#define A5   880
#define A5is 932
#define B5   988

#define C6   1047
#define C6is 1109
#define D6   1175
#define D6is 1245
#define E6   1319
#define F6   1397
#define F6is 1480
#define G6   1568
#define G6is 1661
#define A6   1760
#define A6is 1865
#define B6   1976


#define NOTE    1280
#define HALF    640
#define QUARTER 320
#define EIGHT   160
#define SIXTEEN 80

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void beep(int note, int cl) {
  tone(BUZZER, note, cl);
  delay(cl);
}

void pause(int cl) {
  delay(cl);
}

void TetrisTheme() {
  //1
  beep(E4, EIGHT);
  beep(E4, SIXTEEN);
  beep(E4, SIXTEEN);
  beep(B3, EIGHT);
  beep(B3, EIGHT);
  beep(E4, EIGHT);
  beep(E4, SIXTEEN);
  beep(E4, SIXTEEN);
  beep(E4, EIGHT);
  beep(E4, QUARTER);
  pause(HALF);
  //2
  beep(E4, EIGHT);
  beep(B5, EIGHT);
  beep(E6, EIGHT);
  beep(D5is, EIGHT);
  beep(E6, EIGHT);
  beep(B5, SIXTEEN);
  beep(B5, SIXTEEN);
  beep(C6, EIGHT);
  beep(A5, EIGHT);
  //3
  beep(B5, EIGHT);
  beep(G5, EIGHT);
  beep(A5, EIGHT);
  beep(F5is, EIGHT);
  beep(G5, EIGHT);
  beep(E5, EIGHT);
  beep(F5is, EIGHT);
  beep(D5, EIGHT);
  //4
  beep(E5, EIGHT);
  beep(B4, EIGHT);
  beep(C5, EIGHT);
  beep(D5is, EIGHT);
  beep(E5, EIGHT);
  beep(B4, EIGHT);
  beep(C5, EIGHT);
  beep(F5is, EIGHT);
  //5
  beep(E4, EIGHT);
  beep(B5, EIGHT);
  beep(E6, EIGHT);
  beep(D5is, EIGHT);
  beep(E6, EIGHT);
  beep(B5, SIXTEEN);
  beep(B5, SIXTEEN);
  beep(C6, EIGHT);
  beep(A5, EIGHT);
  //6
  beep(B5, EIGHT);
  beep(G5, EIGHT);
  beep(A5, EIGHT);
  beep(F5is, EIGHT);
  beep(G5, EIGHT);
  beep(E5, EIGHT);
  beep(F5is, EIGHT);
  beep(D5, EIGHT);
  //7
  beep(E5, EIGHT);
  beep(B4, EIGHT);
  beep(C5, EIGHT);
  beep(D5is, EIGHT);
  beep(E5, EIGHT);
  beep(B4, EIGHT);
  beep(C5, EIGHT);
  beep(F5is, EIGHT);
  //8
  beep(E5, EIGHT);
  pause(HALF);
  beep(F5is, EIGHT);
  beep(D5is, EIGHT);
  //9
  beep(E5, EIGHT);
  pause(HALF);
  beep(F5is, EIGHT);
  //10
  beep(G5, EIGHT);
  beep(G5, SIXTEEN);
  beep(G5, SIXTEEN);
  beep(A5, EIGHT);
  beep(F5is, EIGHT);
  beep(G5, EIGHT);
  beep(G5, SIXTEEN);
  beep(G5, SIXTEEN);
  beep(A5, EIGHT);
  beep(F5is, EIGHT);
  //11
  beep(G5, EIGHT);
  pause(HALF);
  beep(A5, EIGHT);
  //12
  beep(B5, EIGHT);
  beep(B5, SIXTEEN);
  beep(B5, SIXTEEN);
  beep(C6, EIGHT);
  beep(A5, EIGHT);
  beep(B5, EIGHT);
  beep(B5, SIXTEEN);
  beep(B5, SIXTEEN);
  beep(C6, EIGHT);
  beep(A5, EIGHT);
  //13
  beep(B5, EIGHT);
  pause(HALF);
  beep(C6is, EIGHT);
  pause(EIGHT);
  //14
  beep(D6, EIGHT);
  beep(D6, SIXTEEN);
  beep(D6, SIXTEEN);
  beep(D6, EIGHT);
  beep(D6, EIGHT);
  beep(E6, EIGHT);
  beep(D6, EIGHT);
  beep(D6, EIGHT);
  beep(C6is, EIGHT);
  //15
  beep(D6, EIGHT);
  beep(D6, SIXTEEN);
  beep(D6, SIXTEEN);
  beep(D6, EIGHT);
  beep(D6, EIGHT);
  beep(E6, EIGHT);
  beep(D6, EIGHT);
  beep(D6, EIGHT);
  beep(C6is, EIGHT);
  //16
  beep(D6, EIGHT);
  beep(D6, SIXTEEN);
  beep(D6, SIXTEEN);
  beep(D6, EIGHT);
  beep(D6, EIGHT);
  beep(C6is, EIGHT);
  beep(C6is, SIXTEEN);
  beep(C6is, SIXTEEN);
  beep(C6is, EIGHT);
  beep(C6is, EIGHT);
  //17
  beep(C6, EIGHT);
  beep(C6, SIXTEEN);
  beep(C6, SIXTEEN);
  beep(C6, EIGHT);
  beep(A5, EIGHT);
  beep(F5is, EIGHT);
  beep(G5, EIGHT);
  beep(A5, EIGHT);
  beep(D5, EIGHT);
  //18
  beep(A5, EIGHT);
  beep(G5, SIXTEEN);
  beep(G5, SIXTEEN);
  beep(D5, EIGHT);
  beep(G5, EIGHT);
  pause(EIGHT);
  beep(D5, SIXTEEN);
  beep(E5, SIXTEEN);
  beep(D5, EIGHT);
  beep(B4, EIGHT);
  //19
  beep(A5, EIGHT);
  beep(G5, SIXTEEN);
  beep(G5, SIXTEEN);
  beep(D5, EIGHT);
  beep(G5, EIGHT);
  pause(EIGHT);
  beep(D5, SIXTEEN);
  beep(E5, SIXTEEN);
  beep(D5, EIGHT);
  beep(A4, EIGHT);
  //20
  beep(D4, EIGHT);
  pause(EIGHT);
  pause(QUARTER);
  pause(HALF);
}

void loop() {
  TetrisTheme();
}
