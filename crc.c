def bin_xor(result,a,b):
    for i in range(16):
        result[i] = '0' if a[i] == b[i] else '1'
    result[15] ='\0'

def cal(data,crc_poly):
    crc = '0' * 16
    for byte in data:
        for _ in range(8):
            msb = crc[0]
            crc = crc[1:] + '0'
            if msb == '1':
                temp = ['0'] *16
                bin_xor(temp,crc,crc_poly)
                crc = ''.join(temp)
        crc = crc[:15] + ('1' if byte=='1' else '0')
    return crc

def main():
    data = input("enter the data in binary")
    crc_poly = bin(int('0X11021',16))[2:]
    print(crc_poly)
    check_sum = cal(data,crc_poly)
    print(check_sum)
    code = data+check_sum
    print(code)
    rec = input("enter the checksum u got")
    if code== rec:
        print("sahi hai")
    else:
        print("galat hai")


main()
