ciphertext = '''\
g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp.
bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle.
sqgle qrpgle.kyicrpylq() gq pcamkkclbcb.
lmu ynnjw ml rfc spj.'''

decrypt = lambda c: chr((((ord(c) - 97) + 2 ) % 26) + 97)
plaintext = map(lambda c: ord(c) >= 97 and decrypt(c) or c, ciphertext)
print(*list(plaintext), sep = '')
