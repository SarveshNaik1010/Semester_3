# ------------------------------ File Operations ------------------------------ #

# 1. Read File
try: 
    fileContent = open('./Python/content.txt', "r");

    # 1. Num of lines
    fileContent = open('./Python/content.txt', "r");
    numLines = len(fileContent.readlines());
    print("Num of lines = ", numLines);

    # 2. No of Words
    fileContent = open('./Python/content.txt', "r");
    numWords = len(fileContent.read().split(" "));
    print("Num of words = ", numWords);

    # 3. No of Characters
    fileContent = open('./Python/content.txt', "r");
    numChars = len(fileContent.read());
    print("Num of Chars = ", numChars);

except FileNotFoundError as err:
    print("ERROR, UNABLE TO OPEN FILE!");

# 2. Write to a file
try: 
    fromFile = open('./Python/content.txt', "r");
    toFile = open("./Python/receiveContent.txt", 'a');
    toFile.write(fromFile.read());
    print("Content added to another file successfully");
except FileNotFoundError as err: 
    print("ERROR, UNABLE TO PERFORM FILE OPERATION!");