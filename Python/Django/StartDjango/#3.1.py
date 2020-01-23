"""
def plus(a,b, *args, **kwargs):
    print (args)
    print (kwargs)
    return a + b

plus(1,2,1,1,1,1,A = True, B = True, c = True, d = True)
"""

def plus (*args):
    result = 0
    for number in args:
        result += number
    print(result)
    
plus(1,2,3,4,5,6,7,8,9)