def my_bilateral(src, msize, sigma, sigma_r, pos_x, pos_y, pad_type='zero'):
    # TODO
    (h, w) = src.shape
    m_s = msize // 2
    img_pad = my_padding(src, pad_shape=(m_s, m_s), pad_type=pad_type)
    dst = np.zeros((h,w))

    y,x = np.mgrid[-m_s:m_s+1, -m_s:m_s+1]

    for i in range(h):
        for j in range(w):
            k = y+i
            l = x+j
            mask = np.exp( -(((i-k)**2) / (2 * sigma**2)) -(((j-l)**2) / (2 * sigma**2)) )\
                           * np.exp( -(((img_pad[i+m_s, j+m_s] - img_pad[k+m_s, l+m_s])**2)/(2*sigma_r**2)) )

            mask = mask/mask.sum()

            dst[i, j] = np.sum(img_pad[i:i+msize, j:j+msize] * mask)

    return dst

