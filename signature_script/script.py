import os

path =  os.path.dirname(os.path.realpath(__file__)) + "/test/"

signature = "/*\n"
signature += "************************************************\n"
signature += "username    :   smmehrab\n"
signature += "fullname    :   s.m.mehrabul islam\n"
signature += "email       :   mehrab.24csedu.001@gmail.com\n"
signature += "institute   :   university of dhaka, bangladesh\n"
signature += "session     :   2017-2018\n"
signature += "************************************************\n"
signature += "*/\n"

for (root, directories, files) in os.walk(path):
    for filename in files:
        if filename.endswith(".cpp") or filename.endswith(".c") :
            filePath = os.path.join(root, filename)
            print(filePath)
            with open(filePath, 'r', encoding = "ISO-8859-1") as file:
                content = file.read()
            content = signature + content
            with open(filePath, 'w', encoding = "ISO-8859-1") as file:
                file.write(content)