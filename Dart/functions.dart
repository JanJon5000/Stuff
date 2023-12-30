import 'dart:io';

binary(int number){
    String binaryNumber = '';
    while (number > 0){
      binaryNumber += (number % 2).toInt().toString();
      number = (number/2).toInt();
    }
    var answer = '';
    for (dynamic ch in binaryNumber.split('').reversed){
      answer += ch;
    }

    return answer;
  }
void main(){
  var num = stdin.readLineSync();
  var n = int.parse(num ?? '0');
  print(binary(n));
}

