
void main(){
  //some generic variables (boring)
  var FirstName = 'Jan';
  var age = 18;
  String word = 'word';
  dynamic number = 4.99;

  //fun with the print function
  print("I am " + FirstName + " and I am " + age.toString() + " years old");
  print(number);
  number = 4;
  print(number);
  number = 'some text';
  print(number);
  print("Number I declared: $age, strings: $word, $FirstName and dynamics!: $number");
  //const and final
  /*
  asdasdasd
  */

  const x = 0;
  final y;

  //final can be declared later (only once) , const cant
  y = 6;


}