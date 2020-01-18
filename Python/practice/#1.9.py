def plus (a, b):
    return float(a) + float(b)

def minus (a, b):
    return float(a) - float(b)

def multi (a, b):
    return float(a) * float(b)

def div (a, b):
    return float(a) / float(b)

def remainder (a, b):
    return float(a) % float(b)

def negation (a):
    return -float(a)

def power (a, b):
    return pow(float(a), float(b))

print(f"plus(3,4) :  {plus(3,4)}")
print(f"minus(3,4) : {minus(3,4)}")
print(f"multify(3,4) : {multi(3,4)}")
print(f"remainder(3,4) : {remainder(3,4)}")
print(f"div(3,4) : {div(3,4)}")
print(f"negation(3) : {negation(3)}")
print(f"power(3,4) : {power(3,4)}")
