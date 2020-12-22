import base64

path = "..\\Release\\ConsoleApplication.exe"

binary = open(path, 'rb').read()

open("encoded.b64", 'w').write(base64.b64encode(binary).decode('ascii'))