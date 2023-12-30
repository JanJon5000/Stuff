void main(){
  //flexible list - it can grow and become smaller as well
  var myList = [1, 2, 3.9, 'asdasda'];
  print(myList);
  print(myList[1]);
  myList[2] = 'changed value';
  print(myList);
  //tuple or something - idk
  var otherList = (1, 2, 3);
  print(otherList);
  // otherList[1] = 4 is not possible
  
  //emptyList
  var emptyList = [];
  print(emptyList);
  emptyList.add('45454');
  print(emptyList);
  emptyList.insertAll(emptyList.length, myList);
  // OR emptyList.addAll()
  print(emptyList);
  //not so empty after all!

  var basiclyAPythonDictionary = {'A':1, 'B':2};
  print(basiclyAPythonDictionary['A']);
  print(basiclyAPythonDictionary.length);
  print(basiclyAPythonDictionary);
  basiclyAPythonDictionary.addAll({'C':7, 'D':19});
  print(basiclyAPythonDictionary);
  print(basiclyAPythonDictionary.keys);
  print(basiclyAPythonDictionary.values);
  basiclyAPythonDictionary.remove('C');
  print(basiclyAPythonDictionary);
}