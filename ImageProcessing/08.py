def dilation(B,S):
    (b_h, b_w) = B.shape
    (s_h, s_w) = S.shape
    pad_size_h = s_h // 2
    pad_size_w = s_w // 2

    dst = my_padding(B, (pad_size_h, pad_size_w), pad_type='zero')

    for row in range(b_h):
        for col in range(b_w):
            if B[row, col] == 1:
                dst[row:row+s_h, col:col+s_w] = S
    dst = dst[pad_size_h:b_h + pad_size_h, pad_size_w:b_w + pad_size_w]
    return  dst

 def erosion(B, S):
    (b_h, b_w) = B.shape
    (s_h, s_w) = S.shape
    pad_size_h = s_h // 2
    pad_size_w = s_w // 2

    dst = np.zeros(B.shape)

    for row in range(pad_size_h, b_h - pad_size_h):
        for col in range(pad_size_w, b_w - pad_size_w):
            if np.arrapy_equal(B[row-pad_size_h:row+pad_size_h+1, col-pad_size_w:col+pad_size_w+1], S):
                dst[row, col] = 1

    return dst

 def opening(B, S):
     dst = dilation((erosion(B, S)), S)
     return dst

 def closing(B,S):
     dst = erosion(dilation(B, S), S)
     return dst

