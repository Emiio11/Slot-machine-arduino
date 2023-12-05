//      ▂▃▄▅▆▇█▓▒░SLOT MACHINE░▒▓█▇▆▅▄▃▂  
//  
//     Progetto ideato e realizzato da Emilio Tulli
//
//  Realizzazione di una slot machine utilizzando display a
//   7 segmenti, display lcd 16x2 e registri a scorrimento
//
//  collegmento primo integrato:(fili arancioni)
//
//  pin 1) segmento b del primo display a 7 segmenti
//  pin 2) segmento c 
//  pin 3) segmento d
//  pin 4) segmento e
//  pin 5) segmento f
//  pin 6) segmento g
//  pin 7) vuoto
//  pin 8) gnd
//  pin 9) vuoto
//  pin 10) vcc
//  pin 11) pin 2 di arduino
//  pin 12) pin A1 di arduino
//  pin 13) gnd
//  pin 14) pin A0 di arduino
//  pin 15) segmento a
//  pin 16) vcc
//
//  collegamento secondo integrato:(fili gialli)
//
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 5 di arduino
//  pin 12) pin 4 di arduino
//  pin 14) pin 3 di arduino
//
//  collegamento terzo integrato:(fili verdi)
//  
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 8 di arduino
//  pin 12) pin 7 di arduino
//  pin 14) pin 6 di arduino
//
//  collegamento quarto integrato:(fili azzurri)
//
//  uguale al precedente tranne i pin 11 12 e 14
//
//  pin 11) pin 11 di arduino
//  pin 12) pin 10 di arduino
//  pin 14) pin 9 di arduino
//
//  
//  collegare il pulsante al pin 12 di arduino
//
//  collegare il terzo e l'ottavo pin al gnd su tutti i display a 7 segmenti
//
//  collegamenti display lcd:
//
//  pin RS al pin 12 di arduino
//  pin Enable al pin 11 di aruino
//  pin D4 al pin 5 di aruino
//  pin D5 al pin 4 di aruino
//  pin D6 al pin 3 di aruino
//  pin D7 al pin 2 di aruino
//  pin R/W a gnd
//  pin VSS a gnd
//  pin VCC a vcc
//
//  collegamento potenziometro:
//
//  estremità vcc e gnd
//  morsetto centrale al pin VO del display (pin 3)
//
//      ▂▃▅▆▇█ █ █ █ █ █ █ █ █ █ █ █ █▇▆▅▃▂

/*i pin analogici di arduino possono essere utilizzati come digitali 
dichiarandoli in questo modo: 

PIN A0 --------> 14
PIN A1 --------> 15
PIN A2 --------> 16
PIN A3 --------> 17
PIN A4 --------> 18
PIN A5 --------> 19  

*/

//collegamenti primo integrato
int clockPin = 2 ;
int latchPin = 15 ;
int dataPin = 14 ;

//collegamenti secondo integrato
int clockPin2 = 5 ;
int latchPin2 = 4 ;
int dataPin2 = 3 ;

//collegamenti terzo integrato
int clockPin3 = 8 ;
int latchPin3 = 7 ;
int dataPin3 = 6 ;

//collegamenti quarto integrato
int clockPin4 = 11 ;
int latchPin4 = 10 ;
int dataPin4 = 9 ;

int val = 0; //definisco una variabile chiamata val di tipo intero e gli assegno valore 0
int button = 12;// dico che il bottone si trova sul pin 12

// pin per comunicare con l'altro arduino
int abilitazione = 16;
int abilitazione2 = 17;



 /*subroutine per comandare i registri*/

void  setbit ( int n) {
  digitalWrite (latchPin, LOW);
  shiftOut (dataPin, clockPin, MSBFIRST, n);
  digitalWrite (latchPin, HIGH);  
}

void  setbit2 ( int n) {
  digitalWrite (latchPin2, LOW);
  shiftOut (dataPin2, clockPin2, MSBFIRST, n);
  digitalWrite (latchPin2, HIGH);  
}

void  setbit3 ( int n) {
  digitalWrite (latchPin3, LOW);
  shiftOut (dataPin3, clockPin3, MSBFIRST, n);
  digitalWrite (latchPin3, HIGH);  
}

