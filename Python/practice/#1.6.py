"""
def p_plus (a, b):
    print(a + b)

def r_plus (a, b):
    return a + b

p_result = p_plus(2, 3)
r_result = r_plus(2, 3)

print (p_result, r_result)
"""
def r_plus (a, b):
    return a + b
    print ("this line may be not run")
    #return은 값을 반환함과 동시에 함수를 종료 시킨다.

r_result = r_plus(2, 3)

print (r_result)
