from Adafruit_IO import Client
import time
 
i = 0
my_file = open("test5.txt","r")
aio = Client("ManChh0712","aio_zick56JLeAHBgOWgJqf0YbNVB1Iq")

for new_line in my_file:
    str1 = new_line.replace("\n","").split(",")
    if (i==8): 
        if (len(str1)==2):
            time.sleep(2)
            one = str1[0]
            two = str1[1]
            test = aio.feeds('wifitest')
            test2 = aio.feeds('ydegree')
            aio.send_data(test.key, one)
            aio.send_data(test2.key, two)
        
        i = 0;
    i += 1


