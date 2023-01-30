#!/usr/bin/env python3

import argparse
from subprocess import run, PIPE
import os

RED = '\033[91m'
BLUE = '\033[94m'
GREEN = '\033[92m'
END = '\033[0m'

def add(input_txt, correct_txt):
  n=1
  while(os.path.exists("test/x-sample-{}.in".format(n))):
    n+=1
  with open("test/x-sample-{}.in".format(n), mode='w') as f:
    f.write(input_txt)
  with open("test/x-sample-{}.out".format(n), mode='w') as f:
    f.write(correct_txt)
  print(GREEN + "ADD x-sample-{}".format(n) + END)

if __name__== "__main__":
  parser = argparse.ArgumentParser()
  parser.add_argument("--number", '-n', type=int, default='100000', metavar='100', help='試行回数')
  parser.add_argument("--diff", "-d", type=float, metavar='0.1', help="絶対誤差")

  opts = parser.parse_args()

  for i in range(opts.number):
    input_result = run(["./make_random.out"], stdout=PIPE, text=True)
    if input_result.returncode != 0:
      print(RED + "input を作るのに失敗" + END)
      exit()
    input_txt = input_result.stdout

    tle_result = run("./tle.out", input=input_txt, stdout=PIPE, text=True)
    if tle_result.returncode != 0:
      print(BLUE + "INPUT:" + END)
      print(input_txt)
      print(RED + "愚直解が RE" +END)
      exit()
    correct_txt = tle_result.stdout

    solve_result = run("./a.out", input=input_txt, stdout=PIPE, text=True)
    if solve_result.returncode != 0:
      print(BLUE + "INPUT:" + END)
      print(input_txt)
      print(BLUE + "CORRECT:" +END)
      print(correct_txt)
      print(RED + "YOUR CODE is RE" + END)
      add(input_txt,correct_txt)
      exit()
    output_txt = solve_result.stdout

    if (opts.diff and abs(correct_txt-output_txt)>diff) or (not opts.diff and correct_txt != output_txt):
      print(BLUE + "INPUT:" + END)
      print(input_txt)
      print(BLUE + "CORRECT:" +END)
      print(correct_txt)
      print(BLUE + "WRONG" + END)
      print(output_txt)
      add(input_txt,correct_txt)
      exit()
    
    if (i&(i+1)) == 0:
      print(GREEN + "{}回の探索".format(i+1) + END)
  print(GREEN + "{}回の探索".format(opts.number) + END)