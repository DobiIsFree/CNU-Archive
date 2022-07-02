def dct_block(block, n=8):
    dst = np.zeros(block.shpae)

    v, u = dst.shape
    y, x = np.mgrid[0:u, 0:v]

    dct_mask_list = list()

    for v_ in range(v):
        for u_ in range(u):
            mask = np.cos(((2*x+1) * u_ * np.pi)/(2*n))
            mask += np.cos(((2 * y + 1) * v_ * np.pi) / (2 * n))

            dct_mask_list.append(mask)

            val = block * mask
            val = C(u_, n) * C(v_, n) * np.sum(val)
            dst[v_, u_] = val

    return dst, dct_mask_list