void  setbit4 ( int n) {
  digitalWrite (latchPin4, LOW);
  shiftOut (dataPin4, clockPin4, MSBFIRST, n);
  digitalWrite (latchPin4, HIGH);  
}

/*subroutine per dire ai registri quali pin attivare*/

//uno
void  one () {
  setbit (B00000110); //accendo i segmenti del display per formare il numero 1
              //su tutti i display
}

void  one2 () {
  setbit2 (B00000110);
}

void  one3 () {
  setbit3 (B00000110);
}

void  one4 () {
  setbit4 (B00000110);
}

//faccio lo stesso procedimento per tutti gli altri numeri

//due

void two () {
  setbit (B01011011);
}

void two2 () {
  setbit2 (B01011011);
}

void two3 () {
  setbit3 (B01011011);
}

void two4 () {
  setbit4 (B01011011);
}

//tre

void three () {
  setbit (B01001111);
}

void three2 () {
  setbit2 (B01001111);
}

void three3 () {
  setbit3 (B01001111);
}

void three4 () {
  setbit4 (B01001111);
}

//quattro

void four () {
  setbit (B01100110);
}

void four2 () {
  setbit2 (B01100110);
}

void four3 () {
  setbit3 (B01100110);
}

void four4 () {
  setbit4 (B01100110);
}

//cinque

void five () {
  setbit (B01101101);
}

void five2 () {
  setbit2 (B01101101);
}

void five3 () {
  setbit3 (B01101101);
}

void five4 () {
  setbit4 (B01101101);
}

//sei

void six () {
  setbit (B01111101);
}

void six2 () {
  setbit2 (B01111101);
}

void six3 () {
  setbit3 (B01111101);
}

void six4 () {
  setbit4 (B01111101);
}

//alterno i segmenti dei display per creare un'animazione di caricamento
void carica(){
  setbit (B00000001);
  delay(50);
  setbit (B00000000);
  delay(50);
  setbit (B00000010);
  delay(50);
  setbit (B00000100);
  delay(50);
  setbit (B00000000);
  delay(50);
  setbit (B00001000);
  delay(100);
  setbit (B00000000);
  delay(50);
  setbit (B00010000);
  delay(50);
  setbit (B00000000);
  delay(50);
  setbit (B00100000);
  delay(50);
  setbit (B00000000);
  delay(50);
  setbit (B00000001);
  delay(50);
  setbit (B00000000);
  delay(50);
}

void carica2(){
  setbit2 (B00000001);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  setbit2 (B00000010);
  delay(100);
  setbit2 (B00000100);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  setbit2 (B00001000);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  setbit2 (B00010000);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  setbit2 (B00100000);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  setbit2 (B00000001);
  delay(100);
  setbit2 (B00000000);
  delay(100);
  
}

void carica3(){
  setbit3 (B00000001);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  setbit3 (B00000010);
  delay(100);
  setbit3 (B00000100);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  setbit3 (B00001000);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  setbit3 (B00010000);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  setbit3 (B00100000);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  setbit3 (B00000001);
  delay(100);
  setbit3 (B00000000);
  delay(100);
  
}

void carica4(){
  setbit4 (B00000001);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  setbit4 (B00000010);
  delay(100);
  setbit4 (B00000100);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  setbit4 (B00001000);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  setbit4 (B00010000);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  setbit4 (B00100000);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  setbit4 (B00000001);
  delay(100);
  setbit4 (B00000000);
  delay(100);
  
}

//funzione per resettare i display
void reset (){

  setbit (B00000000);
  setbit2 (B00000000);
  setbit3 (B00000000);
  setbit4 (B00000000);

}

