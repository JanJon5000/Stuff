void main(){
  //quick little fibonachi sequence
  int a = 1;
  int b = 1;
  print(a);
  print(b);
  for (var i = 1; i < 10; i++){
    print(a + b);
    if (i % 2 == 0){
      a = a + b;
    }else{
      b = a + b;
    }
  }

  // an empty line beetween two fors
  print('');

  // for in loop
  var names = ['Ann', 'Steve', 'Baller'];
  for (dynamic a in names){
    print(a);
  }

  var iterator = 0;
  var AnnList = ['A', 'n', 'n'];
  var n = '';
  while (n != names[0]){
    print(n);
    n = n + AnnList[iterator];
    iterator++;
  }

}