
int sicaklik =0; //Sıcaklık değişkenimiz.
const int sicaklik_pin= A0; //LM35'i bağladığımız pin.

void setup() {
Serial.begin(9600);
}

void loop() {

sicaklik = analogRead(sicaklik_pin); //Ham analog veriyi değişkenimizde sakladık.
sicaklik = (sicaklik * (5000/1023))/100; //Celcius cinsinden sıcaklık birimine dönüştürdük.
Serial.print("Sicaklik: "); // Bilgileri
Serial.print(sicaklik); // ekrana
Serial.print("C"); // yazdırdık...
delay(1000);
}