//funzioni per selezionare i numeri in base al numero estratto
void  displaydice ( int n) {
  switch (n) {
    case  1 :
      one ();
      
      break ;  
    case  2 :
      two ();
     
      break ;  
    case  3 :
      three ();
     
      break ;  
    case  4 :
      four ();
      
      break ;  
    case  5 :
      five ();
      
      break ;  
    case  6 :
      six ();
      
      break ;  
  }  
}
void  displaydice2 ( int n2) {
  switch (n2) {
    case  1 :
      one2 ();
    
      break ;  
    case  2 :
      two2 ();
     
      break ;  
    case  3 :
      three2 ();
    
      break ;  
    case  4 :
      four2 ();
      
      break ;  
    case  5 :
      five2 ();
     
      break ;  
    case  6 :
      six2 ();
    
      break ;  
  }  
}

void  displaydice3 ( int n3) {
  switch (n3) {
    case  1 :
      one3 ();
      
      break ;  
    case  2 :
      two3 ();
    
      break ;  
    case  3 :
      three ();
    
      break ;  
    case  4 :
      four3 ();

      break ;  
    case  5 :
      five3 ();
 
      break ;  
    case  6 :
      six3 ();
 
      break ;  
  }  
}

void  displaydice4 ( int n4) {
  switch (n4) {
    case  1 :
      one4 ();
 
      break ;  
    case  2 :
      two4 ();
    
      break ;  
    case  3 :
      three4 ();
     
      break ;  
    case  4 :
      four4 ();

      break ;  
    case  5 :
      five4 ();
  
      break ;  
    case  6 :
      six4 ();
   
      break ;  
  }  
}
  
void setup()
{
  Serial.begin(9600);
  //imposto i pin dell'integrato come output
  pinMode (clockPin, OUTPUT);
  pinMode (latchPin, OUTPUT);
  pinMode (dataPin, OUTPUT);
  
  pinMode (clockPin2, OUTPUT);
  pinMode (latchPin2, OUTPUT);
  pinMode (dataPin2, OUTPUT);
  
  pinMode (clockPin3, OUTPUT);
  pinMode (latchPin3, OUTPUT);
  pinMode (dataPin3, OUTPUT);
  
  pinMode (clockPin4, OUTPUT);
  pinMode (latchPin4, OUTPUT);
  pinMode (dataPin4, OUTPUT);
  
  randomSeed ( analogRead (A0));//funzione che definisce da dove viene prelevato il seme per il generatore di numeri casuali in questo caso verrà dal pin analogico che deve essere lasciato flottante
  randomSeed ( analogRead (A1));
  randomSeed ( analogRead (A2));
  randomSeed ( analogRead (A3));
  //dato che i pin sono mobili il valore che genererà il generatore di numeri casuali non sarà mai lo stesso rendendolo così casuale
}

void loop()
{
 val = digitalRead(button);//controllo lo stato del pulsante e lo assegno a una variabile

  if(val == 1){
    
    reset();//resetto i display
    carica();//eseguo due cicli di caricaa sul primo display
    carica();
   int n = random ( 1 , 7 ); //genero un numero da 1 a 7 escluso
   displaydice (n);//eseguo la subroutine per mostrare il numero
   delay ( 10 );//aspetto 10 millisecondi
    carica2();//eseguo lo stesso procedimento per gli altri display
    carica2();
   int n2 = random ( 1 , 7 );  
   displaydice2 (n2); 
   delay ( 10 ); 
    carica3();
    carica3();
   int n3 = random ( 1 , 7 );  
   displaydice3 (n3); 
   delay ( 10 ); 
    carica4();
    carica4();
   int n4 = random ( 1 , 7 );  
   displaydice4 (n4); 
   delay ( 10 ); 
  

//per provare che effettivamente si può vincere commentare la parte sopra e lasciare questa
//int n = 1;
//int n2 = 1;
//int n3 = 1;
//int n4 = 1;
   

    if(n == n2 == n3 == n4){//se i quattro numeri riportati sui display sono uguali
      
      Serial.write("jackpot");//scrivo "jackpot" sulla porta seriale
        digitalWrite(17,HIGH);//imposto il pin abilitazione 2 su valore logico alto
        digitalWrite(16,HIGH);//imposto il pin abilitazione su valore logico alto
    
    }else{//altrimenti
    
      Serial.write("ritenta");//scrivo sulla porta seriale "ritenta"
        digitalWrite(abilitazione,LOW);//imposto il pin abilitazione su livello logico basso
      
    } 
  }
}
