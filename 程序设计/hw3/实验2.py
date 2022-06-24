a, b, c = map(float, input().split())

if (a+b>c) & (a+c>b) & (b+c>a):
    temp = float((a+b+c)/2)
    s = float((temp*(temp-a)*(temp-b)*(temp-c))**0.5)
    print("{:.2f}".format(s))
else:
    print("{:.2f}".format(0.00))