while(True) :
    dic = ("a", "e", "i", "o", "u", "A", "E", "I", "O", "U")
    result = 0
    c1 = input()
    if(c1 == "#") :
        break

    for i in c1 :
        if i in dic :
            result += 1

    print(result)