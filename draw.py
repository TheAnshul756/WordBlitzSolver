import pyautogui

G = 4

# pyautogui.moveTo(813, 455)
# pyautogui.mouseDown()
# pyautogui.moveTo(1293, 759)
# pyautogui.moveTo(813, 759)
# pyautogui.moveTo(813, 455)
# pyautogui.mouseUp()


# end points of grid 
x1 = 748
y1 = 458
x2 = x1+420
y2 = y1+420

X = [0,0,0,0]
Y = [0,0,0,0]

X[3] = (x1+7*x2)//8
X[2] = (3*x1+5*x2)//8
X[1] = (5*x1+3*x2)//8
X[0] = (7*x1+x2)//8

Y[3] = (y1+7*y2)//8
Y[2] = (3*y1+5*y2)//8
Y[1] = (5*y1+3*y2)//8
Y[0] = (7*y1+y2)//8

f=open("output.txt", "r")
content = f.read()
flag = 0
stack = []
for i in content:
	if i=='G':
		pyautogui.mouseUp()
		flag=0
		# print()
		continue
	if i=='B':
		pyautogui.moveTo(X[int(stack[1])], Y[int(stack[0])])
		# print(stack[1],stack[0])
		stack.clear()
		if flag==0:
			pyautogui.mouseDown()
			flag=1
		continue
	stack.append(i)
