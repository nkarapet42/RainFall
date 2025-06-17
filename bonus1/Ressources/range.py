for x in range(-2147483648, 9):
    byte = (x * 4) % (2 ** 32)
    if x < 10 and byte >= 44 and byte <= 224:
        print("x = {}, byte = {}".format(x, byte))
