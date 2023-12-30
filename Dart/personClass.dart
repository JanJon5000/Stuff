class Person{
  String? name, sex;
  int? age;
  bool? hasAPartner;


  //Constructor
  Person(String name, sex, int age, hasAPartner){
    this.age = age;
    this.name = name;
    this.sex = sex;
    this.hasAPartner = hasAPartner;
  }

  void show_data(){
    print("This is $name, a $age year old $sex");
  }
}

void main(){
  Person me;
  me = Person('Jan', 'male', 18, true);

  me.show_data();
}