days = ["Mon", "Tue", "Wed","Thur","Fri"]

print("mon" in days) 
#mon이 days라는 변수에 있는지 확인한다. 있으면 true값 반환 없으면 false반환 
print(days[3])
print(len(days))
#
days.append("Sat")
#"Sat"을 추가 한다
days.reverse()
#목록을 뒤집는다
print(days)