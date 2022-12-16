def my_otsu_threshod(img):
    hist, bins = np.histogram(img.ravel(), 256, [0,256])

    p = his / np.sum(hist) + 1e-7

    q1 = np.zeros(256).astype('float64')
    q2 = np.zeros(256).astype('float64')
    m1 = np.zeros(256).astype('float64')
    m2 = np.zeros(256).astype('float64')

    q1[0] = p[0]
    m1[0] = 0
    q2[0] = 0
    m2[0] = (np.sum(p * np.arrange(0, 256)) - (q1[0] * m1[0])) / q2[0]

    for k in range(0, 255):
        q1[k+1] = q1[k] + p[k+1]
        q2[k+1] = 1-q1[k+1]
        m1[k+1] = (q1[k]*m1[k] + (k+1)*p[k+1]) / q1[k+1]
        m2[k + 1] = (q2[k] * m2[k] - (k + 1) * p[k + 1]) / q2[k + 1]

    th = np.argmax(q1 * q2 * (m1-m2) ** 2)
    dst = apply_threshold(img, th)

    return th, dst
