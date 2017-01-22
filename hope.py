import os

os.system("./nfa2")
os.system("dot -Tpng fsm.gv -o my.pdf")
os.system("display my.pdf")
