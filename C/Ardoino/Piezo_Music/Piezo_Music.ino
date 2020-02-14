int piezoPin = 11;

unsigned int frqArray[8] = {
   262 // DO
  ,294 // Re
  ,330 // Mi
  ,349 // Fa
  ,392 // Sol
  ,440 // Ra
  ,494 // Si
  ,0 // 쉼표
};

int signatures[26] = {4,4,4,4,4,4,2,4,4,4,4,3,4,4,4,4,4,4,4,2,4,4,4,4,3,4};
int scale[26] = {4,4,5,5,4,4,2,4,4,2,2,1,7,4,4,5,5,4,4,2,4,2,1,2,0,7};

void setup() {
  // put your setup code here, to run once:
  pinMode(piezoPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<26;i++)
  {
    unsigned long duration
    = 1000 / signatures[i];
    tone(piezoPin,frqArray[scale[i]],duration);
    delay(duration * 1.5);
    noTone(piezoPin);
  }

}
