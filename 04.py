def my_filtering(src, mask, pad_type='zero'):
    (h,w) = src.shape
    src_pad = my_padding(src, (mask.shape[0]//2, mask.shape[1]//2, pad_type))
    dst = np.zeros((h,w))

    # TODO
    for row in range(h):
        for col in range(w):
            val = np.sum(src_pad[row:row+mask.shape[0], col:col+mask.shape[1]] * mask)
            val = np.clip(val, 0, 255)
            dst[row, col] = val

    dst = (dst+0.5).astype(np.uint8)

    return dst

def get_average_mask(fshape):
    # TODO
    mask = np.ones(fshape)
    mask = mask / (fshape[0] * fshape[1])

    print(mask)
    return mask

def get_sharpening_mask(fshape):
    # TODO
    base_mask = np.zeros(fshape)
    base_mask[fshape[0] // 2, fshape[1] // 2] = 2
    aver_mask = np.ones(fshape)
    mask = base_mask - aver_mask

    print(mask)
    return mask

def my_get_Gaussian2D_mask(msize, sigma=1):
    # TODO
    y, x = np.mgrid[-(msize//2):(msize//2)+1, -(msize//2):(msize//2)+1]

    # 2차 gaussian mask 생성
    gaus2D = 1/(2*np.pi * sigma**2) * np.exp(-((x**2 + y**2)/(2*sigma**2)))
    # mask 총 합 = 1
    gaus2D /= np.sum(gaus2D)

    return gaus2D

def my_get_Gaussian1D_mask(msize, sigma=1):
    # TODO
    x = np.full((1,msize), [range(-msize//2), (msize//2)+1])

    gaus1D = 1 / (np.sqrt(2*np.pi) * sigma) * np.exp(-((x*x) / (2*sigma*sigma)))
    # mask 총 합 = 1
    gaus1D /= np.sum(gaus1D)

    return gaus1D

