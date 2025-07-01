with open("pentaracts.txt", "w") as f:
    seen = []
    for a in range(0, 200):
      for b in range(0, 200):
        x = a**5 + b**5
        if(x not in seen and x<=10**9):
          seen.append(x)
          f.write(f"ans[{x}] = {{{a},{-b}}};\n")
        x = a**5 - b**5

        if x > 0 and x not in seen and x<=10**9:
          seen.append(x)
          f.write(f"ans[{x}] = {{{a},{b}}};\n")
        
      
      