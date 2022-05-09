import os
os.system('st g++ main.cpp')
#os.system('st')
if os.path.exists("keypress100.py"):
  reset_count = open('counter.txt', 'w')
  reset_count.write('0')
  reset_count.close()
  for i in range(1, 100):
    os.remove(f'keypress{i}.py')
    os.remove(f'saved_input{i}.txt')
os.system('st ./a.out')

