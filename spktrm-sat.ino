void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);

}
uint16_t channels[14];
int frame_done=0;

void loop() {
    if (frame_done) {
        Serial.printlnf("T%i A%i E%i R%i G%i A1:%i A2:%i A3:%i A4:%i",
                       channels[0],channels[1],channels[2],channels[3],channels[4],channels[5],channels[6],channels[7],channels[8]);
        //for (int i=9;i<13;i++)
        //    Serial.printf("%i ",channels[i]);
        //Serial.printlnf("%i",channels[13]);
        frame_done=0;
    }
}

void serialEvent1()
{ int data;
  int chan_id;
  int errors, bindtype;

    if (Serial1.available() >=18){
        errors = Serial1.read();
        bindtype = Serial1.read();
        for (int i=0;i<7;i++){
            data = Serial1.read();
            chan_id = (data & 0x78)>>3;//Serial.printf("chan_ID:%i ",chan_id);
            channels[chan_id] = ((data & 0x07)<<8);
            channels[chan_id] += Serial1.read();//Serial.printlnf("data :%i ",channels[chan_id]);
        }
        frame_done=1;
    }
}
