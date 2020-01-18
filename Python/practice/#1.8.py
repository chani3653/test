def say_hello(name, age):
    return f"hello {name} you are {age} years old"
    #""앞의 f는 format을 의미하고 ""안에 {}를 넣고 그안에 변수를 넣으면 변수의 내용이 들어 간다.

hello = say_hello("nico", "12")
print(hello)