import pyautogui
import time

#I had created around 50 files, d0.txt, ... d49.txt. This auto submits all.
#Started from 16 in this case, as had done previous 15 in a previous run of the program.

#If want to submit for lower ones: keyDown. (google it...)
for i in range(16, 50):
    time.sleep(5)
    pyautogui.click(1452, 357)
    time.sleep(2)
    pyautogui.click(1263, 420)
    time.sleep(1)
    pyautogui.typewrite('d.txt')
    pyautogui.press('enter')
    time.sleep(5)
    pyautogui.click(1322, 821)
    time.sleep(1)
    pyautogui.typewrite('d'+str(i)+'.txt')
    pyautogui.press('enter')
    time.sleep(10)
    pyautogui.click(1405, 897)
