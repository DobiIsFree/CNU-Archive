def Encoding(src, n=8, scale_factor=1):
    block = img2block(src, n=n)
    block -= 128
    b = np.double(src[150:158, 89:97]) - 128

def img2block(src, n=8):
    # TODO
    (h,w) = src.shape

    if h % n != 0:
        h_pad = n-h%n
    else:
        h_pad = 0

    if w % n != 0:
        w_pad = n-w%n
    else:
        w_pad = 0

    dst = np.zeros((h+h_pad, w+w_pad))
    dst[:h, :w] = src

    blocks = []
    for row in range((h+h_pad)//n):
        for col in range(w+w_pad)//n:
            block = dst[row*n:(row+1)*n, col*n:(col+1)*n]
            block.append(block)

    return np.array(blocks)

# DCT
blocks_dct = []
for block in blocks:
    blocks_dct.append(DCT(blcok, n=n))
blocks_dct = np.array(blocks_dct)

# Quantization + thresholding
Q = Quntization_Luminace(scale_factor)
QnT = np.round(blocks_dct / Q)
bq = np.round(bd / Q)

# Zigzag scanning
while True:
    if encoding:
        zigzag.append(block[row, col])

        if half:
            if change:
                row += val
                col -= val
                if row == half_count or col == half_count:
                    val == -1
                    change = False
            else :
                half_count += 1
                if row== block_size -1 :
                    col += 1
                    change = True
                elif col == block_size-1:
                    row += 1
                    change = True
        else: # half == False
            if change:
                row += val
                col -= val
                if row == 0 or col == 0:
                    val *= -1
                    change = False
                if row == blocks_size - 1 or col == block_size -1:
                    half = True
            else :
                if row == 0:
                    col += 1
                    change = True
                elif col == 0:
                    row += 1
                    change = True

    length = len(zigzag)
    if encoding:
        # 뒤쪽 0 제거
        for idx in range(length):
            if zigzag[length - idx - 1] != 0:
                break
            else :
                zigzag.pop()
        zigzag.append('EOB')
        return zigzag


#zigzag decoding
block_recover = np.zeros((block_size, block_size))
if idx >= len(block) or block[idx] == 'EOB':
    break
block_recover[row, col] = block[idx]
idx += 1

def DCT_inv(block, n=8):
    # TODO
    y, x = block.shape
    v, u = np,mgrid[0:y, 0:x]
    dst = np.zeros(block.shape)
    for x_ in range(x):
        for y_ in range(y):
            tmp = C_matrix(u, n=n) \
                    * C_matrix(v, n=n) \
                    * blcok \
                    * np.cos(((2 * x_ + 1) * u * np.pi) / (2 * n)) \
                    * np.cos(((2 * y_ + 1) * v * np.pi) / (2 * n))
            dst[y_, x_] = np.sup(tmp)

    return np.round(dst)

# inverse DCT
blocks_idct = []
for block in blocks:
    block_idct.append(DCT_inv(blcok, n=b))
blocks_idct = np.array(blocks_idct)
bd2 = DCT_inv(bq2, n=8)

def block2img(blocks, src_shape, n=8):
    # TODO
    (h, w) = src_shape

    if h % n != 0:
        h_pad = n-h%n
    else:
        h_pad = 0

    if w % n != 0:
        w_pad = n-w%n
    else:
        w_pad = 0

    idx = 0
    for row in range(src_shape[0]//n):
        for col in range(src_shape[1]//n):
            dst[row*n:(row+1)*n, col*n:(col+1)*n] = np.clip(blocks[idx], 0, 255)
            idx += 1

    dst = dst[:src_shape[0], :src_shape[1]]
    return dst