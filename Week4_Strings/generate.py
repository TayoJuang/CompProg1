with open("zero.input", 'w') as f:
    #generate 500000 zero
    line = "0 " * 500000 + "\n"
    line2 = "1 " * 500000 + "\n"
    f.write("500000 ")
    f.write("500000\n")
    f.write(line)
    f.write(line2)