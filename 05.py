def my_bilinear(src, scale):
    (h,w) = src.shape
    h_dst = int(h*scale + 0.5)
    w_dst = int(w*scale + 0.5)
    print(src.shape)
    dst = np.zeros((h_dst, w_dst), np.uint8)

    for row in range(h_dst):
        for col in range(w_dst):
            center_r = row / scale
            center_c = col / scale

            t = center_r - int(center_r)
            s = center_c - int(center_c)

            r1 = int(center_r)
            r2 = min(int(center_r + 1), h-1)
            c1 = int(center_c)
            c2 = min(int(center_c + 1), w-1)

            value = 0
            value += (1-s) * (1-t) * src[r1, c1]
            value += s * (1-t) * src[r1, c2]
            value += (1-s) * t * src[r2, c1]
            value += s * t * src[r2, c2]

            value = np.round(value)
            dst[row, col] - value

    return dst

