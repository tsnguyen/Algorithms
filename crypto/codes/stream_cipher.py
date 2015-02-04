# some useful functions
# ord('a') = 97
# unichr(97) = 'a'
# int('0x61', 16) = 97 
# hex(97) = '0x61'
# string.ascii_lowercase
# "".encode('hex')
# "".decode('hex')
import sys

MSGS = {'hello', 'is it me', 'you are looking for'}

def strxor(a, b):     # xor two strings of different lengths
    if len(a) > len(b):
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a[:len(b)], b)])
    else:
        return "".join([chr(ord(x) ^ ord(y)) for (x, y) in zip(a, b[:len(a)])])

def random(size=16):
    return open("/dev/urandom").read(size)

def encrypt(key, msg):
    c = strxor(key, msg)
    print
    print c.encode('hex')
    return c

def main():
    key = random(1024)
    ciphertexts = [encrypt(key, msg) for msg in MSGS]

